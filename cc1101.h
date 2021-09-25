#pragma once

#include <stdint.h>
#include <stdbool.h>

/**
 * init
 * 
 * Initializa CC1101
 */
void cc1101_init(void);

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
bool cc1101_sendData(uint8_t* packet, uint8_t len);
