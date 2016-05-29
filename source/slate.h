#pragma once
#include "Includes.h"

class slate
{
	public:
		//Variables
		std::string setName;
		const char *name;
		int banner_r = 0;
		int banner_g = 0;
		int banner_b = 0;
		int focused = 0;//If focused, it is printing
		int index = 0;
		int item_count = 0;
		int item_index = 0;
		std::string id = "";

		//Pages shit
		int page_Index = 0;
		int page_Count = 0;
		//page *pages;
		std::list<page*> pages;
		std::list<item*> items;//Max for a page = 12
		
		
		//Functions		
		void generateStrings() {
			//Set item indexes
			int itemIndex = 0;
			for (std::list<item*>::iterator iter = items.begin(); iter != items.end(); ++iter)
			{
				(*iter)->index = itemIndex;
				itemIndex++;
			}
			item_count = itemIndex;
			//End

			//Getting page count
			int itemC = 0;
			page *temp = new page;
			pages.push_back(temp);
			for (std::list<item*>::iterator iter = items.begin(); iter != items.end(); ++iter) {
				itemC++;
				if (itemC > 12) {
					page *temp1 = new page;
					temp1->id = id;
					pages.push_back(temp1);
					page_Count++;
					itemC = 0;
				}
			}
			//End

			//Grouping items into 12 for pages
			std::vector<int> data;
			for (std::list<page*>::iterator iter = pages.begin(); iter != pages.end(); ++iter) {
				int start = 0;
				for (std::list<item*>::iterator iiter = items.begin(); iiter != items.end(); ++iiter) {
					if (start > 11) {
						break;
					}
					if (!(std::find(data.begin(), data.end(), ((*iiter))->index) != data.end())) {
						(*iter)->items.push_back((*iiter));
						data.push_back((*iiter)->index);
						start++;
					}
				}
			}
			//End

			//Getting the page index
			int pageIndex = 0;
			for (std::list<page*>::iterator iter = pages.begin(); iter != pages.end(); iter++) {
				(*iter)->index = pageIndex;
				if ((*iter)->index == 0) {
					(*iter)->focused = 1;
				}
				pageIndex++;
			}
			name = setName.c_str();
		}
		
		//prints menu item
		void printMenu(sftd_font *font) {

			if (focused == 1) {
				sf2d_start_frame(GFX_TOP, GFX_LEFT);

					sf2d_draw_rectangle(0, 0, 420, 18, RGBA8(banner_r, banner_g, banner_b, 255));
					sf2d_draw_rectangle(0, 224, 420, 240, RGBA8(banner_r, banner_g, banner_b, 255));
					sftd_draw_textf(font, 2, 0, RGBA8(255, 255, 255, 255), 15, name);
					sftd_draw_textf(font, 2, 222, RGBA8(255, 255, 255, 255), 15, "Page %i of %i",(page_Index + 1),(page_Count + 1));
					for (std::list<page*>::iterator iter = pages.begin(); iter != pages.end(); iter++) {
						if ((*iter)->focused == 1) {
							(*iter)->printPage(font);
						}
					}
					newMsg->printMsgBox(font);
				
				sf2d_end_frame();

				

				//Print description on screen
				sf2d_start_frame(GFX_BOTTOM, GFX_LEFT);

					for (std::list<item*>::iterator iter = items.begin(); iter != items.end(); ++iter)
					{
						if ((*iter)->selected == 1) {
							sftd_draw_textf(font, 2, 0, RGBA8(255, 255, 255, 255), 15, (*iter)->description);
						}
					}

				sf2d_end_frame();
				sf2d_swapbuffers();
			}
		}
		
		void userInput() {
			if (newMsg->focused == 1) {
				if (hidKeysDown() & KEY_Y) {
					newMsg->focused = 0;
					item_index = 0;
				}
			}
			if (hidKeysDown() & KEY_RIGHT) {
				if (page_Index != page_Count) {
					page_Index++;
				}
				clearCurrentPage();
				for (std::list<page*>::iterator iter = pages.begin(); iter != pages.end(); iter++) {
					if (page_Index == (*iter)->index) {
						(*iter)->focused = 1;
					}
				}
			}
			if (hidKeysDown() & KEY_LEFT) {
				if (page_Index != 0) {
					page_Index--;
				}
				clearCurrentPage();
				for (std::list<page*>::iterator iter = pages.begin(); iter != pages.end(); iter++) {
					if (page_Index == (*iter)->index) {
						(*iter)->focused = 1;
					}
				}
			}
			for (std::list<page*>::iterator iter = pages.begin(); iter != pages.end(); iter++) {
				if (focused == 1) {
					if ((*iter)->focused == 1) {
						(*iter)->pageControl();
					}
				}
			}
		}

		void clearCurrentPage() {
			for (std::list<page*>::iterator iter = pages.begin(); iter != pages.end(); iter++) {
				(*iter)->focused = 0;
			}
		}
};