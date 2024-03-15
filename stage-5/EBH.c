#include <osbind.h>
#include <stdio.h>
#include "types.h"
#include "model.h"
#include "renderer.h"
#include "rast_asm.h"


int main()
{
    
    UINT32 time_then, time_now, time_elapsed;
    UINT8 *base = Physbase();
	UINT32 *base_long = Physbase();

    Model model;

    init_model(&model);

    initalize_screen(base, base_long, &model);

    time_then = get_time();

    /*Main game loop*/

    while(1){

        /*Async Events*/


        /*Sync Events*/

        

    }



    return 0;
    
}

UINT32 get_time(){

	UINT32 time_now;
	UINT32 old_ssp;
	UINT32 *timer = (UINT32 *)0x462;
	
	old_ssp = Super(0); 
	time_now = *timer;
	Super(old_ssp); 
	
	return time_now;
	
}