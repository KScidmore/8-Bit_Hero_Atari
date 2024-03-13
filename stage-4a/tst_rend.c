#include <osbind.h>
#include "types.h"
#include "model.h"
#include "renderer.h"

int main()
{
    UINT8 *base = Physbase();
	UINT32 *base32 = Physbase();

    Model model;

    init_model(&model);

    render_fretboard(base);
    render_frets(base32, &model);
    render_multiplier(base32, &model);

    return 0;
    
}