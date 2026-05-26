#include <stdint.h>
#include <stdlib.h> 
#include <string.h> 
#include <stdio.h> 
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

	Pixel (*rgb_visible)[v_width];
	rgb_visible = malloc(sizeof(Pixel[v_height][v_width]));
	memcpy(rgb_visible, rgb_visible_data, v_width * v_height * CHANNEL_NUM);

	int h_width, h_height, h_bpp;
    uint8_t* rgb_hidden_data = stbi_load(hidden, &h_width, &h_height, &h_bpp, CHANNEL_NUM);

	printf("Read file %s with width %d, height %d, bpp %d\n", hidden, h_width, h_height, h_bpp);

	Pixel (*rgb_hidden)[h_width]; 
	rgb_hidden = malloc(sizeof(Pixel[h_height][h_width]));
	memcpy(rgb_hidden, rgb_hidden_data, h_width * h_height * CHANNEL_NUM);

	Pixel (*rgb_output)[v_width];
	rgb_output = malloc(sizeof(Pixel[v_height][v_width]));

	for (int row = 0; row < v_height; row++)
	{
		for (int col = 0; col < v_width; col++)
		{
			if (row < h_height && col < h_width)
			{
				rgb_output[row][col].r = hide(rgb_visible[row][col].r, rgb_hidden[row][col].r);
				rgb_output[row][col].g = hide(rgb_visible[row][col].g, rgb_hidden[row][col].g);
				rgb_output[row][col].b = hide(rgb_visible[row][col].b, rgb_hidden[row][col].b);
			}
			else
			{
				rgb_output[row][col].r = hide(rgb_visible[row][col].r, 0);
				rgb_output[row][col].g = hide(rgb_visible[row][col].g, 0);
				rgb_output[row][col].b = hide(rgb_visible[row][col].b, 0);
			}
		}
	}

	write_jpg(output, (uint8_t*) rgb_output, v_width, v_height, CHANNEL_NUM);

	stbi_image_free(rgb_visible_data);
	stbi_image_free(rgb_hidden_data);
	free(rgb_visible);
	free(rgb_hidden);
	free(rgb_output);
}

void steg_1d(char visible[], char hidden[], char output[])
{
	int v_width, v_height, v_bpp;
    uint8_t* rgb_visible_data = stbi_load(visible, &v_width, &v_height, &v_bpp, CHANNEL_NUM);

	printf("Read file %s with width %d, height %d, bpp %d\n", visible, v_width, v_height, v_bpp);

	int h_width, h_height, h_bpp;
    uint8_t* rgb_hidden_data = stbi_load(hidden, &h_width, &h_height, &h_bpp, CHANNEL_NUM);

	printf("Read file %s with width %d, height %d, bpp %d\n", hidden, h_width, h_height, h_bpp);
	stbi_image_free(rgb_visible_data);
	stbi_image_free(rgb_hidden_data);
}

void steg(char visible[], char hidden[], char output[])
{
	steg_2d(visible, hidden, output);
}


void unsteg_2d(char secret[], char output[])
{
	int s_width, s_height, s_bpp;
    uint8_t* rgb_secret_data = stbi_load(secret, &s_width, &s_height, &s_bpp, CHANNEL_NUM);

	printf("Read file %s with width %d, height %d, bpp %d\n", secret, s_width, s_height, s_bpp);

	Pixel (*rgb_secret)[s_width];
	rgb_secret = malloc(sizeof(Pixel[s_height][s_width]));
	memcpy(rgb_secret, rgb_secret_data, s_width * s_height * CHANNEL_NUM);

	Pixel (*rgb_output)[s_width];
	rgb_output = malloc(sizeof(Pixel[s_height][s_width]));

	for (int row = 0; row < s_height; row++)
	{
		for (int col = 0; col < s_width; col++)
		{
			rgb_output[row][col].r = show(rgb_secret[row][col].r);
			rgb_output[row][col].g = show(rgb_secret[row][col].g);
			rgb_output[row][col].b = show(rgb_secret[row][col].b);
		}
	}

	write_jpg(output, (uint8_t*) rgb_output, s_width, s_height, CHANNEL_NUM);

	stbi_image_free(rgb_secret_data);
	free(rgb_secret);
	free(rgb_output);
}


void unsteg_1d(char secret[], char output[])
{
	int s_width, s_height, s_bpp;
    uint8_t* rgb_secret_data = stbi_load(secret, &s_width, &s_height, &s_bpp, CHANNEL_NUM);

	printf("Read file %s with width %d, height %d, bpp %d\n", secret, s_width, s_height, s_bpp);

	stbi_image_free(rgb_secret_data); }
void unsteg(char secret[], char output[])
{
	unsteg_2d(secret, output);
}