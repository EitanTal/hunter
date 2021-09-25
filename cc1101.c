#include "cc1101.h"
#include "Arduino.h"
#include "spi.h"

enum
{
  PA_POWER_MINUS_0 = 0x51,
  PA_POWER_MINUS_15 = 0x1D,
  PA_POWER_MINUS_30 = 0x03,
  PA_POWER_ORIGINAL = 0xC0,
};

/**
 * Frequency channels
 */
#define NUMBER_OF_FCHANNELS      10

/**
 * Type of transfers
 */
#define WRITE_BURST              0x40
#define READ_SINGLE              0x80
#define READ_BURST               0xC0

/**
 * Type of register
 */
#define CC1101_CONFIG_REGISTER   READ_SINGLE
#define CC1101_STATUS_REGISTER   READ_BURST

/**
 * PATABLE & FIFO's
 */
#define CC1101_PATABLE           0x3E        // PATABLE address
#define CC1101_TXFIFO            0x3F        // TX FIFO address
#define CC1101_RXFIFO            0x3F        // RX FIFO address

/**
 * Command strobes
 */
#define CC1101_SRES              0x30        // Reset CC1101 chip
#define CC1101_SFSTXON           0x31        // Enable and calibrate frequency synthesizer (if MCSM0.FS_AUTOCAL=1). If in RX (with CCA):
                                             // Go to a wait state where only the synthesizer is running (for quick RX / TX turnaround).
#define CC1101_SXOFF             0x32        // Turn off crystal oscillator
#define CC1101_SCAL              0x33        // Calibrate frequency synthesizer and turn it off. SCAL can be strobed from IDLE mode without
                                             // setting manual calibration mode (MCSM0.FS_AUTOCAL=0)
#define CC1101_SRX               0x34        // Enable RX. Perform calibration first if coming from IDLE and MCSM0.FS_AUTOCAL=1
#define CC1101_STX               0x35        // In IDLE state: Enable TX. Perform calibration first if MCSM0.FS_AUTOCAL=1.
                                             // If in RX state and CCA is enabled: Only go to TX if channel is clear
#define CC1101_SIDLE             0x36        // Exit RX / TX, turn off frequency synthesizer and exit Wake-On-Radio mode if applicable
#define CC1101_SWOR              0x38        // Start automatic RX polling sequence (Wake-on-Radio) as described in Section 19.5 if
                                             // WORCTRL.RC_PD=0
#define CC1101_SPWD              0x39        // Enter power down mode when CSn goes high
#define CC1101_SFRX              0x3A        // Flush the RX FIFO buffer. Only issue SFRX in IDLE or RXFIFO_OVERFLOW states
#define CC1101_SFTX              0x3B        // Flush the TX FIFO buffer. Only issue SFTX in IDLE or TXFIFO_UNDERFLOW states
#define CC1101_SWORRST           0x3C        // Reset real time clock to Event1 value
#define CC1101_SNOP              0x3D        // No operation. May be used to get access to the chip status byte

/**
 * CC1101 configuration registers
 */
