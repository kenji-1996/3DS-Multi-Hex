# 3DS-Multi-Hex
An OOP C++ Project for the 3DS, to allow for easy addition of menu items

# About
3DS Multi Hex is a projec tI am making for easy menu customization through objects for minimal coding input. It will be used in this project for loading json files and using their values to build menus.

# Features
* Object Orientated (No hard coding!)
  * Easy to add new items or menus! (a few lines in slateManager.cpp)
* Visual Menu (Using xerp's libs! thanks dude!)
  * Customizable item and banner color (or random)
* Fire Emblem difficulty editor (The first and the example of whats possible.

# New menu example
`slate* home = new slate;`

`home->setName = "Easy Menu Builder";`

`	home->setDescription = "Creating an easy way to menu build with the 3DS, use objects!";`

`	home->banner_r = 30;`

`	home->banner_g = 144;`

`	home->banner_b = 255;`

`	home->focused = 1;`

`	//Building items for home`

`	selectFireEmblem* fireEmblemItem = new selectFireEmblem;`

`	fireEmblemItem->setName = "Fire Emblem";`

`	fireEmblemItem->setDescription = "Fire Emblem:Awakening difficulty modifier";`

`	home->items.push_back(fireEmblemItem);`

`	changeBannerColor* testOption = new changeBannerColor;`

` testOption->setName = "Randomize banner color!";`

`	testOption->setDescription = "An option to show how the system fully works,\nby randomizing this slates banner color :)";`

`	home->items.push_back(testOption);`

`	home->item_count = home->items.size();`

`	//Finished building and adding items`

`	slates.push_back(home);`

`	//Finished 'home' slate useage and adding`
