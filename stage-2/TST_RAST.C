/*---------------------------------------------------------------
/ ID Header:
/   Authors: 	Andrew Boisvert, Kyle Scidmore
/   Emails: 		abois526@mtroyal.ca, kscid125@mtroyal.ca
/   File Name:	RASTER.C
/   Citations:  
/     - https://en.wikipedia.org/wiki/Bresenham%27s_line_algorithm
/     - 
/
/
/ Program Purposes:
/   Test file for testing plotting routines
/-----------------------------------------------------------------*/
#include <osbind.h>
#include "raster.h"
#include "rast_asm.h"
#include "types.h"

void test_plot_pixel(UINT8 *base);
void test_plot_hline(UINT8 *base);
void test_plot_genline(UINT8 *base);
void test_plot_diamond(UINT8 *base);
void test_plot_vline(UINT8 *base);
void test_plot_bit32(UINT32 *base32);
void test_plot_bit16(UINT16 *base16);
void test_plot_bit8(UINT8 *base);

int main()
{

	UINT8 *base = (UINT8 *)Physbase();
	UINT16 *base16 = (UINT16 *)Physbase();
	UINT32 *base32 = (UINT32 *)Physbase();
	clear_screen(base);
	
	test_plot_pixel(base);
	test_plot_hline(base);
	test_plot_genline(base);
	test_plot_vline(base);
	test_plot_bit32(base32);
	test_plot_bit16(base16);
	test_plot_bit8(base);

		
	return 0;
}

/*---------- FUNCTION: test_plot_pixel ------------------
/  PURPOSE:
/    Tests multiple pixel plots including out of bounds plotting
/  
/  CALLER INPUT:
/    UINT8 *base
/    - Pointer to start of frame buffer
/  
/  CALLER OUTPUT:
/	 None
/  
/  ASSUMPTIONS, LIMITATIONS, AND KNOWN BUGS:
/    None
/--------------------------------------------------------*/
void test_plot_pixel(UINT8 *base)
{
	plot_pixel(base, 20, 50);
	plot_pixel(base, 100, 120);
	plot_pixel(base, 250, 280);
	plot_pixel(base, 300, 300);
	plot_pixel(base, 400, 380);
	plot_pixel(base, 700, 340); /*Pixel out of bounds X*/
	plot_pixel(base, 400, 450); /*Pixel out of bounds Y*/
}

/*---------- FUNCTION: test_plot_hline ------------------
/  PURPOSE:
/    Tests multiple horizontal line plots including out 
/ 	 of bounds plotting
/  
/  CALLER INPUT:
/    UINT8 *base
/    - Pointer to start of frame buffer
/  
/  CALLER OUTPUT:
/	 None
/  
/  ASSUMPTIONS, LIMITATIONS, AND KNOWN BUGS:
/    None
/--------------------------------------------------------*/
void test_plot_hline(UINT8 *base)
{
	plot_h_line(base, 300, 400, 200);
	plot_h_line(base, 100, 300, 300);
	plot_h_line(base, 50, 600, 100);
	plot_h_line(base, 20, 450, 80);
	plot_h_line(base, 700, 750, 150); /*Out of bounds start x*/
	plot_h_line(base, 400, 750, 250); /*Out of bounds end x*/
	plot_h_line(base, 120, 350, 450); /*Out of bounds y*/
}

/*---------- FUNCTION: test_plot_genline ------------------
/  PURPOSE:
/    Tests plotting generic line including out of bounds testing
/  
/  CALLER INPUT:
/    UINT8 *base
/    - Pointer to start of frame buffer
/  
/  CALLER OUTPUT:
/	 None
/  
/  ASSUMPTIONS, LIMITATIONS, AND KNOWN BUGS:
/    None
/--------------------------------------------------------*/
void test_plot_genline(UINT8 *base)
{
	plot_gen_line(base, 5, 5, 200, 200);
	plot_gen_line(base, 0, 0, 100, 100);
	plot_gen_line(base, 50, 20, 350, 200);
	plot_gen_line(base, 700, 20, 300, 220); /*Out of bounds start x*/
	plot_gen_line(base, 50, 450, 100, 20); /*Out of bounds start y*/
	plot_gen_line(base, 750, 480, 100, 20); /*Out of bounds start x and y*/
	plot_gen_line(base, 50, 20, 700, 220); /*Out of bounds end x*/
	plot_gen_line(base, 80, 30, 100, 600); /*Out of bounds end y*/
	plot_gen_line(base, 600, 260, 720, 650); /*Out of bounds end x and y*/
	plot_gen_line(base, 800, 500, 720, 650); /*Out of bounds all coords*/

}

