#include <osbind.h>

#include "renderer.h"

int main()
{
    UINT8 *base = (UINT8 *)Physbase();
	UINT16 *base16 = (UINT16 *)Physbase();
	UINT32 *base32 = (UINT32 *)Physbase();

    render_fretboard(base);
    render_frets(base32);
    render_multiplier(base32);
    render_score(base32);
    
}