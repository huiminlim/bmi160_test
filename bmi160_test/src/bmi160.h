/*
    bmi160.h

    Created: 21/12/2020 11:18:14 PM
    Author: user
*/

#define BMI160_CHIP_ID				0xD1
#define BMI160_SPI_READ_BIT         7

#define BMI160_RA_CHIP_ID           0x00
#define BMI160_RA_CMD               0x7E

#define BMI160_CMD_SOFT_RESET       0xB6

int bmp280_init(void);
uint8_t read8(uint8_t reg);
void write8 (uint8_t reg, uint8_t value);
uint8_t spixfer(uint8_t x);