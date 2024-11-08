#include <MCP23S17.h>

void MCP23S17_Init(MCP23S17* mcp23s17, uint8_t hardware_addr, uint16_t CS, GPIO_TypeDef* peripheral, SPI_HandleTypeDef spi_handler) {

	if(hardware_addr >= 0x08) { return; }

	HAL_GPIO_WritePin(peripheral, CS, GPIO_PIN_SET);

	mcp23s17->hardware_addr = hardware_addr;
	mcp23s17->opcode = (ADDR_FIX_BIT | hardware_addr);
	mcp23s17->CS = CS;
	mcp23s17->peripheral = peripheral;
	mcp23s17->spi_handler = spi_handler;
}

uint8_t MCP23S17_read_REG(MCP23S17* mcp23s17, uint8_t reg_addr) {

	if(MCP23S17_check_REG(reg_addr) < 0) { return -1; }

	uint8_t transmit[2] = {mcp23s17->opcode | 0x01, reg_addr};
	uint8_t receive;

    HAL_GPIO_WritePin(mcp23s17->peripheral, mcp23s17->CS, GPIO_PIN_RESET);
    HAL_SPI_Transmit(&(mcp23s17->spi_handler), transmit, 2, HAL_MAX_DELAY);
    HAL_SPI_Receive(&(mcp23s17->spi_handler), &receive, 1, HAL_MAX_DELAY);
    HAL_GPIO_WritePin(mcp23s17->peripheral, mcp23s17->CS, GPIO_PIN_SET);

    return receive;
}

void MCP23S17_write_REG(MCP23S17* mcp23s17, uint8_t reg_addr, uint8_t config) {

	if(MCP23S17_check_REG(reg_addr) < 0) { return; }

	uint8_t transmit[3] = {mcp23s17->opcode & ~0x01, reg_addr, config};


	HAL_GPIO_WritePin(mcp23s17->peripheral, mcp23s17->CS, GPIO_PIN_RESET);
	HAL_SPI_Transmit(&(mcp23s17->spi_handler), transmit, 3, HAL_MAX_DELAY);
    HAL_GPIO_WritePin(mcp23s17->peripheral, mcp23s17->CS, GPIO_PIN_SET);

}

int MCP23S17_check_REG(uint8_t reg_addr) {
	switch (reg_addr) {
	case IODIRA:
		return 0;
				break;
	case IODIRB:
		return 0;
				break;
	case IPOLA:
		return 0;
				break;
	case IPOLB:
		return 0;
				break;
	case GPIINTENA:
		return 0;
				break;
	case GPIINTENB:
		return 0;
				break;
	case DEFVALA:
		return 0;
				break;
	case DEFVALB:
		return 0;
				break;
	case INTCONA:
		return 0;
				break;
	case INTCONB:
		return 0;
				break;
	case IOCON:
		return 0;
				break;
	case GPPUA:
		return 0;
				break;
	case GPPUB:
		return 0;
				break;
	case INTFA:
		return 0;
				break;
	case INTFB:
		return 0;
				break;
	case INTCAPA:
		return 0;
				break;
	case INTCAPB:
		return 0;
				break;
	case GPIOA_MCP:
		return 0;
				break;
	case GPIOB_MCP:
		return 0;
				break;
	case OLATA:
		return 0;
				break;
	case OLATB:
		return 0;
				break;
	default:
		return -1;
				break;
	}
}
