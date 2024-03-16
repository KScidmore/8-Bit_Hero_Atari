#ifndef INPUTS_H
#define INPUTS_H

#define RX_DISABLE ((UINT8)0x16)
#define RX_ENABLE ((UINT8)0x96)
#define FULL ((UINT8)0x01)
#define MAKE_MASK ((UINT8)0x80)
#define TIMEOUT_VALUE ((UINT16)1000)


/*Needed make/break values for inputs*/
#define ESC_MAKE ((SCANCODE)0x01)
#define ESC_BREAK ((SCANCODE)0x81)
#define A_MAKE ((SCANCODE)0x1E)
#define A_BREAK((SCANCODE)0x9E)
#define S_MAKE ((SCANCODE)0x1F)
#define S_BREAK((SCANCODE)0x9F)
#define D_MAKE ((SCANCODE)0x20)
#define D_BREAK((SCANCODE)0xA0)
#define F_MAKE ((SCANCODE)0x21)
#define F_BREAK((SCANCODE)0xA1)


/*IKBD Address'*/
#define CONTROL ((UINT32)0xFFFC00)
#define STATUS ((UINT32)0xFFFC00)
#define RDR ((UINT32)0xFFFC02)




SCANCODE read_scancode();



#endif