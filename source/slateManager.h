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
	void changeSlateByID(std::string id);
	void randomizeBanner();
	int returnSlate();
	void resetItemIndex();
	bool returnSlateFromID(std::string id);
};
extern slateManager *cSlateManager;
extern msgbox *newMsg;