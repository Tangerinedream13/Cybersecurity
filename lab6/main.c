#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "steghelper.h"
#include "steggy.h"

void test_hide(uint8_t v, uint8_t h, uint8_t ans)
{
    printf("%x should be %x and was formed from visible %x and hidden %x\n", hide(v, h), ans, v, h);
}

void test_show(uint8_t s, uint8_t ans)
{
    printf("%x should be %x and was unhidden from %x\n", show(s), ans, s);
}

int main(int argc, char* argv[])
{
    if (argc == 1)
    {
        test_hide(0x76, 0x00, 0x74);
        test_hide(0x76, 0x40, 0x75);
        test_hide(0x76, 0x80, 0x76);
        test_hide(0x76, 0xC0, 0x77);

        test_show(0x74, 0x00);
        test_show(0x75, 0x40);
        test_show(0x76, 0x80);
        test_show(0x77, 0xC0);

        exit(0);
    }

    if ((argc != 4) && (argc != 3))
    {
        printf("Usage: steggy visible hidden output\n");
        printf("or\n");
        printf("Usage: steggy secret output\n");
        exit(1); 
    }
    if (argc == 4)
        steg(argv[1], argv[2], argv[3]);
    else
        unsteg(argv[1], argv[2]);
}