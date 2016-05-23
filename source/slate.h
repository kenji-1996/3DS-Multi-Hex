#pragma once
#include "Includes.h"

class slate
{
	public:
		//Variables
		std::string setName;
		std::string setDescription;
		const char *name;
		const char *description;
		int banner_r = 0;
		int banner_g = 0;
		int banner_b = 0;
		int focused = 0;//If focused, it is printing
		int index = 0;
		int item_count = 0;
		int item_index = 0;
		std::list<item*> items;
		
		
		//Functions		
		void generateStrings() {
			int itemIndex = 0;
			for(std::list<item*>::iterator iter = items.begin(); iter != items.end(); ++iter)
			{
				(*iter)->index = itemIndex;
				itemIndex++;
			}
			item_count = itemIndex;
			name = setName.c_str();
			description = setDescription.c_str();
		}
		
		//prints menu item
		void printMenu(sftd_font *font) {
			if(focused == 1) {
				sf2d_start_frame(GFX_TOP, GFX_LEFT);
				
					sf2d_draw_rectangle(0, 0, 420, 18, RGBA8(banner_r, banner_g, banner_b, 255));
					sftd_draw_textf(font, 2, 0, RGBA8(255, 255, 255, 255), 15, name);
					int start = 19;
					for(std::list<item*>::iterator iter = items.begin(); iter != items.end(); ++iter)
					{
						(*iter)->generateStrings();
						(*iter)->printItem(start,font);
						start+=17;
					}
				sf2d_end_frame();
				
				//Print description on screen
				sf2d_start_frame(GFX_BOTTOM, GFX_LEFT);
				
					for(std::list<item*>::iterator iter = items.begin(); iter != items.end(); ++iter)
					{
						if((*iter)->selected == 1) {
							sftd_draw_textf(font, 2, 0, RGBA8(255, 255, 255, 255), 15, (*iter)->description);
						}
					}
				sf2d_end_frame();
				
				sf2d_swapbuffers();	
			}
		}
		
		void userInput() {
			if(focused == 1) {
				if (hidKeysDown() & KEY_DOWN) {
					if(item_index != (item_count - 1)) {
						item_index++;
					}
					clearSelectedItem();
					for(std::list<item*>::iterator iter = items.begin(); iter != items.end(); ++iter)
					{
						if(item_index == (*iter)->index) {
							(*iter)->selected = 1;
						}
					}
				}//Press down end
				
				if (hidKeysDown() & KEY_UP) {
					if(item_index != 0) {
						item_index--;
					}
					clearSelectedItem();
					for(std::list<item*>::iterator iter = items.begin(); iter != items.end(); ++iter)
					{
						if(item_index == (*iter)->index) {
							(*iter)->selected = 1;
						}
					}
				}//Press up end
				
				if(hidKeysDown() & KEY_A) {
					for(std::list<item*>::iterator iter = items.begin(); iter != items.end(); ++iter)
					{
						if(item_index == (*iter)->index) {
							(*iter)->onSelect();
						}
					}
				}//Press A end	
				if (hidKeysDown() & KEY_B) {
					if (cSlateManager->returnSlate() != 1) {
						cSlateManager->changeSlate(1);
					}
				}
			}
		}
		
		void clearSelectedItem() {
			for(std::list<item*>::iterator iter = items.begin(); iter != items.end(); ++iter)
			{
				(*iter)->selected = 0;
			}
		}
};