#pragma once

#include <stdint.h>
#include <stdbool.h>

/**
 * cc1101_init
 * 
 * Initializa CC1101
 */
void cc1101_init(void);

/**
 * cc1101_sendData
 * 
 * Send data packet via RF
 * 
 *  Return:
 *    True if the transmission succeeds
 *    False otherwise
 */
bool cc1101_sendData(uint8_t* packet, uint8_t len);
