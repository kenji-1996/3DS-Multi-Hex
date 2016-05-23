#include "Includes.h"

slateManager *cSlateManager = NULL;

	//Functions
	void slateManager::generateSlates() {
		//Creating 'home' slate - ID is 1
		slate* home = new slate;
		home->setName = "Easy Menu Builder";
		home->setDescription = "Creating an easy way to menu build with the 3DS, use objects!";
		home->banner_r = 30;
		home->banner_g = 144;
		home->banner_b = 255;
		home->focused = 1;
		//Building items for home
		selectFireEmblem* fireEmblemItem = new selectFireEmblem;
		fireEmblemItem->setName = "Fire Emblem";
		fireEmblemItem->setDescription = "Fire Emblem:Awakening difficulty modifier";
		fireEmblemItem->selected = 1;
		home->items.push_back(fireEmblemItem);
		changeBannerColor* testOption = new changeBannerColor;
		testOption->setName = "Randomize banner color!";
		testOption->setDescription = "An option to show how the system fully works,\nby randomizing this slates banner color :)";
		home->items.push_back(testOption);
		home->item_count = home->items.size();
		//Finished building and adding items
		slates.push_back(home);

		//Finished 'home' slate useage and adding

		//Creating 'Fire Emblem' slate - ID is 2
		slate* fireEmblem = new slate;
		fireEmblem->setName = "Fire Emblem:Awakening - Difficulty Modifier";
		fireEmblem->setDescription = "Edits the difficulty of the (first?) save file in FE:A";
		fireEmblem->banner_r = 178;
		fireEmblem->banner_g = 34;
		fireEmblem->banner_b = 34;
		//Building items for FE:A
		fireEmblemNormal* normalDiffItem = new fireEmblemNormal;
		normalDiffItem->setName = "Normal Difficulty";
		normalDiffItem->setDescription = "Sets your save game to normal difficulty";
		normalDiffItem->selected = 1;
		fireEmblem->items.push_back(normalDiffItem);
		fireEmblemHard* hardDiffItem = new fireEmblemHard;
		hardDiffItem->setName = "Hard Difficulty";
		hardDiffItem->setDescription = "Sets your save game to hard difficulty";
		hardDiffItem->selected = 0;
		fireEmblem->items.push_back(hardDiffItem);
		fireEmblemLunatic* lunaticDiffItem = new fireEmblemLunatic;
		lunaticDiffItem->setName = "Lunatic Difficulty";
		lunaticDiffItem->setDescription = "Sets your save game to lunatic difficulty";
		lunaticDiffItem->selected = 0;
		fireEmblem->items.push_back(lunaticDiffItem);
		fireEmblemLunaticP* lunaticPDiffItem = new fireEmblemLunaticP;
		lunaticPDiffItem->setName = "Lunatic+ Difficulty";
		lunaticPDiffItem->setDescription = "Sets your save game to lunatic+ difficulty";
		lunaticPDiffItem->selected = 0;
		fireEmblem->items.push_back(lunaticPDiffItem);
		selectHome* homeItem = new selectHome;
		homeItem->setName = "Back to main menu";
		homeItem->setDescription = "Goes back to the main menu";
		homeItem->selected = 0;
		fireEmblem->items.push_back(homeItem);
		slates.push_back(fireEmblem);


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