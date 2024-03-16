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

    init_scene(base, base32, &model);

    return 0;
    
}