#define CC1101_IOCFG2            0x00        // GDO2 Output Pin Configuration
#define CC1101_IOCFG1            0x01        // GDO1 Output Pin Configuration
#define CC1101_IOCFG0            0x02        // GDO0 Output Pin Configuration
#define CC1101_FIFOTHR           0x03        // RX FIFO and TX FIFO Thresholds
#define CC1101_SYNC1             0x04        // Sync Word, High Byte
#define CC1101_SYNC0             0x05        // Sync Word, Low Byte
#define CC1101_PKTLEN            0x06        // Packet Length
#define CC1101_PKTCTRL1          0x07        // Packet Automation Control
#define CC1101_PKTCTRL0          0x08        // Packet Automation Control
#define CC1101_ADDR              0x09        // Device Address
#define CC1101_CHANNR            0x0A        // Channel Number
#define CC1101_FSCTRL1           0x0B        // Frequency Synthesizer Control
#define CC1101_FSCTRL0           0x0C        // Frequency Synthesizer Control
#define CC1101_FREQ2             0x0D        // Frequency Control Word, High Byte
#define CC1101_FREQ1             0x0E        // Frequency Control Word, Middle Byte
#define CC1101_FREQ0             0x0F        // Frequency Control Word, Low Byte
#define CC1101_MDMCFG4           0x10        // Modem Configuration
#define CC1101_MDMCFG3           0x11        // Modem Configuration
#define CC1101_MDMCFG2           0x12        // Modem Configuration
#define CC1101_MDMCFG1           0x13        // Modem Configuration
#define CC1101_MDMCFG0           0x14        // Modem Configuration
#define CC1101_DEVIATN           0x15        // Modem Deviation Setting
#define CC1101_MCSM2             0x16        // Main Radio Control State Machine Configuration
#define CC1101_MCSM1             0x17        // Main Radio Control State Machine Configuration
#define CC1101_MCSM0             0x18        // Main Radio Control State Machine Configuration
#define CC1101_FOCCFG            0x19        // Frequency Offset Compensation Configuration
#define CC1101_BSCFG             0x1A        // Bit Synchronization Configuration
#define CC1101_AGCCTRL2          0x1B        // AGC Control
#define CC1101_AGCCTRL1          0x1C        // AGC Control
#define CC1101_AGCCTRL0          0x1D        // AGC Control
#define CC1101_WOREVT1           0x1E        // High Byte Event0 Timeout
#define CC1101_WOREVT0           0x1F        // Low Byte Event0 Timeout
#define CC1101_WORCTRL           0x20        // Wake On Radio Control
#define CC1101_FREND1            0x21        // Front End RX Configuration
#define CC1101_FREND0            0x22        // Front End TX Configuration
#define CC1101_FSCAL3            0x23        // Frequency Synthesizer Calibration
#define CC1101_FSCAL2            0x24        // Frequency Synthesizer Calibration
#define CC1101_FSCAL1            0x25        // Frequency Synthesizer Calibration
#define CC1101_FSCAL0            0x26        // Frequency Synthesizer Calibration
#define CC1101_RCCTRL1           0x27        // RC Oscillator Configuration
#define CC1101_RCCTRL0           0x28        // RC Oscillator Configuration
#define CC1101_FSTEST            0x29        // Frequency Synthesizer Calibration Control
#define CC1101_PTEST             0x2A        // Production Test
#define CC1101_AGCTEST           0x2B        // AGC Test
#define CC1101_TEST2             0x2C        // Various Test Settings
#define CC1101_TEST1             0x2D        // Various Test Settings
#define CC1101_TEST0             0x2E        // Various Test Settings

/**
 * Status registers
 */
#define CC1101_PARTNUM           0x30        // Chip ID
#define CC1101_VERSION           0x31        // Chip ID
#define CC1101_FREQEST           0x32        // Frequency Offset Estimate from Demodulator
#define CC1101_LQI               0x33        // Demodulator Estimate for Link Quality
#define CC1101_RSSI              0x34        // Received Signal Strength Indication
#define CC1101_MARCSTATE         0x35        // Main Radio Control State Machine State
#define CC1101_WORTIME1          0x36        // High Byte of WOR Time
#define CC1101_WORTIME0          0x37        // Low Byte of WOR Time
#define CC1101_PKTSTATUS         0x38        // Current GDOx Status and Packet Status
#define CC1101_VCO_VC_DAC        0x39        // Current Setting from PLL Calibration Module
#define CC1101_TXBYTES           0x3A        // Underflow and Number of Bytes
#define CC1101_RXBYTES           0x3B        // Overflow and Number of Bytes
#define CC1101_RCCTRL1_STATUS    0x3C        // Last RC Oscillator Calibration Result
#define CC1101_RCCTRL0_STATUS    0x3D        // Last RC Oscillator Calibration Result 

