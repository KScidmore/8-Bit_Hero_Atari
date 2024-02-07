#include <osbind.h>
#include "raster.h"
#include "types.h"

void test_plot_pixel(UINT8 *base);
void test_plot_hline(UINT8 *base);
void test_plot_genline(UINT8 *base);

int main()
{
	UINT8 *base = (UINT8 *)Physbase();
	
	/* FOR TESTING STUFF 
	test_plot_pixel(base);
	test_plot_hline(base);
	*/
	plot_diamond(base, 300, 200, 50);
	plot_diamond(base, 300, 200, 150);
	
		
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

}