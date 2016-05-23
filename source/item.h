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
		
		//Functions
		void printItem(int y, sftd_font *font) {
			name = setName.c_str();
			if(selected == 1) {
				sftd_draw_textf(font, 10, y, RGBA8(text_r, text_g, text_b, 255), 15, ">");
				sftd_draw_textf(font, 20, y, RGBA8(text_r, text_g, text_b, 255), 15, name);
			}else{
				sftd_draw_textf(font, 10, y, RGBA8(text_r, text_g, text_b, 255), 15, name);
			}
			
		}
		
		void generateStrings() {
			name = setName.c_str();
			description = setDescription.c_str();
		}
		
		virtual void onSelect()  {
			//cSlateManager->changeSlate(1);
			//Change slate?
		}
};

class changeBannerColor : public item {
public:
	void onSelect() {
		cSlateManager->randomizeBanner();
		//Change slate?
	}
};

class selectFireEmblem : public item {
	public:
		void onSelect() {
			cSlateManager->changeSlate(2);
		}
};

class selectHome : public item {
	public:
		void onSelect() {
			cSlateManager->changeSlate(1);
		}
};

class fireEmblemNormal: public item {
	public:
		void onSelect() {
			std::fstream ofs("/JKSV/Saves/Fire_Emblem__Awakening/hack/Chapter0", std::ios::in | std::ios::out | std::ios::binary);
			ofs.seekp(0x0D);
			ofs << char(0x00);
			ofs.close();
		}
};

class fireEmblemHard: public item {
	public:
		void onSelect() {
			std::fstream ofs("/JKSV/Saves/Fire_Emblem__Awakening/hack/Chapter0", std::ios::in | std::ios::out | std::ios::binary);
			ofs.seekp(0x0D);
			ofs << char(0x01);
			ofs.close();
		}
};

class fireEmblemLunatic: public item {
	public:
		void onSelect() {
			std::fstream ofs("/JKSV/Saves/Fire_Emblem__Awakening/hack/Chapter0", std::ios::in | std::ios::out | std::ios::binary);
			ofs.seekp(0x0D);
			ofs << char(0x02);
			ofs.close();
		}
};

class fireEmblemLunaticP : public item {
public:
	void onSelect() {
		std::fstream ofs("/JKSV/Saves/Fire_Emblem__Awakening/hack/Chapter0", std::ios::in | std::ios::out | std::ios::binary);
		ofs.seekp(0x0D);
		ofs << char(0x03);
		ofs.close();
	}
};

