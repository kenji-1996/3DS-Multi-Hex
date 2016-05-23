#pragma once
#include "Includes.h"

class msgbox
{
public:
	//Variables
	std::string setTitle;
	std::string setInfo;
	const char *title;
	const char *info;
	int box_r = 255;
	int box_g = 255;
	int box_b = 255;
	int banner_r = 112;
	int banner_g = 128;
	int banner_b = 144;
	int focused = 0;//If focused, it is printing
	int previous_slate;

	void printMsgBox(sftd_font *font) {
		if (focused == 1) {
			sf2d_draw_rectangle(0, 0, 420, 240, RGBA8(box_r, box_g, box_b, 255));
			sf2d_draw_rectangle(0, 0, 420, 18, RGBA8(banner_r, banner_g, banner_b, 255));
			sftd_draw_textf(font, 1, 0, RGBA8(0, 0, 0, 255), 15, title);
			sftd_draw_textf(font, 1, 19, RGBA8(0, 0, 0, 255), 15, info);
			sftd_draw_textf(font, 1, 220, RGBA8(0, 0, 0, 255), 15, "Press 'B' to close!");
			//sftd_draw_textf(font, 0, 0, RGBA8(80, 255, 35, 255), 15, "LMAO");
			//sf2d_draw_rectangle(10, 10, 380, 220, RGBA8(box_r, box_g, box_b, 255));
			
			
		}
	}
};