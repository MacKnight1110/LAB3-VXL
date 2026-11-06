#include "main.h"
#include "input_reading.h"

#define N0_OF_BUTTONS       3u
#define BUTTON_IS_PRESSED   GPIO_PIN_RESET
#define BUTTON_IS_RELEASED  GPIO_PIN_SET

static GPIO_TypeDef * const buttonPort[N0_OF_BUTTONS] = {
    GPIOB, GPIOB, GPIOB
};

static const uint16_t buttonPin[N0_OF_BUTTONS] = {
    GPIO_PIN_11,   // MODE
    GPIO_PIN_12,   // INC
    GPIO_PIN_13    // SET
};

static GPIO_PinState buttonBuffer[N0_OF_BUTTONS] = {
    BUTTON_IS_RELEASED,
    BUTTON_IS_RELEASED,
    BUTTON_IS_RELEASED
};

static GPIO_PinState debounceBuffer1[N0_OF_BUTTONS] = {
    BUTTON_IS_RELEASED,
    BUTTON_IS_RELEASED,
    BUTTON_IS_RELEASED
};

static GPIO_PinState debounceBuffer2[N0_OF_BUTTONS] = {
    BUTTON_IS_RELEASED,
    BUTTON_IS_RELEASED,
    BUTTON_IS_RELEASED
};

void button_reading(void)
{
    for (uint8_t i = 0; i < N0_OF_BUTTONS; i++)
    {
        debounceBuffer2[i] = debounceBuffer1[i];
        debounceBuffer1[i] =
            HAL_GPIO_ReadPin(buttonPort[i], buttonPin[i]);

        if (debounceBuffer1[i] == debounceBuffer2[i])
        {
            buttonBuffer[i] = debounceBuffer1[i];
        }
    }
}

uint8_t is_button_pressed(uint8_t index)
{
    if (index >= N0_OF_BUTTONS)
    {
        return 0u;
    }

    return (buttonBuffer[index] == BUTTON_IS_PRESSED);
}
