#ifndef _HAL_H
#define _HAL_H

#include "cpu.h"

typedef unsigned int uint;

int umain();

// #define GPIO_BASE_ADDRESS  0x00000000
// #define TIMER_BASE_ADDRESS 0x10000000

#define PERIPH_BASE           0x40000000UL /*!< Peripheral base address in the alias region                                */
#define APB1PERIPH_BASE       PERIPH_BASE
#define AHB1PERIPH_BASE       (PERIPH_BASE + 0x00020000UL)

/**
  * GPIO Bit SET and Bit RESET enumeration
  */
typedef enum
{
    GPIO_PIN_RESET = 0,
    GPIO_PIN_SET
} GPIO_PinState;


// Timers
#define TIM6_BASE  (APB1PERIPH_BASE + 0x1000UL)
#define TIM7_BASE  (APB1PERIPH_BASE + 0x1400UL)

#define TIM_CR1_OFFSET  0x0000UL
#define TIM_DIER_OFFSET 0x000CUL
#define TIM_CNT_OFFSET  0x0024UL
#define TIM_PSC_OFFSET  0x0028UL
#define TIM_ARR_OFFSET  0x002CUL

#define TIM6_CR1  (TIM6_BASE + TIM_CR1_OFFSET)
#define TIM6_DIER (TIM6_BASE + TIM_DIER_OFFSET)
#define TIM6_CNT  (TIM6_BASE + TIM_CNT_OFFSET)
#define TIM6_PSC  (TIM6_BASE + TIM_PSC_OFFSET)
#define TIM6_ARR  (TIM6_BASE + TIM_ARR_OFFSET)

#define TIM7_CR1  (TIM7_BASE + TIM_CR1_OFFSET)
#define TIM7_DIER (TIM7_BASE + TIM_DIER_OFFSET)
#define TIM7_CNT  (TIM7_BASE + TIM_CNT_OFFSET)
#define TIM7_PSC  (TIM7_BASE + TIM_PSC_OFFSET)
#define TIM7_ARR  (TIM7_BASE + TIM_ARR_OFFSET)

/*******************  Bit definition for TIM_CR1 register  ********************/
#define TIM_CR1_CEN_Pos     (0U)
#define TIM_CR1_CEN_Msk     (0x1U << TIM_CR1_CEN_Pos)      /*!< 0x00000001 */
#define TIM_CR1_CEN         TIM_CR1_CEN_Msk                /*!<Counter enable */

#define TIM_CR1_OPM_Pos     (3U)
#define TIM_CR1_OPM_Msk     (0x1U << TIM_CR1_OPM_Pos)      /*!< 0x00000008 */
#define TIM_CR1_OPM         TIM_CR1_OPM_Msk                /*!<One pulse mode */

/*******************  Bit definition for TIM_DIER register  *******************/
#define TIM_DIER_UIE_Pos    (0U)
#define TIM_DIER_UIE_Msk    (0x1U << TIM_DIER_UIE_Pos)     /*!< 0x00000001 */
#define TIM_DIER_UIE        TIM_DIER_UIE_Msk               /*!<Update interrupt enable */


/*!< AHB1 peripherals */
#define GPIOA            (AHB1PERIPH_BASE + 0x0000UL)
#define GPIOB            (AHB1PERIPH_BASE + 0x0400UL)
#define GPIOC            (AHB1PERIPH_BASE + 0x0800UL)
#define GPIOD            (AHB1PERIPH_BASE + 0x0C00UL)
#define GPIOE            (AHB1PERIPH_BASE + 0x1000UL)

#define GPIO_PIN_0       (0x0001)  /* Pin 0 selected    */
#define GPIO_PIN_1       (0x0002)  /* Pin 1 selected    */
#define GPIO_PIN_2       (0x0004)  /* Pin 2 selected    */
#define GPIO_PIN_3       (0x0008)  /* Pin 3 selected    */
#define GPIO_PIN_4       (0x0010)  /* Pin 4 selected    */
#define GPIO_PIN_5       (0x0020)  /* Pin 5 selected    */
#define GPIO_PIN_6       (0x0040)  /* Pin 6 selected    */
#define GPIO_PIN_7       (0x0080)  /* Pin 7 selected    */
#define GPIO_PIN_8       (0x0100)  /* Pin 8 selected    */
#define GPIO_PIN_9       (0x0200)  /* Pin 9 selected    */
#define GPIO_PIN_10      (0x0400)  /* Pin 10 selected   */
#define GPIO_PIN_11      (0x0800)  /* Pin 11 selected   */
#define GPIO_PIN_12      (0x1000)  /* Pin 12 selected   */
#define GPIO_PIN_13      (0x2000)  /* Pin 13 selected   */
#define GPIO_PIN_14      (0x4000)  /* Pin 14 selected   */
#define GPIO_PIN_15      (0x8000)  /* Pin 15 selected   */


void HAL_GPIO_TogglePin(uint gpio_port, uint pin);
GPIO_PinState HAL_GPIO_ReadPin(uint gpio_port, uint pin);
void HAL_GPIO_WritePin(uint gpio_port, uint pin, GPIO_PinState pin_state);
void HAL_Delay(uint delay_ms);

void MODIFY_REG(uint reg_address, uint clear_mask, uint set_mask);
void SET_BIT(uint reg_address, uint set_mask);
void CLEAR_BIT(uint reg_address, uint clear_mask);
uint READ_REG(uint reg_address);
void WRITE_REG(uint reg_address, uint value);

void __disable_irq();
void __enable_irq();

void registerTIM6_IRQHandler(void (*irqHandler)());
void registerTIM7_IRQHandler(void (*irqHandler)());

#endif // _HAL_H
