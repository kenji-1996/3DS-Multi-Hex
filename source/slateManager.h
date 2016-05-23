#pragma once
#include "Includes.h"

class slateManager
{
public:
	//Variables
	std::list<slate*> slates;

	//Functions
	void generateSlates();
	void generateStrings();
	void printSlates(sftd_font *font);
	void userInput();
	void generateIndex();
	void changeSlate(int slate_index);
	void randomizeBanner();
};
extern slateManager *cSlateManager;