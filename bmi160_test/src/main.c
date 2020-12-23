#include <asf.h>
#include <stdlib.h>
#include <spi.h>
#include <uart.h>
#include <bmi160.h>

int main (void) {
    /* Insert system clock initialization code here (sysclk_init()). */
    board_init();

    uart_init();
    printf("------- Default testing -------\r\n\r\n");

    spi_init();

    uint8_t sensorID = reg_read(BMI160_RA_CHIP_ID);
    printf("Sensor id: 0x%x\r\n\r\n", sensorID);

    //sensorID = bmi160_init();
    //printf("Read 2 - Sensor id: 0x%x\r\n\r\n", sensorID);

    int16_t gxRaw, gyRaw, gzRaw;         // raw gyro values

    while (1) {
        uint8_t sensorID = reg_read(BMI160_RA_CHIP_ID);
        printf("Sensor id: 0x%x\r\n", sensorID);

        read_gyro(&gxRaw, &gyRaw, &gzRaw);

        printf("gx: %d ", gxRaw);
        printf("gy: %d ", gyRaw);
        printf("gx: %d\r\n", gzRaw);

        printf("\r\n");
        delay_ms(8000);
    }
}


// NOTE: read_gyro() returns raw gyro values that need to be converted
/*
    float convertRawGyro(int gRaw) {
	// since we are using 250 degrees/seconds range
	// -250 maps to a raw value of -32768
	// +250 maps to a raw value of 32767

	float g = (gRaw * 250.0) / 32768.0;

	return g;
    }
*/