//#define CC1101_DEFVAL_IOCFG2     0x29        // GDO2 Output Pin Configuration
#define CC1101_DEFVAL_IOCFG2     0x2E        // GDO2 Output Pin Configuration
#define CC1101_DEFVAL_IOCFG1     0x2E        // GDO1 Output Pin Configuration
#define CC1101_DEFVAL_IOCFG0     0x06        // GDO0 Output Pin Configuration
#define CC1101_DEFVAL_FIFOTHR    0x47        // RX FIFO and TX FIFO Thresholds
#define CC1101_DEFVAL_SYNC1      0xD3        // Synchronization word, high byte
#define CC1101_DEFVAL_SYNC0      0x91        // Synchronization word, low byte
#define CC1101_DEFVAL_PKTLEN     0x12        // Packet Length
#define CC1101_DEFVAL_PKTCTRL1   0x04        // Packet Automation Control
#define CC1101_DEFVAL_PKTCTRL0   0x00        // Packet Automation Control
#define CC1101_DEFVAL_ADDR       0x11        // Device Address
#define CC1101_DEFVAL_CHANNR     0x00        // Channel Number
#define CC1101_DEFVAL_FSCTRL1    0x06        // Frequency Synthesizer Control
#define CC1101_DEFVAL_FSCTRL0    0x00        // Frequency Synthesizer Control
// Carrier frequency = 868 MHz
#define CC1101_DEFVAL_FREQ2_868  0x21        // Frequency Control Word, High Byte
#define CC1101_DEFVAL_FREQ1_868  0x62        // Frequency Control Word, Middle Byte
#define CC1101_DEFVAL_FREQ0_868  0x76        // Frequency Control Word, Low Byte
// Carrier frequency = 902 MHz
#define CC1101_DEFVAL_FREQ2_915  0x22        // Frequency Control Word, High Byte
#define CC1101_DEFVAL_FREQ1_915  0xB1        // Frequency Control Word, Middle Byte
#define CC1101_DEFVAL_FREQ0_915  0x3B        // Frequency Control Word, Low Byte
// Carrier frequency = 433 MHz
#define CC1101_DEFVAL_FREQ2_433  0x10        // Frequency Control Word, High Byte
#define CC1101_DEFVAL_FREQ1_433  0xA7        // Frequency Control Word, Middle Byte
#define CC1101_DEFVAL_FREQ0_433  0x62        // Frequency Control Word, Low Byte
// Carrier frequency = 400 MHz
#define CC1101_DEFVAL_FREQ2_400  0x0F        // Frequency Control Word, High Byte
#define CC1101_DEFVAL_FREQ1_400  0x62        // Frequency Control Word, Middle Byte
#define CC1101_DEFVAL_FREQ0_400  0x76        // Frequency Control Word, Low Byte
// Carrier frequency = 304 MHz
#define CC1101_DEFVAL_FREQ2_304  0x0B        // Frequency Control Word, High Byte
#define CC1101_DEFVAL_FREQ1_304  0xB1        // Frequency Control Word, Middle Byte
#define CC1101_DEFVAL_FREQ0_304  0x3B        // Frequency Control Word, Low Byte
// Carrier frequency = 302 MHz
#define CC1101_DEFVAL_FREQ2_302  0x0B        // Frequency Control Word, High Byte
#define CC1101_DEFVAL_FREQ1_302  0xA1        // Frequency Control Word, Middle Byte
#define CC1101_DEFVAL_FREQ0_302  0x15        // Frequency Control Word, Low Byte

//#define CC1101_DEFVAL_MDMCFG4    0xE5        // Modem Configuration
//#define CC1101_DEFVAL_MDMCFG3    0xC3        // Modem Configuration
#define CC1101_DEFVAL_MDMCFG4    0xF6        // Modem Configuration
#define CC1101_DEFVAL_MDMCFG3    0xEB        // Modem Configuration

