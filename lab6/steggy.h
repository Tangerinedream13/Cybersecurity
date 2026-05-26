#ifndef _STEGGY_H__
#define _STEGGY_H__

typedef struct pixel {
	uint8_t		r;
	uint8_t		g;
	uint8_t		b;
} Pixel;

void steg(char visible[], char hidden[], char output[]);
void unsteg(char secret[], char output[]);
#endif
