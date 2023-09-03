#pragma once
#include <utility>
#include <vector>
#include <string>
#include "SFML/Graphics.hpp"
#include <regex>
#include <iostream>
#include "DrawText.h"
#include "GlobalDefines.h"
#include <sstream>
#include <fstream>


class Highscore
{
private:
	std::vector <std::pair<std::string, int>> playersScore;
	std::regex nameTemplate;
	const std::string addingNameInfo = "Enter a nickname: ";
	const std::string requirements = "Your nickname must contain (3,15) LETTERS";
	const std::string confirmInfo = "Press ENTER to continue";
	sf::String playerInput;
	sf::Text playerText;
	std::pair<std::string, int> newScore;
	sf::Color color = sf::Color::White;
	float typingTimer;
	bool spottedDoubleLetter;

public:
	Highscore();
	~Highscore() = default;
	void addPlayer(sf::RenderWindow& window,int score, float height, sf::Font& font, sf::Event &event, std::string fileName);
	void draw(sf::RenderWindow &window, sf::Font &font, sf::Event& event, std::string fileName, sf::Sprite backgroud, bool newResult = false);
	bool checkNameCorrection(std::string playerName);
	void updateFile(std::string fileName);
	void readFile(std::string fileName);
	void sortPlayers();
	inline std::vector <std::pair<std::string, int>> getPlayers() { return playersScore; }
	std::string fillText(std::string text, int newLenght);
};