#define CC1101_DEFVAL_MDMCFG2    0x30        // Modem Configuration
#define CC1101_DEFVAL_MDMCFG1    0x22        // Modem Configuration
#define CC1101_DEFVAL_MDMCFG0    0xF8        // Modem Configuration
#define CC1101_DEFVAL_DEVIATN    0x15        // Modem Deviation Setting
#define CC1101_DEFVAL_MCSM2      0x07        // Main Radio Control State Machine Configuration
//#define CC1101_DEFVAL_MCSM1      0x30        // Main Radio Control State Machine Configuration
#define CC1101_DEFVAL_MCSM1      0x20        // Main Radio Control State Machine Configuration
#define CC1101_DEFVAL_MCSM0      0x18        // Main Radio Control State Machine Configuration
#define CC1101_DEFVAL_FOCCFG     0x16        // Frequency Offset Compensation Configuration
#define CC1101_DEFVAL_BSCFG      0x6C        // Bit Synchronization Configuration
#define CC1101_DEFVAL_AGCCTRL2   0x03        // AGC Control
#define CC1101_DEFVAL_AGCCTRL1   0x00        // AGC Control
#define CC1101_DEFVAL_AGCCTRL0   0x91        // AGC Control
#define CC1101_DEFVAL_WOREVT1    0x87        // High Byte Event0 Timeout
#define CC1101_DEFVAL_WOREVT0    0x6B        // Low Byte Event0 Timeout
#define CC1101_DEFVAL_WORCTRL    0xFB        // Wake On Radio Control
#define CC1101_DEFVAL_FREND1     0x56        // Front End RX Configuration
#define CC1101_DEFVAL_FREND0     0x11        // Front End TX Configuration
#define CC1101_DEFVAL_FSCAL3     0xE9        // Frequency Synthesizer Calibration
#define CC1101_DEFVAL_FSCAL2     0x2A        // Frequency Synthesizer Calibration
#define CC1101_DEFVAL_FSCAL1     0x00        // Frequency Synthesizer Calibration
#define CC1101_DEFVAL_FSCAL0     0x1F        // Frequency Synthesizer Calibration
#define CC1101_DEFVAL_RCCTRL1    0x41        // RC Oscillator Configuration
#define CC1101_DEFVAL_RCCTRL0    0x00        // RC Oscillator Configuration
#define CC1101_DEFVAL_FSTEST     0x59        // Frequency Synthesizer Calibration Control
#define CC1101_DEFVAL_PTEST      0x7F        // Production Test
#define CC1101_DEFVAL_AGCTEST    0x3F        // AGC Test
#define CC1101_DEFVAL_TEST2      0x88        // Various Test Settings
#define CC1101_DEFVAL_TEST1      0x31        // Various Test Settings
#define CC1101_DEFVAL_TEST0      0x0B        // Various Test Settings

/**
 * Macros
 */
// Read CC1101 Config register
#define readConfigReg(regAddr)    readReg(regAddr, CC1101_CONFIG_REGISTER)
// Read CC1101 Status register
#define cc1101_readStatusReg(regAddr)    cc1101_readReg(regAddr, CC1101_STATUS_REGISTER)
// Enter Rx state
#define setRxState()              cc1101_cmdStrobe(CC1101_SRX)
// Enter Tx state
#define setTxState()              cc1101_cmdStrobe(CC1101_STX)
// Enter IDLE state
#define setIdleState()            cc1101_cmdStrobe(CC1101_SIDLE)
// Flush Rx FIFO
#define flushRxFifo()             cc1101_cmdStrobe(CC1101_SFRX)
// Flush Tx FIFO
#define flushTxFifo()             cc1101_cmdStrobe(CC1101_SFTX)
// Disable address check
#define disableAddressCheck()     cc1101_writeReg(CC1101_PKTCTRL1, 0x04)
// Enable address check
#define enableAddressCheck()      writeReg(CC1101_PKTCTRL1, 0x06)
// Disable CCA
#define disableCCA()              writeReg(CC1101_MCSM1, 0)
// Enable CCA
#define enableCCA()               writeReg(CC1101_MCSM1, CC1101_DEFVAL_MCSM1)

// PATABLE values
#define PA_LowPower               0x60
#define PA_LongDistance           0xC0

/**
 * Macros
 */
// Select (SPI) CC1101
#define cc1101_Select()  bitClear(PORT_SPI_SS, BIT_SPI_SS)
// Deselect (SPI) CC1101
#define cc1101_Deselect()  bitSet(PORT_SPI_SS, BIT_SPI_SS)
// Wait until SPI MISO line goes low
#define wait_Miso()  while(bitRead(PORT_SPI_MISO, BIT_SPI_MISO))
// Get GDO0 pin state
#define getGDO0state()  bitRead(PORT_GDO0, BIT_GDO0)
// Wait until GDO0 line goes high
#define wait_GDO0_high()  while(!getGDO0state())
// Wait until GDO0 line goes low
#define wait_GDO0_low()  while(getGDO0state())

