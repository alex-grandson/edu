#include "hal.h"

const int sw_count = 4;
GPIO_PinState state[4];
int BASIC_DELAY = 500;
const uint T = 50; // in lab variant

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

uint get_state();
void play_animation(uint i);

void TIM6_IRQ_HANDLER() {
    uint i = 0;
    if (i > 8) i = 0;
    play_animation(i);
    i++;
}

int umain() {
    registerTIM6_IRQHandler(TIM6_IRQ_HANDLER);
    __enable_irq();

    WRITE_REG(TIM6_ARR, BASIC_DELAY);
    WRITE_REG(TIM6_DIER, TIM_DIER_UIE);
    WRITE_REG(TIM6_PSC, 0);
    WRITE_REG(TIM6_CR1, TIM_CR1_CEN);

    while (1) {
        uint mul = get_state();
        uint delay = BASIC_DELAY + mul * T;
        WRITE_REG(TIM6_ARR, delay);
    }

    __disable_irq();
    return 0;
}

uint get_state() {
    for (int i =0; i < sw_count; i++) {
        state[i] = HAL_GPIO_ReadPin(GPIOD, sw_num[i]);
    }
    return state[0] + 2 * state[1] + 4 * state[2] + 8 * state[3];
}


void play_animation(uint i) {
    switch (i) {
        case 1:
            HAL_GPIO_WritePin(GPIOD, led_num[0],GPIO_PIN_SET);
            HAL_GPIO_WritePin(GPIOD, led_num[1],GPIO_PIN_SET);

            HAL_GPIO_WritePin(GPIOD, led_num[7],GPIO_PIN_SET);
            break;
        case 2:
            HAL_GPIO_WritePin(GPIOD, led_num[0],GPIO_PIN_RESET);
            HAL_GPIO_WritePin(GPIOD, led_num[7],GPIO_PIN_RESET);

            HAL_GPIO_WritePin(GPIOD, led_num[2],GPIO_PIN_SET);

            HAL_GPIO_WritePin(GPIOD, led_num[6],GPIO_PIN_SET);

            break;
        case 3:
            HAL_GPIO_WritePin(GPIOD, led_num[2],GPIO_PIN_RESET);
            HAL_GPIO_WritePin(GPIOD, led_num[6],GPIO_PIN_RESET);

            HAL_GPIO_WritePin(GPIOD, led_num[3],GPIO_PIN_SET);

            HAL_GPIO_WritePin(GPIOD, led_num[5],GPIO_PIN_SET);

            break;
        case 4:
            HAL_GPIO_WritePin(GPIOD, led_num[3],GPIO_PIN_RESET);
            HAL_GPIO_WritePin(GPIOD, led_num[5],GPIO_PIN_RESET);

            HAL_GPIO_WritePin(GPIOD, led_num[4],GPIO_PIN_SET);
            break;
        case 5:
            HAL_GPIO_WritePin(GPIOD, led_num[2],GPIO_PIN_RESET);
            HAL_GPIO_WritePin(GPIOD, led_num[6],GPIO_PIN_RESET);

            HAL_GPIO_WritePin(GPIOD, led_num[5],GPIO_PIN_SET);

            HAL_GPIO_WritePin(GPIOD, led_num[3],GPIO_PIN_SET);
            break;
        case 6:
            HAL_GPIO_WritePin(GPIOD, led_num[5],GPIO_PIN_RESET);
            HAL_GPIO_WritePin(GPIOD, led_num[3],GPIO_PIN_RESET);

            HAL_GPIO_WritePin(GPIOD, led_num[6],GPIO_PIN_SET);

            HAL_GPIO_WritePin(GPIOD, led_num[2],GPIO_PIN_SET);
            break;
        case 7:
            HAL_GPIO_WritePin(GPIOD, led_num[6],GPIO_PIN_RESET);
            HAL_GPIO_WritePin(GPIOD, led_num[2],GPIO_PIN_RESET);

            HAL_GPIO_WritePin(GPIOD, led_num[7],GPIO_PIN_SET);

            HAL_GPIO_WritePin(GPIOD, led_num[1],GPIO_PIN_SET);
            break;
        case 8:
            HAL_GPIO_WritePin(GPIOD, led_num[7],GPIO_PIN_RESET);
            HAL_GPIO_WritePin(GPIOD, led_num[1],GPIO_PIN_RESET);

//            HAL_GPIO_WritePin(GPIOD, led_num[3],GPIO_PIN_SET);

            HAL_GPIO_WritePin(GPIOD, led_num[0],GPIO_PIN_SET);
            break;

    }
}