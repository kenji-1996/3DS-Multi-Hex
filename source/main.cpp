#include "Main.h"
int main()
{
	//Drawing shit
	sf2d_init();
	sf2d_set_clear_color(RGBA8(0x40, 0x40, 0x40, 0xFF));
	sf2d_set_vblank_wait(0);
	sftd_init();
	sftd_font *font = sftd_load_font_mem(FreeSans_ttf, FreeSans_ttf_size);
	
	cSlateManager = new slateManager();
	//generates and loops the slate objects!
	cSlateManager->generateSlates();
	cSlateManager->generateStrings();
	cSlateManager->generateIndex();
	
	
	//Main 3DS Loop (for buttons!)
    while (aptMainLoop()) {
		hidScanInput();
		//Exit!
        if (hidKeysDown() & KEY_START) break;

		cSlateManager->printSlates(font);
		cSlateManager->userInput();
		
    }

	//Cleanup shit
	sftd_free_font(font);
	sftd_fini();
	sf2d_fini();
    return 0;
}

