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
	newMsg = new msgbox();
	//generates and loops the slate objects!
	cSlateManager->generateSlates();
	cSlateManager->generateStrings();
	cSlateManager->generateIndex();
	//Sets the starting slate
	cSlateManager->changeSlate(1);
	
	
	//Main 3DS Loop (for buttons or printing)
    while (aptMainLoop()) {
		hidScanInput();

		//Exit!
        if (hidKeysDown() & KEY_START) break;

		//Print menu with items
		cSlateManager->printSlates(font);
		//Handle user input to change item selection
		cSlateManager->userInput();
		
    }

	//Cleanup shit
	sftd_free_font(font);
	sftd_fini();
	sf2d_fini();
    return 0;
}

