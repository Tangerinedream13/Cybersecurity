#ifndef _STEGHELPER_H__
#define _STEGHELPER_H__

#include <stdint.h>

uint8_t hide(uint8_t visible, uint8_t hidden);
uint8_t show(uint8_t secret);

#endif