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
Now loads from text files inside SD card located at:
```
sd\3DSMH\
```
To add a new item, open 'home.txt' and 
_Game Name_|_Description for menu_|_Unique id_
And to add a game cheat
_Name of cheat_|_Description of cheat_|/JKSV/Saves/_Location of save file_|_Pointer_|_Value_

An example of this with Fire Emblem:Awakening
```
Fire Emblem:Awakening|Save file cheats for Fire Emblem:Awakening|FEA1
Set Normal DIfficulty|Sets your save game to normal difficulty|/JKSV/Saves/Fire_Emblem__Awakening/hack/Chapter0|0x0D|0x00
```
**Notice it uses the same unique id, you MUST have the same unique id you set for the game!**
