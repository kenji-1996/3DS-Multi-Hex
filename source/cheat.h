#pragma once
#include "Includes.h"

class cheat
{
public:
	//Variables
	std::string location;//"/JKSV/Saves/Fire_Emblem__Awakening/hack/Chapter0"
	std::string pointer;
	std::string value;
	std::string id;

	void updateValue() {
		std::fstream ofs(location, std::ios::in | std::ios::out | std::ios::binary);
		unsigned long pointer_hex = std::strtoul(pointer.c_str(), 0, 16);
		ofs.seekp(pointer_hex);
		unsigned long value_hex = std::strtoul(value.c_str(), 0, 16);
		ofs << char(value_hex);
		ofs.close();
	}
};
