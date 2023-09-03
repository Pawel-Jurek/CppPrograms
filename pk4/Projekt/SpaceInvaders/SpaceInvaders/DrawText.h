#pragma once
#include "SFML/Graphics.hpp"

inline void drawText(int x, int y, int charSize, std::string text, sf::RenderWindow& window, sf::Font& font, sf::Color color = sf::Color::White, bool setOrigin = true)
{
	sf::Text toDraw;
	std::wstring widestr = std::wstring(text.begin(), text.end());
	toDraw.setFont(font);
	toDraw.setFillColor(color);
	toDraw.setString(text);
	toDraw.setCharacterSize(charSize);
	if(setOrigin)
		toDraw.setOrigin(toDraw.getLocalBounds().width / 2, toDraw.getLocalBounds().height / 2);
	toDraw.setPosition(x, y);
	window.draw(toDraw);
}