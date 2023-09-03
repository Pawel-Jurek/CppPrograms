#include "GlobalDefines.h"
#include "DrawText.h"
#include <filesystem>
#include <iostream>

#pragma once
#include <SFML/Graphics.hpp>

constexpr int items = 4;

using namespace sf;
class Menu
{
public:
	Menu();
	~Menu() = default;

	void draw(RenderWindow& window);
	void MoveUp();
	void MoveDown();
	int GetPressedIndex() { return selectedItemIndex; }

private:
	int selectedItemIndex;
	Font font;
	Text menu[items];
	Text info1{ "Select an option using arrows [up, down]", font, 20 };
	Text info2{ "Confirm by pressing Enter", font, 20 };

};