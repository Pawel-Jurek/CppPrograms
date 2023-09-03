#include "SFML/Graphics.hpp"
#include <string>


export module DrawText;

export void drawText(short i_x, short i_y, const std::string& i_text, sf::RenderWindow& i_window, const sf::Font& i_font)
{
	sf::Text text;
	text.setFont(i_font);
	text.setString(i_text);
	text.setPosition(i_x, i_y);
	i_window.draw(text);
}