static void cc1101_setDefaultRegs(void);

static void cc1101_writeBurstReg(uint8_t regAddr, uint8_t* buffer, uint8_t len);

static void cc1101_cmdStrobe(uint8_t cmd);

static uint8_t cc1101_readReg(uint8_t regAddr, uint8_t regType);

static void cc1101_writeReg(uint8_t regAddr, uint8_t value);

/**
 * cc1101_writeReg
 * 
 * Write single register into the CC1101 IC via SPI
 * 
 * 'regAddr'	Register address
 * 'value'	Value to be writen
 */
void cc1101_writeReg(uint8_t regAddr, uint8_t value) 
{
  cc1101_Select();                      // Select CC1101
  wait_Miso();                          // Wait until MISO goes low
  spi_send(regAddr);                    // Send register address
  spi_send(value);                      // Send value
  cc1101_Deselect();                    // Deselect CC1101
}

/**
 * cc1101_writeBurstReg
 * 
 * Write multiple registers into the CC1101 IC via SPI
 * 
 * 'regAddr'	Register address
 * 'buffer'	Data to be writen
 * 'len'	Data length
 */
void cc1101_writeBurstReg(uint8_t regAddr, uint8_t* buffer, uint8_t len)
{
  uint8_t addr, i;
  
  addr = regAddr | WRITE_BURST;         // Enable burst transfer
  cc1101_Select();                      // Select CC1101
  wait_Miso();                          // Wait until MISO goes low
  spi_send(addr);                       // Send register address
  
  for(i=0 ; i<len ; i++)
    spi_send(buffer[i]);                // Send value

  cc1101_Deselect();                    // Deselect CC1101  
}

/**
 * cmdStrobe
 * 
 * Send command strobe to the CC1101 IC via SPI
 * 
 * 'cmd'	Command strobe
 */     
void cc1101_cmdStrobe(uint8_t cmd) 
{
  cc1101_Select();                      // Select CC1101
  wait_Miso();                          // Wait until MISO goes low
  spi_send(cmd);                        // Send strobe command
  cc1101_Deselect();                    // Deselect CC1101
}

/**
 * readReg
 * 
 * Read CC1101 register via SPI
 * 
 * 'regAddr'	Register address
 * 'regType'	Type of register: CC1101_CONFIG_REGISTER or CC1101_STATUS_REGISTER
 * 
 * Return:
 * 	Data byte returned by the CC1101 IC
 */
uint8_t cc1101_readReg(uint8_t regAddr, uint8_t regType) 
{
  uint8_t addr, val;

  addr = regAddr | regType;
  cc1101_Select();                      // Select CC1101
  wait_Miso();                          // Wait until MISO goes low
  spi_send(addr);                       // Send register address
  val = spi_send(0x00);                 // Read result
  cc1101_Deselect();                    // Deselect CC1101

  return val;
}

/**
 * setDefaultRegs
 * 
 * Configure CC1101 registers
 */