/*---------- FUNCTION: test_plot_vline ------------------
/  PURPOSE:
/    Tests plotting vertical lines including out of bounds testing
/  
/  CALLER INPUT:
/    UINT8 *base
/    - Pointer to start of frame buffer
/  
/  CALLER OUTPUT:
/	 None
/  
/  ASSUMPTIONS, LIMITATIONS, AND KNOWN BUGS:
/    None
/--------------------------------------------------------*/
void test_plot_vline(UINT8 *base)
{
	vertical_line(base, 200, 0, 20);
	vertical_line(base, 204, 50, 50);
	vertical_line(base, 208, 100, 80);
	vertical_line(base, 220, 150, 100);
	vertical_line(base, 240, 200, 150);
	vertical_line(base, 300, 300, 200); /*Out of bounds height*/
	vertical_line(base, 320, 450, 100); /*Out of bounds start y*/
}

/*---------- FUNCTION: test_plot_bit32 ------------------
/  PURPOSE:
/    Tests plotting 32 bit wide bitmap
/  
/  CALLER INPUT:
/    UINT32 *base
/    - Pointer to start of frame buffer
/  
/  CALLER OUTPUT:
/	 None
/  
/  ASSUMPTIONS, LIMITATIONS, AND KNOWN BUGS:
/    Only plots to multiples of 32 bits
/--------------------------------------------------------*/
void test_plot_bit32(UINT32 *base32)
{
	UINT32 a_bitmap[32] =
	{
		0xFFFFFFFF,
		0xFFFFFFFF,
		0xFFFFFFFF,
		0xE0000007,
		0xE0000007,
		0xE0000007,
		0xE007E007,
		0xE00FF007,
		0xE00E7007,
		0xE01C3807,
		0xE0381C07,
		0xE0700E07,
		0xE1E00787,
		0xE1C00387,
		0xE1C00387,
		0xE1C00387,
		0xE1FFFF87,
		0xE1FFFF87,
		0xE1FFFF87,
		0xE1C00387,
		0xE1C00387,
		0xE1C00387,
		0xE1C00387,
		0xE1C00387,
		0xE1C00387,
		0xE0000007,
		0xE0000007,
		0xE0000007,
		0xFFFFFFFF,
		0xFFFFFFFF,
		0xFFFFFFFF
	};

	plot_bitmap_32(base32, 64, 20, a_bitmap, 32 );
	plot_bitmap_32(base32, 128, 20, a_bitmap, 32);
}

/*---------- FUNCTION: test_plot_bit16 ------------------
/  PURPOSE:
/    Tests plotting 16 bit wide bitmap
/  
/  CALLER INPUT:
/    UINT16 *base
/    - Pointer to start of frame buffer
/  
/  CALLER OUTPUT:
/	 None
/  
/  ASSUMPTIONS, LIMITATIONS, AND KNOWN BUGS:
/    Only plots to multiples of 16 bits
/--------------------------------------------------------*/
void test_plot_bit16(UINT16 *base16)
{
	UINT16 smile[16] =
	{
		0xFFFF,
		0xFFFF,
		0xC003,
		0xC003,
		0xCC33,
		0xCC33,
		0xCC33,
		0xC003,
		0xC003,
		0xCC33,
		0xCFF3,
		0xC7E3,
		0xC003,
		0xC003,
		0xFFFF,
		0xFFFF
	};

	plot_bitmap_16(base16, 64, 100, smile, 16);
	plot_bitmap_16(base16, 128, 100, smile, 16);
}

/*---------- FUNCTION: test_plot_bit32 ------------------
/  PURPOSE:
/    Tests plotting 8 bit wide bitmap
/  
/  CALLER INPUT:
/    UINT8 *base
/    - Pointer to start of frame buffer
/  
/  CALLER OUTPUT:
/	 None
/  
/  ASSUMPTIONS, LIMITATIONS, AND KNOWN BUGS:
/    Only plots to multiples of 8 bits
/--------------------------------------------------------*/
void test_plot_bit8(UINT8 *base)
{
	UINT8 greyscale[8] =
	{
		0xAA,
		0x55,
		0xAA,
		0x55,
		0xAA,
		0x55,
		0xAA,
		0x55,
	
	};

	plot_bitmap_8(base, 64, 200, greyscale, 8);
	plot_bitmap_8(base, 128, 200, greyscale, 8);
}