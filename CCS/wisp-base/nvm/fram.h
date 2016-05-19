/**
 * @file fram.h
 *
 * Provides an interface to the INFOA through INFOD FRAM sections of memory for the MSP430FR5xxx
 * Other than the quite useful defined memory locations, these functions are pretty superfluous.
 * One could just as easily use the defines and never use these silly shortcut functions at all.
 *
 * @author Saman Naderiparizi, Aaron Parks, modified by Jeremy Bobotek, 2016
 */

#ifndef FRAM_H_
#define FRAM_H_

#include <stdint.h>

//this FRAM section literally just partitions the FRAM memory, can't believe these guys just write to specific sections
#define FRAM_INFOA_START_ADX 	0x1980
#define FRAM_INFOB_START_ADX 	0x1900
#define FRAM_INFOC_START_ADX 	0x1880
#define FRAM_INFOD_START_ADX 	0x1800

//general FRAM memory section
#define FRAM_START_ADX			0x4400 //length is 48k addresses, byte addressable(i think)
#define FRAM2_START_ADX			0x10000//length is 16.384k(4000 in hex), for total fram space of 64kB

#define FRAM_write(address, writeData) (*(address))=(writeData) //terrible way to do this.

void FRAM_init(void);

//omg these functions are so pointless, just use FRAM_write, these are all just crap functions to write specific data types
//that could easily be done as needed
void FRAM_write_long_array(uint32_t *address , uint16_t numberOfLongs , uint32_t *writeData);
void FRAM_write_int_array(uint16_t *address , uint16_t numberOfInts , uint16_t *writeData);
void FRAM_write_char_array(uint8_t *address , uint16_t numberOfChars , uint8_t *writeData);

void FRAM_write_infoA_long(int addressOffset , uint16_t numberOfLongs , uint32_t *writeData);
void FRAM_write_infoA_int(int addressOffset , uint16_t numberOfInts , uint16_t *writeData);
void FRAM_write_infoA_char(int addressOffset , uint16_t numberOfChars , uint8_t *writeData);

void FRAM_write_infoB_long(int addressOffset , uint16_t numberOfLongs , uint32_t *writeData);
void FRAM_write_infoB_int(int addressOffset , uint16_t numberOfInts , uint16_t *writeData);
void FRAM_write_infoB_char(int addressOffset , uint16_t numberOfChars , uint8_t *writeData);

void FRAM_write_infoC_long(int addressOffset , uint16_t numberOfLongs , uint32_t *writeData);
void FRAM_write_infoC_int(int addressOffset , uint16_t numberOfInts , uint16_t *writeData);
void FRAM_write_infoC_char(int addressOffset , uint16_t numberOfChars , uint8_t *writeData);

void FRAM_write_infoD_long(int addressOffset , uint16_t numberOfLongs , uint32_t *writeData);
void FRAM_write_infoD_int(int addressOffset , uint16_t numberOfInts , uint16_t *writeData);
void FRAM_write_infoD_char(int addressOffset , uint16_t numberOfChars , uint8_t *writeData);


uint32_t FRAM_read_long(uint32_t *address);
uint16_t FRAM_read_int(uint16_t *address);
uint8_t FRAM_read_char(uint8_t *address);

uint32_t FRAM_read_infoA_long(int addressOffset);
uint16_t FRAM_read_infoA_int(int addressOffset);
uint8_t FRAM_read_infoA_char(int addressOffset);

uint32_t FRAM_read_infoB_long(int addressOffset);
uint16_t FRAM_read_infoB_int(int addressOffset);
uint8_t FRAM_read_infoB_char(int addressOffset);

uint32_t FRAM_read_infoC_long(int addressOffset);
uint16_t FRAM_read_infoC_int(int addressOffset);
uint8_t FRAM_read_infoC_char(int addressOffset);

uint32_t FRAM_read_infoD_long(int addressOffset);
uint16_t FRAM_read_infoD_int(int addressOffset);
uint8_t FRAM_read_infoD_char(int addressOffset);

#endif /* FRAM_H_ */
