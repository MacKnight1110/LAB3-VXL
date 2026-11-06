#include "main.h"
#include "led_display.h"

typedef struct
{
    GPIO_TypeDef *port;
    uint16_t pin;
} DisplayPin;

static const DisplayPin segPins[7] = {
    {SEG0_GPIO_Port, SEG0_Pin},
    {SEG1_GPIO_Port, SEG1_Pin},
    {SEG2_GPIO_Port, SEG2_Pin},
    {SEG3_GPIO_Port, SEG3_Pin},
    {SEG4_GPIO_Port, SEG4_Pin},
    {SEG5_GPIO_Port, SEG5_Pin},
    {SEG6_GPIO_Port, SEG6_Pin}
};

static const DisplayPin enPins[4] = {
    {EN0_GPIO_Port, EN0_Pin},
    {EN1_GPIO_Port, EN1_Pin},
    {EN2_GPIO_Port, EN2_Pin},
    {EN3_GPIO_Port, EN3_Pin}
};

static const DisplayPin redLeds[4] = {
    {REDN_GPIO_Port, REDN_Pin},
    {REDE_GPIO_Port, REDE_Pin},
    {REDS_GPIO_Port, REDS_Pin},
    {REDW_GPIO_Port, REDW_Pin}
};

static const DisplayPin yellowLeds[4] = {
    {YELLOWN_GPIO_Port, YELLOWN_Pin},
    {YELLOWE_GPIO_Port, YELLOWE_Pin},
    {YELLOWS_GPIO_Port, YELLOWS_Pin},
    {YELLOWW_GPIO_Port, YELLOWW_Pin}
};

static const DisplayPin greenLeds[4] = {
    {GREENN_GPIO_Port, GREENN_Pin},
    {GREENE_GPIO_Port, GREENE_Pin},
    {GREENS_GPIO_Port, GREENS_Pin},
    {GREENW_GPIO_Port, GREENW_Pin}
};

/* Bit 0=A, bit 1=B, ..., bit 6=G. */
static const uint8_t digitPattern[11] = {
    0x3F, 0x06, 0x5B, 0x4F, 0x66,
    0x6D, 0x7D, 0x07, 0x7F, 0x6F,
    0x00  // blank
};

static uint8_t digits[4] = {10u, 10u, 10u, 10u};
static uint8_t scanIndex = 0u;
static uint8_t blinkOn = 1u;
static uint8_t previousMode = 0xFFu;
static uint32_t lastScanTick = 0u;
static uint32_t lastBlinkTick = 0u;

static void writeGroup(const DisplayPin *pins,
                       uint8_t count,
                       GPIO_PinState state)
{
    for (uint8_t i = 0; i < count; i++)
    {
        HAL_GPIO_WritePin(pins[i].port, pins[i].pin, state);
    }
}

static void allDigitsOff(void)
{
    writeGroup(enPins, 4u, GPIO_PIN_SET);
}

static void allTrafficLedsOff(void)
{
    writeGroup(redLeds, 4u, GPIO_PIN_RESET);
    writeGroup(yellowLeds, 4u, GPIO_PIN_RESET);
    writeGroup(greenLeds, 4u, GPIO_PIN_RESET);
}

static void showEditModeLeds(uint8_t mode)
{
    writeGroup(redLeds, 4u,
               (mode == 2u && blinkOn) ? GPIO_PIN_SET : GPIO_PIN_RESET);

    writeGroup(yellowLeds, 4u,
               (mode == 3u && blinkOn) ? GPIO_PIN_SET : GPIO_PIN_RESET);

    writeGroup(greenLeds, 4u,
               (mode == 4u && blinkOn) ? GPIO_PIN_SET : GPIO_PIN_RESET);
}

static void setSegments(uint8_t value)
{
    uint8_t pattern = digitPattern[value];

    for (uint8_t i = 0; i < 7u; i++)
    {
        GPIO_PinState level =
            (pattern & (1u << i)) ? GPIO_PIN_RESET : GPIO_PIN_SET;

        HAL_GPIO_WritePin(segPins[i].port, segPins[i].pin, level);
    }
}

void led_display_task(uint8_t mode, uint8_t value)
{
    uint32_t now = HAL_GetTick();

    if (mode != previousMode)
    {
        previousMode = mode;
        lastBlinkTick = now;
        blinkOn = 1u;

        if (mode == 1u)
        {
            allTrafficLedsOff();
        }
    }

    if (mode >= 2u && mode <= 4u)
    {
        /* 2 Hz: một chu kỳ 500 ms, đảo trạng thái mỗi 250 ms. */
        if ((uint32_t)(now - lastBlinkTick) >= 250u)
        {
            lastBlinkTick = now;
            blinkOn = !blinkOn;
        }

        showEditModeLeds(mode);

        /* Hai digit đầu hiển thị giá trị; hai digit sau hiển thị mode. */
        digits[0] = (uint8_t)(value / 10u);
        digits[1] = (uint8_t)(value % 10u);
        digits[2] = 0u;
        digits[3] = mode;
    }
    else
    {
        /* Normal-mode display sẽ được ghép vào chu kỳ đèn ở phần sau. */
        digits[0] = 10u;
        digits[1] = 10u;
        digits[2] = 10u;
        digits[3] = 10u;
    }

    /* Quét một digit mỗi 2 ms: gọi hàm này liên tục trong superloop. */
    if ((uint32_t)(now - lastScanTick) >= 2u)
    {
        lastScanTick = now;
        allDigitsOff();

        if (digits[scanIndex] < 10u)
        {
            setSegments(digits[scanIndex]);
            HAL_GPIO_WritePin(enPins[scanIndex].port,
                              enPins[scanIndex].pin,
                              GPIO_PIN_RESET);
        }

        scanIndex = (uint8_t)((scanIndex + 1u) % 4u);
    }
}
