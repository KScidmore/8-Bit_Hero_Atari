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
	
	test_plot_pixel(base);
	test_plot_hline(base);
	test_plot_genline(base);
	test_plot_diamond(base);
	test_plot_vline(base);
	test_plot_bit32(base32);
	test_plot_bit16(base16);
	test_plot_bit8(base);

	clear_screen(base);
		
	return 0;
}

void test_plot_pixel(UINT8 *base)
{
	plot_pixel(base, 300, 240);
	plot_pixel(base, 300, 260);
	plot_pixel(base, 300, 280);
	plot_pixel(base, 300, 300);
	plot_pixel(base, 300, 320);
	plot_pixel(base, 300, 340);
	plot_pixel(base, 300, 360);
}

void test_plot_hline(UINT8 *base)
{
	plot_hline(base, 300, 400, 200);
	plot_hline(base, 100, 300, 300);
	plot_hline(base, 50, 600, 100);
}

void test_plot_genline(UINT8 *base)
{
	plot_gen_line(base, 5, 5, 200, 200);
	plot_gen_line(base, 0, 0, 100, 100);
	plot_gen_line(base, 50, 20, 350, 200);

}

void test_plot_diamond(UINT8 *base)
{
	
	plot_diamond(base, 300, 200, 50);
	plot_diamond(base, 300, 200, 150);

}
void test_plot_vline(UINT8 *base)
{
	vertical_line(base, 200, 0, 200);
	vertical_line(base, 204, 0, 200);
	vertical_line(base, 208, 0, 200);
}

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