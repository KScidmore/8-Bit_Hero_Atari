#include <osbind.h>
#include "types.h"
#include "model.h"
#include "renderer.h"
#include "rast_asm.h"
#include "events.h"

int main()
{
    UINT8 *base = Physbase();
	UINT32 *base32 = Physbase();
    int i;
    Model model;

    init_model(&model);

    init_scene(base, base32, &model);

    /*Generate 4 notes*/
    for(i = 0; i < 4; i++){

        model.lanes[i].notes[i].is_active = TRUE;
    }

    /*rerender notes in new positions*/
    for(i = 0; i < 4; i++){

        render_next(base32, &model);

    }

    return 0;
    
}