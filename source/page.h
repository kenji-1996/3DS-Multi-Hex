#pragma once
#include "Includes.h"

class page
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
	std::string id;

	//prints menu item
	void printPage(sftd_font *font) {
		int start = 19;
		for (std::list<item*>::iterator iter = items.begin(); iter != items.end(); ++iter)
		{
			(*iter)->generateStrings();
			(*iter)->printItem(start, font);
			start += 17;
		}
	}

	void pageControl() {
		if (focused == 1) {
			if (hidKeysDown() & KEY_DOWN) {
				if (item_index != (item_count - 1)) {
					item_index++;
				}
				clearSelectedItem();
				setSelectedItem();
			}//Press down end

			if (hidKeysDown() & KEY_UP) {
				if (item_index != 0) {
					item_index--;
				}
				clearSelectedItem();
				setSelectedItem();
			}//Press up end

			if (hidKeysUp() & KEY_A) {
				for (std::list<item*>::iterator iter = items.begin(); iter != items.end(); ++iter)
				{
					
					if (item_index == (*iter)->index) {
						(*iter)->onSelect();
						cSlateManager->resetItemIndex();
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
		for (std::list<item*>::iterator iter = items.begin(); iter != items.end(); ++iter)
		{
			(*iter)->selected = 0;
		}
	}

	void setSelectedItem() {
		for (std::list<item*>::iterator iter = items.begin(); iter != items.end(); ++iter)
		{
			if (item_index == (*iter)->index) {
				(*iter)->selected = 1;
			}
		}
	}

};