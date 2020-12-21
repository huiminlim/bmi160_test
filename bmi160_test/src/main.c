#include <asf.h>
#include <spi.h>
#include <uart.h>
#include <bmi160.h>


uint8_t reg_read (uint8_t reg) {
    //uint8_t buffer[1];
    //buffer[0] = reg;
    //serial_buffer_transfer(buffer, 1, 1);
    //return buffer[0];

    uint8_t ret = read8(reg);
    return ret;
}

void reg_write(uint8_t reg, uint8_t data) {
    uint8_t buffer[2];
    buffer[0] = reg;
    buffer[1] = data;
    //serial_buffer_transfer(buffer, 2, 0);
}

int main (void) {
    /* Insert system clock initialization code here (sysclk_init()). */
    board_init();

    uart_init();
    printf("------- Default testing -------\r\n\r\n");

    spi_init();

    while (1) {
        uint8_t sensorID = reg_read(BMI160_RA_CHIP_ID);
        printf("Sensor id: 0x%x\r\n\r\n", sensorID);
        delay_ms(8000);
    }

    // Initialization of sensor
    /* Issue a soft-reset to bring the device into a clean state */
    //reg_write(BMI160_RA_CMD, BMI160_CMD_SOFT_RESET);
    delay_ms(1);

    /* Issue a dummy-read to force the device into SPI comms mode */
    //reg_read(0x7F);
    delay_ms(1);

    /* Power up the accelerometer */
    //reg_write(BMI160_RA_CMD, BMI160_CMD_ACC_MODE_NORMAL);
    delay_ms(1);

    /* Wait for power-up to complete */
    /*
        while (0x1 != reg_read_bits(BMI160_RA_PMU_STATUS,
                                BMI160_ACC_PMU_STATUS_BIT,
                                BMI160_ACC_PMU_STATUS_LEN)) {
        delay_ms(1);
        }
    */

    /* Power up the gyroscope */
    //reg_write(BMI160_RA_CMD, BMI160_CMD_GYR_MODE_NORMAL);
    delay_ms(1);

    /* Wait for power-up to complete */
    /*
        while (0x1 != reg_read_bits(BMI160_RA_PMU_STATUS,
                            BMI160_GYR_PMU_STATUS_BIT,
                            BMI160_GYR_PMU_STATUS_LEN)) {
        delay_ms(1);
        }
    */

    //setFullScaleGyroRange(BMI160_GYRO_RANGE_250);
    //setFullScaleAccelRange(BMI160_ACCEL_RANGE_2G);

}

