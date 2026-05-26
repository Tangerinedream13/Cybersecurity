#include <stdint.h>
#include "steghelper.h"

uint8_t hide(uint8_t visible, uint8_t hidden) {

    uint8_t clearedVisible = visible & 0xFC;   // Clears the last two bits
    uint8_t hiddenBits = hidden >> 6;          // Moves the top two bits to the bottom

    return clearedVisible | hiddenBits;
}

uint8_t show(uint8_t secret) {

    uint8_t extractedBits = secret & 0x03;     // Isolates the last two bits

    return extractedBits << 6;                 // Then moves them to top
}

