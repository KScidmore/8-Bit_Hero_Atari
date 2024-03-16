#include <osbind.h>
#include "types.h"
#include "model.h"
#include "renderer.h"
#include "rast_asm.h"

int main()
{
    UINT8 *base = Physbase();
	UINT32 *base32 = Physbase();

    Model model;

    init_model(&model);

    clear_screen(base);
    render_start_score(base32, &model);
    render_fretboard(base);
    render_frets(base32, &model);
    render_start_multiplier(base32, &model);
    render_x(base32, &model);
    render_failbar(base32, &model);

    return 0;
    
}