#include <osbind.h>
#include "types.h"
#include "model.h"
#include "renderer.h"
#include "rast_asm.h"

int main()
{
    UINT8 *base = Physbase();
	UINT32 *base32 = Physbase();
    int i, j;
    Model model;

    init_model(&model);

    init_scene(base, base32, &model);

    /*Generate 4 notes*/
    for(i = 0; i < 4; i++){

        model.lanes[i].notes[i].is_active = TRUE;
    }

    /*wait, clear and rerender notes in new positions*/
    for(i = 0; i < 100; i++){
        for(j= 0; j < 10000; j++);
        render_next(base32, &model);

    }

    /*Clear and update multiplier value*/
    model.multiplier.value = 2;
    render_next(base32, &model);
    for(j= 0; j < 32500; j++);

    model.multiplier.value = 4;
    render_next(base32, &model);
    for(j= 0; j < 32500; j++);

    model.multiplier.value = 8;
    render_next(base32, &model);

    /*update fail bar*/
    model.fail_bar.value += 20;
    render_next(base32, &model);
    for(j= 0; j < 32500; j++);

    model.fail_bar.value += 20;
    render_next(base32, &model);
    for(j= 0; j < 32500; j++);

    model.fail_bar.value += 20;
    render_next(base32, &model);


    return 0;
    
}