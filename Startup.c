/*
Startup.c by Abdelrahman Kamal >> Learn-in-Depth
*/

#include <stdint.h>
typedef volatile uint32_t vuint32_t;
typedef volatile unsigned long vuint64_t;

void Reset_Handler();
void NMI_Handler() __attribute__((weak, alias("Default_Handler")));
void Bus_Fault() __attribute__((weak, alias("Default_Handler")));
extern int main();

void Default_Handler(void) {
	Reset_Handler();
}

/* Reserve the stack size through reserving a static global array
to be stored in the (.bss) section and to make sure that it will be 
a strong symbol so it will not be overridden and to be only used in 
this source file */

static vuint64_t Stack_top[256];

void (* const g_p_fn_Vectors[])() __attribute__ ((section(".vectors"))) = {
(void (*) ()) (Stack_top + sizeof(Stack_top)) ,
&Reset_Handler,
&NMI_Handler,
&Bus_Fault

};

extern unsigned int _E_TEXT;
extern unsigned int _S_DATA;
extern unsigned int _E_DATA;
extern unsigned int _S_BSS;
extern unsigned int _E_BSS;

void Reset_Handler (void) {

	/* Copy .data segment from flash to ram */
	unsigned int DATA_SIZE = (unsigned char*)&_E_DATA - (unsigned char*)&_S_DATA;
	unsigned char* P_src = (unsigned char*)&_E_TEXT;
	unsigned char* P_dst = (unsigned char*)&_S_DATA;
	for (int i = 0; i < DATA_SIZE; i++) {
		*((unsigned char*)P_dst) = *((unsigned char*)P_src++);
	}

	/* Initialize the .bss segment by zeros*/
	unsigned int BSS_SIZE = (unsigned char*)&_S_BSS - (unsigned char*)&_E_BSS;
	P_dst = (unsigned char*)&_S_BSS;
	for (int i = 0; i < BSS_SIZE; i++) {
		*((unsigned char*)P_dst++) = (unsigned char)0;
	}

	main();
}