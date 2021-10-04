#include "cc1101.h"
#include "spi.h"
#include "io.h"
#include "time.h"
#include "main.h"

#include "cc1101_private.h"

int getGDO0state(void)
{
  return digitalRead(2);
}

void wait_GDO0_high(void)
{
  while(!getGDO0state());
}

void wait_GDO0_low(void)
{
  while(getGDO0state());
}

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
 extern uint8_t SPI_ReceiveData(void);
uint8_t cc1101_readReg(uint8_t regAddr, uint8_t regType) 
{
  uint8_t addr, val;

  addr = regAddr | regType;
  cc1101_Select();                      // Select CC1101
  wait_Miso();                          // Wait until MISO goes low
  spi_send(addr);                       // Send register address
  val = spi_send(0x00);                 // Read result
  
	val = SPI_ReceiveData(); // Read again. stupid hardware. // !
  cc1101_Deselect();                    // Deselect CC1101

  val = SPI_ReceiveData(); // Read again. stupid hardware. // !
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
 * CC1101 init
 * 
 * Initialize CC1101
 */
void cc1101_init(void) 
{
	int i,j,k;
	uint8_t PA_TABLE[] = {0x00, PA_POWER_MINUS_0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
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
  
  cc1101_writeBurstReg(CC1101_PATABLE, PA_TABLE, 8);

  disableAddressCheck();
#if 1
/*
Serial.print("CC1101_PARTNUM ");
Serial.println(cc1101.readReg(CC1101_PARTNUM, CC1101_STATUS_REGISTER));
Serial.print("CC1101_VERSION ");
Serial.println(cc1101.readReg(CC1101_VERSION, CC1101_STATUS_REGISTER));
Serial.print("CC1101_MARCSTATE ");
Serial.println(cc1101.readReg(CC1101_MARCSTATE, CC1101_STATUS_REGISTER) & 0x1f);
*/
 i = cc1101_readReg(CC1101_PARTNUM, CC1101_STATUS_REGISTER);
 j = cc1101_readReg(CC1101_VERSION, CC1101_STATUS_REGISTER);
 k = cc1101_readReg(CC1101_MARCSTATE, CC1101_STATUS_REGISTER);
#endif
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
