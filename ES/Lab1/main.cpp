#include "hal.h"

const int delay = 500; // ms
const int delay_short = 300; // ms
GPIO_PinState sw_state[4];
const int sw_count = 4;

const int led_num[] = {
        GPIO_PIN_3,
        GPIO_PIN_4,
        GPIO_PIN_5,
        GPIO_PIN_6,
        GPIO_PIN_8,
        GPIO_PIN_9,
        GPIO_PIN_11,
        GPIO_PIN_12
};
const int sw_num[] = {
        GPIO_PIN_4,
        GPIO_PIN_8,
        GPIO_PIN_10,
        GPIO_PIN_12
};
const int nbtn_num[] = { // nBTN
        GPIO_PIN_13,
        GPIO_PIN_14,
        GPIO_PIN_15
};

int sw_read();

int isN();

void play_animation();

int umain() {
    while (1) {
        for (int i = 0; i < sw_count; i++)
            sw_state[i] = HAL_GPIO_ReadPin(GPIOE, sw_num[i]);
        if (sw_state[1] && sw_state[3] && (sw_state[0] == 0) && (sw_state[2] == 0)) {
            HAL_GPIO_WritePin(GPIOD, nbtn_num[1], GPIO_PIN_RESET); // GPIO_PIN_14
            for (int i = 0; i < sw_count; i++)
                HAL_GPIO_WritePin(GPIOD, led_num[i], GPIO_PIN_RESET);
            HAL_Delay(delay);
            play_animation();
        } else {
            HAL_GPIO_WritePin(GPIOD, nbtn_num[1], GPIO_PIN_SET); // GPIO_PIN_14
            for (int i = 0; i < sw_count; i++)
                if (sw_state[i] == 1)
                    HAL_GPIO_WritePin(GPIOD, led_num[i], GPIO_PIN_SET);
                else
                    HAL_GPIO_WritePin(GPIOD, led_num[i], GPIO_PIN_RESET);
        }
        HAL_Delay(delay_short);
    }

    return 0;

}

int isN() {
    return !sw_state[0] && sw_state[1] && !sw_state[2] && sw_state[3]; // N = 0b0101 = 5
}

int sw_read() {
    for (int i = 0; i < sw_count; i++)
        sw_state[i] = HAL_GPIO_ReadPin(GPIOE, sw_num[i]);
    return !isN();
}

void play_animation() {
    int current = 7;
    for (int i = 0; i < 14; i++) {
        if (sw_read()) {
            HAL_Delay(delay_short);
            break;
        }
        HAL_Delay(delay_short);
        GPIO_PinState state = HAL_GPIO_ReadPin(GPIOC, nbtn_num[2]); // GPIO_PIN_15

        // BTN

        if (state == GPIO_PIN_RESET) {
            HAL_GPIO_WritePin(GPIOD, nbtn_num[0], GPIO_PIN_RESET);
            HAL_GPIO_WritePin(GPIOD, nbtn_num[2], GPIO_PIN_SET);
            state = GPIO_PIN_SET;
            while (state == GPIO_PIN_SET) {
                state = HAL_GPIO_ReadPin(GPIOC, nbtn_num[2]);
                HAL_Delay(delay_short);
            }
        }
        HAL_GPIO_WritePin(GPIOD, nbtn_num[0], GPIO_PIN_SET);
        HAL_GPIO_WritePin(GPIOD, nbtn_num[2], GPIO_PIN_RESET);
        HAL_Delay(delay);

        switch (i) {
            case 0:
            case 1:
            case 2:
            case 3:
            case 4:
            case 5:
            case 6:
            case 7:
                HAL_GPIO_WritePin(GPIOD, led_num[i], GPIO_PIN_SET);
                HAL_Delay(delay);
                break;
            case 8:
            case 9:
            case 10:
            case 11:
            case 12:
            case 13:
                HAL_GPIO_WritePin(GPIOD, led_num[current--], GPIO_PIN_RESET);
                HAL_Delay(delay);
                break;
            default:
                break;
        }
    }
    // Выключение всех
    for (int i = 0; i < 8; i++) {
        HAL_GPIO_WritePin(GPIOD, led_num[i], GPIO_PIN_RESET);
    }
    HAL_GPIO_WritePin(GPIOD, nbtn_num[0], GPIO_PIN_RESET);

}