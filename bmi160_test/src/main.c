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

