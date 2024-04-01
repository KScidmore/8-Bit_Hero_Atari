#ifndef EBH_H
#define EBH_H

void game_loop();
void set_buffer(UINT32** front_buffer, UINT32** back_buffer, UINT8 buffer_array[]);
void take_snapshot(Model *model, Model *snapshot);
void swap_buffer(UINT32* front_buffer, UINT32* back_buffer, UINT32** curr_buffer);
UINT32 get_time();


#endif