#include <stdint.h>
#include <math.h>
#include "steggy.h"
#include "steghelper.h"

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "stb_image_write.h"

#define CHANNEL_NUM 3


void write_jpg (char filename[], uint8_t* rgb_image, int width, int height, int bpp) 
{
    stbi_write_png(filename, width, height, bpp, rgb_image, width*bpp);
}

void steg_2d(char visible[], char hidden[], char output[])
{
	int v_width, v_height, v_bpp;
    uint8_t* rgb_visible_data = stbi_load(visible, &v_width, &v_height, &v_bpp, CHANNEL_NUM);

	printf("Read file %s with width %d, height %d, bpp %d\n", visible, v_width, v_height, v_bpp);

	Pixel (*rgb_visible)[v_height];
	rgb_visible = malloc(sizeof(Pixel[v_width][v_height]));
	memcpy(rgb_visible, rgb_visible_data, v_width * v_height * v_bpp);

	int h_width, h_height, h_bpp;
    uint8_t* rgb_hidden_data = stbi_load(hidden, &h_width, &h_height, &h_bpp, CHANNEL_NUM);

	printf("Read file %s with width %d, height %d, bpp %d\n", hidden, h_width, h_height, h_bpp);

	Pixel (*rgb_hidden)[h_height];
	rgb_hidden = malloc(sizeof(Pixel[h_width][h_height]));
	memcpy(rgb_hidden, rgb_hidden_data, h_width * h_height * h_bpp);

	// rgb_visible is now a 2D array of pixel structs
	// rgb_visible[0][0] is the top left pixel, and has r, g, and b components

	// Output file is the same size as rgb_visible



	stbi_image_free(rgb_visible);
	stbi_image_free(rgb_hidden);
}

void steg_1d(char visible[], char hidden[], char output[])
{
	int v_width, v_height, v_bpp;
    uint8_t* rgb_visible_data = stbi_load(visible, &v_width, &v_height, &v_bpp, CHANNEL_NUM);

	printf("Read file %s with width %d, height %d, bpp %d\n", visible, v_width, v_height, v_bpp);

	int h_width, h_height, h_bpp;
    uint8_t* rgb_hidden_data = stbi_load(hidden, &h_width, &h_height, &h_bpp, CHANNEL_NUM);

	printf("Read file %s with width %d, height %d, bpp %d\n", hidden, h_width, h_height, h_bpp);

	// rgb_visible_data is now a 1D array where red, green, blue for each pixel are one after another
	// rgb_visible_data[0] is the top left pixel's red, rgb_visible_data[1] is the top left pixel green
	// and rgb_visible_data[2] is the top left pixel blue

	// Output file is the same size as rgb_visible_data



	stbi_image_free(rgb_visible_data);
	stbi_image_free(rgb_hidden_data);
}

void steg(char visible[], char hidden[], char output[])
{
	// This function should call either steg_2d or steg_1d -- whichever one you implement
}


void unsteg_2d(char secret[], char output[])
{
	int s_width, s_height, s_bpp;
    uint8_t* rgb_secret_data = stbi_load(secret, &s_width, &s_height, &s_bpp, CHANNEL_NUM);

	printf("Read file %s with width %d, height %d, bpp %d\n", secret, s_width, s_height, s_bpp);

	Pixel (*rgb_secret)[s_height];
	rgb_secret = malloc(sizeof(Pixel[s_width][s_height]));
	memcpy(rgb_secret, rgb_secret_data, s_width * s_height * s_bpp);

	// rgb_secret is now a 2D array of pixel structs
	// rgb_secret[0][0] is the top left pixel, and has r, g, and b components

	// Output file is the same size as rgb_secret




	stbi_image_free(rgb_secret_data);
}


void unsteg_1d(char secret[], char output[])
{
	int s_width, s_height, s_bpp;
    uint8_t* rgb_secret_data = stbi_load(secret, &s_width, &s_height, &s_bpp, CHANNEL_NUM);

	printf("Read file %s with width %d, height %d, bpp %d\n", secret, s_width, s_height, s_bpp);

	// rgb_secret_data is now a 1D array where red, green, blue for each pixel are one after another
	// rgb_secret_data[0] is the top left pixel's red, rgb_visible_data[1] is the top left pixel green
	// and rgb_secret_data[2] is the top left pixel blue

	// Output file is the same size as rgb_secret



	stbi_image_free(rgb_secret_data);
}

void unsteg(char secret[], char output[])
{
	// This function should call either unsteg_2d or unsteg_1d -- whichever one you implement
}
