#pragma once
#include "Includes.h"

class item
{
public:
	//Variables
	std::string location;//"/JKSV/Saves/Fire_Emblem__Awakening/hack/Chapter0"
	int pointer;
	int value;


	void updateValue() {
		std::fstream ofs(location, std::ios::in | std::ios::out | std::ios::binary);
		ofs.seekp(pointer);
		ofs << char(value);
		ofs.close();
	}
};
