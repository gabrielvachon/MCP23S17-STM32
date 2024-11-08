#ifndef MCP23S17_H_
#define MCP23S17_H_

#include <stdint.h>
#include "stm32l4xx_hal.h"

// --------- Register list ---------
// ---------------------------------
// Using IOCON.BANK = 0
#define IODIRA		0x00
#define IODIRB		0x01
#define IPOLA		0x02
#define IPOLB		0x03
#define GPIINTENA	0x04
#define GPIINTENB	0x05
#define DEFVALA		0x06
#define DEFVALB		0x07
#define INTCONA		0x08
#define INTCONB		0x09
#define IOCON		0x0A
#define GPPUA		0x0C
#define GPPUB		0x0D
#define INTFA		0x0E
#define INTFB		0x0F
#define INTCAPA		0x10
#define INTCAPB		0x11
#define GPIOA_MCP	0x12
#define GPIOB_MCP	0x13
#define OLATA		0x14
#define OLATB		0x15

// --------- IOCON configs ---------
// ---------------------------------
// Using IOCON.BANK = 0
#define BANK_ON		0x80
#define BANK_OFF	0x00
#define MIRROR_ON	0x40
#define MIRROR_OFF	0x00
#define SEQOP_ON	0x20
#define SEQOP_OFF	0x00
#define DISSLW_ON	0x10
#define DISSLW_OFF	0x00
#define HAEN_ON		0x08
#define HAEN_OFF	0x00
#define ODR_ON		0x04
#define ODR_OFF		0x00
#define INTPOL_ON	0x02
#define INTPOL_OFF  0x00

#define ADDR_FIX_BIT 0b01000000

typedef struct MCP23S17 {

	uint8_t hardware_addr;
	uint8_t opcode;
	uint16_t CS;
	uint16_t t_buffer;
	uint16_t r_buffer;
	GPIO_TypeDef* peripheral;
	SPI_HandleTypeDef spi_handler;

//    int (*read_REG)(struct MCP23S17* mcp23s17, uint8_t reg_opcode, uint8_t reg_addr);
//    void (*write_REG)(struct MCP23S17* mcp23s17, uint8_t reg_opcode, uint8_t reg_addr);
//    int (*check_REG)(uint8_t reg_addr);

} MCP23S17;


void MCP23S17_Init(MCP23S17* mcp23s17, uint8_t hardware_addr, uint16_t CS, GPIO_TypeDef* peripheral, SPI_HandleTypeDef spi_handler);

uint8_t MCP23S17_read_REG(MCP23S17* mcp23s17, uint8_t reg_addr);

void MCP23S17_write_REG(MCP23S17* mcp23s17, uint8_t reg_addr, uint8_t config);

int MCP23S17_check_REG(uint8_t reg_addr);

#endif
