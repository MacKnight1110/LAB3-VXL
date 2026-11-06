#ifndef INC_INPUT_READING_H_
#define INC_INPUT_READING_H_

#include <stdint.h>

#define BUTTON_MODE_INDEX  0u
#define BUTTON_INC_INDEX   1u
#define BUTTON_SET_INDEX   2u

void button_reading(void);
uint8_t is_button_pressed(uint8_t index);

#endif