void cc1101_setDefaultRegs(void) 
{
  cc1101_writeReg(CC1101_IOCFG2,  CC1101_DEFVAL_IOCFG2);
  cc1101_writeReg(CC1101_IOCFG1,  CC1101_DEFVAL_IOCFG1);
  cc1101_writeReg(CC1101_IOCFG0,  CC1101_DEFVAL_IOCFG0);
  cc1101_writeReg(CC1101_FIFOTHR,  CC1101_DEFVAL_FIFOTHR);
  cc1101_writeReg(CC1101_PKTLEN,  CC1101_DEFVAL_PKTLEN);
  cc1101_writeReg(CC1101_PKTCTRL1,  CC1101_DEFVAL_PKTCTRL1);
  cc1101_writeReg(CC1101_PKTCTRL0,  CC1101_DEFVAL_PKTCTRL0);
  //cc1101_writeReg(CC1101_SYNC1, CC1101_DEFVAL_SYNC1); // Set default synchronization word
  //cc1101_writeReg(CC1101_SYNC0, CC1101_DEFVAL_SYNC0);
  cc1101_writeReg(CC1101_SYNC1, 0x55); // Custom SYNC word
  cc1101_writeReg(CC1101_SYNC0, 0x55);
  cc1101_writeReg(CC1101_ADDR, CC1101_DEFVAL_ADDR); // Set default device address
  cc1101_writeReg(CC1101_CHANNR,  CC1101_DEFVAL_CHANNR); // Set default frequency channel
	cc1101_writeReg(CC1101_CHANNR,  CC1101_DEFVAL_CHANNR);
	cc1101_writeReg(CC1101_ADDR,  CC1101_DEFVAL_ADDR);
  cc1101_writeReg(CC1101_FSCTRL1,  CC1101_DEFVAL_FSCTRL1);
  cc1101_writeReg(CC1101_FSCTRL0,  CC1101_DEFVAL_FSCTRL0);
  cc1101_writeReg(CC1101_FREQ2,  CC1101_DEFVAL_FREQ2_302);
  cc1101_writeReg(CC1101_FREQ1,  CC1101_DEFVAL_FREQ1_302);
  cc1101_writeReg(CC1101_FREQ0,  CC1101_DEFVAL_FREQ0_302);
  cc1101_writeReg(CC1101_MDMCFG4,  CC1101_DEFVAL_MDMCFG4);
  cc1101_writeReg(CC1101_MDMCFG3,  CC1101_DEFVAL_MDMCFG3);
  cc1101_writeReg(CC1101_MDMCFG2,  CC1101_DEFVAL_MDMCFG2);
  cc1101_writeReg(CC1101_MDMCFG1,  CC1101_DEFVAL_MDMCFG1);
  cc1101_writeReg(CC1101_MDMCFG0,  CC1101_DEFVAL_MDMCFG0);
  cc1101_writeReg(CC1101_DEVIATN,  CC1101_DEFVAL_DEVIATN);
  cc1101_writeReg(CC1101_PKTLEN,  CC1101_DEFVAL_PKTLEN);
  cc1101_writeReg(CC1101_PKTCTRL1,  CC1101_DEFVAL_PKTCTRL1);
  cc1101_writeReg(CC1101_PKTCTRL0,  CC1101_DEFVAL_PKTCTRL0);
  cc1101_writeReg(CC1101_MCSM2,  CC1101_DEFVAL_MCSM2);
  cc1101_writeReg(CC1101_MCSM1,  CC1101_DEFVAL_MCSM1);
  cc1101_writeReg(CC1101_MCSM0,  CC1101_DEFVAL_MCSM0);
  cc1101_writeReg(CC1101_FOCCFG,  CC1101_DEFVAL_FOCCFG);
  cc1101_writeReg(CC1101_BSCFG,  CC1101_DEFVAL_BSCFG);
  cc1101_writeReg(CC1101_AGCCTRL2,  CC1101_DEFVAL_AGCCTRL2);
  cc1101_writeReg(CC1101_AGCCTRL1,  CC1101_DEFVAL_AGCCTRL1);
  cc1101_writeReg(CC1101_AGCCTRL0,  CC1101_DEFVAL_AGCCTRL0);
  cc1101_writeReg(CC1101_WOREVT1,  CC1101_DEFVAL_WOREVT1);
  cc1101_writeReg(CC1101_WOREVT0,  CC1101_DEFVAL_WOREVT0);
  cc1101_writeReg(CC1101_WORCTRL,  CC1101_DEFVAL_WORCTRL);
  cc1101_writeReg(CC1101_FREND1,  CC1101_DEFVAL_FREND1);
  cc1101_writeReg(CC1101_FREND0,  CC1101_DEFVAL_FREND0);
  cc1101_writeReg(CC1101_FSCAL3,  CC1101_DEFVAL_FSCAL3);
  cc1101_writeReg(CC1101_FSCAL2,  CC1101_DEFVAL_FSCAL2);
  cc1101_writeReg(CC1101_FSCAL1,  CC1101_DEFVAL_FSCAL1);
  cc1101_writeReg(CC1101_FSCAL0,  CC1101_DEFVAL_FSCAL0);
  cc1101_writeReg(CC1101_RCCTRL1,  CC1101_DEFVAL_RCCTRL1);
  cc1101_writeReg(CC1101_RCCTRL0,  CC1101_DEFVAL_RCCTRL0);
  cc1101_writeReg(CC1101_FSTEST,  CC1101_DEFVAL_FSTEST);
  cc1101_writeReg(CC1101_PTEST,  CC1101_DEFVAL_PTEST);
  cc1101_writeReg(CC1101_AGCTEST,  CC1101_DEFVAL_AGCTEST);
  cc1101_writeReg(CC1101_TEST2,  CC1101_DEFVAL_TEST2);
  cc1101_writeReg(CC1101_TEST1,  CC1101_DEFVAL_TEST1);
  cc1101_writeReg(CC1101_TEST0,  CC1101_DEFVAL_TEST0);
}

