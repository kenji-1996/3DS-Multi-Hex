#include "Includes.h"

slateManager *cSlateManager = NULL;
msgbox *newMsg = NULL;

	std::vector<std::string> split(std::string str, char delimiter) {
		std::vector<std::string> internal;
		std::stringstream ss(str); // Turn the string into a stream.
		std::string tok;

		while (std::getline(ss, tok, delimiter)) {
			internal.push_back(tok);
		}
		return internal;
	}

	//Functions
	void slateManager::generateSlates(sftd_font *font) {
		//Setting up home
		slate* home = new slate;
		home->setName = "3DS Multi-Hex";
		home->banner_r = 30;
		home->banner_g = 144;
		home->banner_b = 255;
		home->id = "home";
		slates.push_back(home);
		std::vector<std::string> slate_info;

		//Loading files
		std::ifstream myReadFile;
		myReadFile.open("/3DSMH/home.txt");
		std::vector<std::string> lines;
		for (std::string line; std::getline(myReadFile, line);)
		{
			lines.push_back(line);
		}
		for (std::vector<std::string>::iterator it = lines.begin(); it != lines.end(); ++it) {
			item* i = new item;
			std::string s = *it;
			s = s.substr(0, s.size() - 1);
			if (s != "") {
				slate_info = split(s, '|');
				//Makes a menu item for that cheat selection
				i->setName = slate_info.at(0);
				i->setDescription = slate_info.at(1);
				i->slate_id = slate_info.at(2);
				i->cheatBool = 0;
				//Generates a slate for the cheat
				slate* s = new slate;
				s->setName = slate_info.at(0);
				s->id = slate_info.at(2);
				std::ifstream readSlate;
				std::string slateLocation = "/3DSMH/" + slate_info.at(2) + ".txt";
				readSlate.open(slateLocation);
				//COnvert string to int atoi( str.c_str() );
				std::vector<std::string> slate_lines;
				for (std::string line; std::getline(readSlate, line);)
				{
					slate_lines.push_back(line);
				}
				for (std::vector<std::string>::iterator it = slate_lines.begin(); it != slate_lines.end(); ++it) {
					std::string sz = *it;
					sz = sz.substr(0, sz.size() - 1);
					if (sz != "") {
						std::vector<std::string> splitter = split(sz, '|');
						item* fileItem = new item;
						fileItem->setName = splitter.at(0);
						fileItem->setDescription = splitter.at(1);
						fileItem->save_location = splitter.at(2);
						fileItem->pointer = splitter.at(3);
						fileItem->value = splitter.at(4);
						fileItem->cheatBool = 1;
						cheat* c = new cheat;
						c->location = splitter.at(2);
						c->pointer = splitter.at(3);
						c->value = splitter.at(4);
						c->id = splitter.at(0);
						fileItem->cheatList.push_back(c);
						s->items.push_back(fileItem);
					}
				}
				std::list<cheat*> tempList;
				s->items.unique([&](const item *lhs,const item *rhs)->bool {
					cheat* c = new cheat;
					if (lhs->setName == rhs->setName) {
						c->location = rhs->save_location;
						c->pointer = rhs->pointer;
						c->value = rhs->value;
						c->id = rhs->setName;
						tempList.push_back(c);
					}
					return lhs->setName == rhs->setName;
				});
				for (std::list<cheat*>::iterator iter = tempList.begin(); iter != tempList.end(); ++iter)
				{
					for (std::list<item*>::iterator iiter = s->items.begin(); iiter != s->items.end(); ++iiter)
					{
						if ((*iiter)->setName == (*iter)->id) {
							(*iiter)->cheatList.push_back((*iter));
						}
					}
				}
				std::vector<std::string> lines;
				home->items.push_back(i);
				slates.push_back(s);
				
			}
		}

		showMsgBox* info = new showMsgBox;
		info->setName = "3DS MUlti-Hex Information";
		info->setDescription = "Information on 3DSMH";
		home->items.push_back(info);
			/* std::cout << *it; ... */
		//Building items for home
		/*selectFireEmblem* fireEmblemItem = new selectFireEmblem;
		fireEmblemItem->setName = "Fire Emblem";
		fireEmblemItem->setDescription = "Fire Emblem:Awakening difficulty modifier";
		home->items.push_back(fireEmblemItem);*/

		//Finished building and adding items
		
		//Finished 'home' slate useage and adding

		//Creating 'Fire Emblem' slate - ID is 2
		/*slate* fireEmblem = new slate;
		fireEmblem->setName = "Fire Emblem:Awakening - Difficulty Modifier";
		fireEmblem->banner_r = 178;
		fireEmblem->banner_g = 34;
		fireEmblem->banner_b = 34;

		//Building items for FE:A
		fireEmblemNormal* normalDiffItem = new fireEmblemNormal;
		normalDiffItem->setName = "Normal Difficulty";
		normalDiffItem->setDescription = "Sets your save game to normal difficulty";
		fireEmblem->items.push_back(normalDiffItem);

		fireEmblemHard* hardDiffItem = new fireEmblemHard;
		hardDiffItem->setName = "Hard Difficulty";
		hardDiffItem->setDescription = "Sets your save game to hard difficulty";
		fireEmblem->items.push_back(hardDiffItem);

		fireEmblemLunatic* lunaticDiffItem = new fireEmblemLunatic;
		lunaticDiffItem->setName = "Lunatic Difficulty";
		lunaticDiffItem->setDescription = "Sets your save game to lunatic difficulty";
		fireEmblem->items.push_back(lunaticDiffItem);

		fireEmblemLunaticP* lunaticPDiffItem = new fireEmblemLunaticP;
		lunaticPDiffItem->setName = "Lunatic+ Difficulty";
		lunaticPDiffItem->setDescription = "Sets your save game to lunatic+ difficulty";
		fireEmblem->items.push_back(lunaticPDiffItem);
		//Finished, push this slate to the slate list
		slates.push_back(fireEmblem);*/
	}

	void slateManager::generateStrings() {
		for (std::list<slate*>::iterator iter = slates.begin(); iter != slates.end(); ++iter)
		{
			(*iter)->generateStrings();
		}
	}

	void slateManager::printSlates(sftd_font *font) {
		for (std::list<slate*>::iterator iter = slates.begin(); iter != slates.end(); ++iter)
		{
			(*iter)->printMenu(font);
		}
	}

	void slateManager::userInput() {
		for (std::list<slate*>::iterator iter = slates.begin(); iter != slates.end(); ++iter)
		{
			(*iter)->userInput();
		}
	}
	
	void slateManager::generateIndex() {
		int index = 1;
		for (std::list<slate*>::iterator iter = slates.begin(); iter != slates.end(); ++iter)
		{
			(*iter)->index = index;
			index++;
		}
	}

	void slateManager::randomizeBanner() {
		int r = 0 + (rand() % (int)(255 - 0 + 1));
		int g = 0 + (rand() % (int)(255 - 0 + 1));;
		int b = 0 + (rand() % (int)(255 - 0 + 1));;
		for (std::list<slate*>::iterator iter = slates.begin(); iter != slates.end(); ++iter)
		{
			if ((*iter)->focused == 1) {
				(*iter)->banner_r = r;
				(*iter)->banner_g = g;
				(*iter)->banner_b = b;
			}
		}
	}

	void slateManager::changeSlate(int slate_index) {
		for (std::list<slate*>::iterator iter = slates.begin(); iter != slates.end(); ++iter)
		{
			(*iter)->focused = 0;
		}
		for (std::list<slate*>::iterator iter = slates.begin(); iter != slates.end(); ++iter)
		{
			if ((*iter)->index == slate_index) {
				(*iter)->focused = 1;
			}
		}
	}

	void slateManager::changeSlateByID(std::string id) {
		for (std::list<slate*>::iterator iter = slates.begin(); iter != slates.end(); ++iter)
		{
			(*iter)->focused = 0;
		}
		for (std::list<slate*>::iterator iter = slates.begin(); iter != slates.end(); ++iter)
		{
			if ((*iter)->id == id) {
				(*iter)->focused = 1;
			}
		}
	}

	int slateManager::returnSlate() {
		int returnValue = 0;
		for (std::list<slate*>::iterator iter = slates.begin(); iter != slates.end(); ++iter)
		{
			if ((*iter)->focused == 1) {
				returnValue = (*iter)->index;
			}
		}
		return returnValue;
	}

	void slateManager::resetItemIndex() {
		for (std::list<slate*>::iterator iter = slates.begin(); iter != slates.end(); ++iter)
		{
			(*iter)->item_index = -1;
		}
	}

	bool slateManager::returnSlateFromID(std::string id)
	{
		bool returnValue = false;
		for (std::list<slate*>::iterator iter = slates.begin(); iter != slates.end(); ++iter)
		{
			if ((*iter)->id == id) {
				if ((*iter)->focused) {
					returnValue = true;
				}
			}
		}
		return returnValue;
	}
