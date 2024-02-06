void vertical_line(UCHAR8 *base, int x, int y_start, int height){

	int i;
  
	for(i = 0; i < height; i++){

		*(base + (y_start + i) * 80 + (x >> 3)) |= 1 << 7 -((x & 7));

	}
	
}

void plot_bitmap_32(ULONG32 *base, int x, int y, const ULONG32 *bitmap, unsigned int height)
{
	
	int i;

	ULONG32 *plot = (base + ((y + i) * 20 ) + (x / 32));  //Want to change the divide to a shift for performance
	
    	
	for (i = 0; i < height; i++) 
	{        

            *plot |= bitmap[I];
			      plot += 20;
	}
        
    
}	
	
void plot_bitmap_16(UINT16 *base, int x, int y, const UINT16 *bitmap, unsigned int height) //Edit to match 32 bit for speed
{

	int i = 0;
	
	for (i = 0; i < height; i++) 
	{        

            *(base + ((y + i) * 40 ) + (x / 16))  = bitmap[i];
    
  }
	
	
}

void plot_bitmap_8(UCHAR8 *base, int x, int y, const UCHAR8 *bitmap, unsigned int height) //Edit to match 32 bit for speed
{

	int i = 0;
	
	for (i = 0; i < height; i++) 
	{        

            *(base + ((y + i) * 80 ) +  (x / 80) )  = bitmap[i];
    
    }
	
	
}