/**
 * spi_init
 * 
 * Initialize CC1101
 */
void cc1101_init(void) 
{
  spi_init();                           // Initialize SPI interface
  //setClockDivider(SPI_CLOCK_DIV16);
  //setBitOrder(MSBFIRST);
  pinMode(GDO0, INPUT);                 // Config GDO0 as input

  // reset
  {
    cc1101_Deselect();                    // Deselect CC1101
    delayMicroseconds(5);
    cc1101_Select();                      // Select CC1101
    delayMicroseconds(10);
    cc1101_Deselect();                    // Deselect CC1101
    delayMicroseconds(41);
    cc1101_Select();                      // Select CC1101

    wait_Miso();                          // Wait until MISO goes low
    spi_send(CC1101_SRES);                // Send reset command strobe
    wait_Miso();                          // Wait until MISO goes low

    cc1101_Deselect();                    // Deselect CC1101

    cc1101_setDefaultRegs();                     // Reconfigure CC1101
  }

  // Configure PATABLE
  cc1101_writeReg(CC1101_PATABLE, PA_LowPower);
  uint8_t PA_TABLE[] = {0x00, PA_POWER_MINUS_0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
  cc1101_writeBurstReg(CC1101_PATABLE, PA_TABLE, 8);

  disableAddressCheck();
}

/**
 * sendData
 * 
 * Send data packet via RF
 * 
 * 'packet'	Packet to be transmitted. First byte is the destination address
 *
 *  Return:
 *    True if the transmission succeeds
 *    False otherwise
 */
bool cc1101_sendData(uint8_t* packet, uint8_t len)
{
  uint8_t marcState;
  bool res = false;
 
  // Enter RX state
  setRxState();

  // Check that the RX state has been entered
  while (((marcState = cc1101_readStatusReg(CC1101_MARCSTATE)) & 0x1F) != 0x0D)
  {
    if (marcState == 0x11)        // RX_OVERFLOW
      flushRxFifo();              // flush receive queue
  }

  delayMicroseconds(500);

  // Set data length at the first position of the TX FIFO
  // cc1101_writeReg(CC1101_TXFIFO,  packet.length);
  // Write data into the TX FIFO
  cc1101_writeBurstReg(CC1101_TXFIFO, packet, len);

  // CCA enabled: will enter TX state only if the channel is clear
  setTxState();

  // Check that TX state is being entered (state = RXTX_SETTLING)
  marcState = cc1101_readStatusReg(CC1101_MARCSTATE) & 0x1F;
  if((marcState != 0x13) && (marcState != 0x14) && (marcState != 0x15))
  {
    setIdleState();       // Enter IDLE state
    flushTxFifo();        // Flush Tx FIFO
    setRxState();         // Back to RX state

    return false;
  }

  // Wait for the sync word to be transmitted
  wait_GDO0_high();

  // Wait until the end of the packet transmission
  wait_GDO0_low();

  // Check that the TX FIFO is empty
  if((cc1101_readStatusReg(CC1101_TXBYTES) & 0x7F) == 0)
    res = true;

  setIdleState();       // Enter IDLE state
  flushTxFifo();        // Flush Tx FIFO

  // Enter back into RX state
  setRxState();

  return res;
}
