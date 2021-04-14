// #include "Intellisense.h"


// int main()
// {
// 	//set GBA rendering context to MODE 3 Bitmap Rendering
// 	*(unsigned int*)0x04000000 = 0x0403;

// 	int t = 0;
// 	while(1){
// 		int x,y;
// 		for(x = 0; x < 240; ++x){
// 			for( y = 0; y < 160; ++y){
// 				((unsigned short*)0x06000000)[x+y*240] = ((((x&y)+t) & 0x1F) << 10)|
// 				((((x&y)+t*3)&0x1F)<<5) | ((((x&y)+t * 5)&0x1F)<<0);
// 			}
// 		}
// 		t=t+30;
// 	}
// 	return 0;
// }


#include <gba_console.h>
#include <gba_video.h>
#include <gba_interrupt.h>
#include <gba_systemcalls.h>
#include <gba_input.h>
#include <stdio.h>
#include <stdlib.h>

//---------------------------------------------------------------------------------
// Program entry point
//---------------------------------------------------------------------------------
int main(void) {
//---------------------------------------------------------------------------------


	// the vblank interrupt must be enabled for VBlankIntrWait() to work
	// since the default dispatcher handles the bios flags no vblank handler
	// is required
	irqInit();
	irqEnable(IRQ_VBLANK);

	consoleDemoInit();

	// ansi escape sequence to set print co-ordinates
	// /x1b[line;columnH
	iprintf("\x1b[10;10HHello World!\n");

	while (1) {
		VBlankIntrWait();
	}
}


