#include <osbind.h>
#include "raster.h"
#include "model.h"
#include "bitmaps.h"
#include "types.h"
#include "renderer.h"

int main()
{
    unsigned char *base = Physbase();
	unsigned long *base32 = Physbase();

    Model model;

    init_model(&model);

    render_fretboard(base);
    render_frets(base32, &model);
    render_multiplier(base32, &model);

    return 0;
    
}