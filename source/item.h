#pragma once
#include "Includes.h"

class item
{
	public:
		//Variables
		std::string setName;
		std::string setDescription;
		const char *name;
		const char *description;
		int text_r = 255;
		int text_g = 255;
		int text_b = 255;
		int selected = 0;//0 - Not selected; 1 - Selected
		int index = 0;
		std::list<cheat*> cheatList;
		int cheatBool = 0;
		std::string pointer;
		std::string value;
		//long pointer;
		//long value;
		std::string slate_id;
		std::string save_location;
		
		//Functions
		void printItem(int y, sftd_font *font) {
			name = setName.c_str();
			if(selected == 1) {
				sftd_draw_textf(font, 8, y - 2, RGBA8(text_r, text_g, text_b, 200), 15, ">");
				sftd_draw_textf(font, 18, y, RGBA8(text_r, text_g, text_b, 255), 15, name);
			}else{
				sftd_draw_textf(font, 10, y, RGBA8(text_r, text_g, text_b, 255), 15,name);
			}
			
		}
		
		void generateStrings() {
			name = setName.c_str();
			description = setDescription.c_str();
		}
		
		virtual void onSelect() {
			if (selected == 1) {
				if (cheatBool == 0) {
					cSlateManager->changeSlateByID(slate_id);
				} else {
					int total = 0;
					for (std::list<cheat*>::iterator iter = cheatList.begin(); iter != cheatList.end(); ++iter) {
						total++;
					}
					int i = 0;
					for (std::list<cheat*>::iterator iter = cheatList.begin(); iter != cheatList.end(); ++iter) {
						if ((*iter)->location != "") {
							(*iter)->updateValue();
						}
						i++;
						if (i == total) {
							newMsg->setTitle = "Cheat status";
							newMsg->title = newMsg->setTitle.c_str();
							std::string msgS = setName + " has gone into effect\nafter modifying ";
							std::stringstream sstm;
							sstm << msgS << total << " values.";
							std::string result = sstm.str();
							newMsg->setInfo = result;
							newMsg->info = newMsg->setInfo.c_str();
							newMsg->focused = 1;
						}						
					}
				}
			}
		}
};

class changeBannerColor : public item {
	public:
		void onSelect() {
			cSlateManager->randomizeBanner();
		}
};

class showMsgBox : public item {
public:
	void onSelect() {
		newMsg->setTitle = "3DS Multi-Hex user guide";
		newMsg->title = newMsg->setTitle.c_str();                                       //
		newMsg->setInfo = "3DS Multi-Hex is a WIP by Kenji(Metab), it is designed to be \neasily used and easily edited, to add or remove items \nwithout hard coding\nA - Selects item\nB - Goes to main menu\nY - Closes message box\nStart - Closes 3DS Multi-Hex";
		newMsg->info = newMsg->setInfo.c_str();
		newMsg->focused = 1;
	}
};

