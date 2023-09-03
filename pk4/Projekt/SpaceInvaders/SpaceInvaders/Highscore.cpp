#include "Highscore.h"

Highscore::Highscore()
{
	std::regex newNameTemplate("[[:alpha:]]{3,15}");
	nameTemplate = newNameTemplate;
	typingTimer = 0;
	spottedDoubleLetter = false;
}

// dodawanie gracza do tabeli wynik�w
void Highscore::addPlayer(sf::RenderWindow& window, int score, float height, sf::Font& font, sf::Event& event, std::string fileName)
{
	playerInput = "";
	playerText.setString(playerInput);
	color = sf::Color::White;
	while (window.pollEvent(event) || true)
	{
		if (event.type == sf::Event::Closed)
		{
			window.close();
			break;
		}
		window.clear();
		drawText(WINDOW_WIDHT / 2, height, 20, addingNameInfo, window, font);
		drawText(WINDOW_WIDHT / 2, height + 30, 20, requirements, window, font, color);

		// cz�� odpowiedzialna za wprowadzanie nicku
		if (event.type == sf::Event::TextEntered)
		{	
			// klikni�ty klawisz Enter -> sprawdzenie zgodno�ci z warunkami dobrego nicku. 
			// Je�li nie, ustaw kolor czerwony dla komunikatu zwi�zanego z wymaganiami
			if (event.text.unicode == 13)
				if (checkNameCorrection(playerText.getString()))
					break;
				else
					color = sf::Color::Red;
			//obs�uga backspace
			else if (event.text.unicode == 8 && typingTimer <= 0)
			{
				if (playerText.getString().getSize() > 0)
				{
					std::string temp = "";
					for (int i = 0; i < playerInput.getSize() - 1; i++)
						temp += playerInput[i];
					playerInput = temp;
					playerText.setString(temp);
					typingTimer = 5;
				}
			}
			//wpisywanie znak�w do nicku
			else if (typingTimer <= 0 && event.text.unicode != 8 && event.text.unicode != 13)
			{
				typingTimer = 10;
				playerInput += event.text.unicode;
				playerText.setString(playerInput);
			}
			else
				typingTimer--;
		}
		else
			typingTimer--;

		drawText(WINDOW_WIDHT / 2, height + 80, 30, "Your name: " + playerText.getString(), window, font);
		drawText(WINDOW_WIDHT / 2, height + 120, 20, confirmInfo, window, font);
		window.display();
	}
	if (window.isOpen())
	{
		color = sf::Color::White;
		//czyszczenie podr�cznej tabeli wynik�w
		playersScore.clear();
		//dodanie gracza do podr�czenej tabeli wynik�w
		newScore = std::make_pair(playerText.getString(), score);
		playersScore.push_back(std::make_pair(playerText.getString(), score));
		//zaktualizuj plik z wynikami
		updateFile(fileName);
	}
	
}
//funkcja uzupe�niaj�ca tekst spacjami
std::string Highscore::fillText(std::string text, int newLenght)
{	
	std::string newString = text;
	for (int i = 0; i < newLenght - text.size(); i++)
		newString += " ";		
	
	return newString;
}


void Highscore::draw(sf::RenderWindow& window, sf::Font& font, sf::Event& event, std::string fileName, sf::Sprite backgroud, bool newResult)
{
	window.clear();
	window.draw(backgroud);
	playersScore.clear();
	// przeczytanie pliku z wynikami i aktualizacja podr�cznej tabeli wynik�w
	readFile(fileName);
	//wypisanie wynik�w
	drawText(WINDOW_WIDHT / 2, 80, 35, "Highscores", window, font);
	drawText(WINDOW_WIDHT / 4, 150, 25, fillText("Rank", 10) + fillText("Name", 20) + "Score", window, font, color, false);
	std::string results = "";
	int i = 1;
	//je�eli nie jest to nowy wynik, czyli wchodzimy do tej funckji przez menu, to wy�wietl jednolicie najlepsze 10 wynik�w
	if (!newResult)
		for (auto& player : playersScore)
		{
			drawText(WINDOW_WIDHT / 4, 170 + 30 * i, 25, fillText(std::to_string(i), 10) + fillText(player.first, 20) + std::to_string(player.second), window, font, color, false);
			i++;
			if (i > 10)
				break;
		}
	//je�li jest nowy wynik, czyli sko�czyli�my gr� to wypisujemy stare wyniki na bia�o, a nowy na czerwono
	else
	{
		bool actualPlayerDisplayed = false;
		int pos = playersScore.size();
		for (auto& player : playersScore)
		{
			if (player == newScore)
			{
				if (i <= 10)
				{
					drawText(WINDOW_WIDHT / 4, 170 + 30 * i, 25, fillText(std::to_string(i), 10) + fillText(player.first, 20) + std::to_string(player.second), window, font, sf::Color::Red, false);
					actualPlayerDisplayed = true;
				}
				else
					pos = i;
			}
			else
				if (i <= 10)
				{
					drawText(WINDOW_WIDHT / 4, 170 + 30 * i, 25, fillText(std::to_string(i), 10) + fillText(player.first, 20) + std::to_string(player.second), window, font, color, false);
				}
			i++;
		}
		// je�li okaza�o by si�, �e gracz mia� za niski wynik do najlepszej 10ki, to wypisujemy go pod spodem
		if(!actualPlayerDisplayed)
			drawText(WINDOW_WIDHT / 4, 170 + 30 * 11, 25, fillText(std::to_string(pos), 10) + fillText(newScore.first, 20) + std::to_string(newScore.second), window, font, sf::Color::Red, false);

	}
	//czekamy na spacj� obs�uguj�c opcj� wyj�cia z gry
	drawText(WINDOW_WIDHT / 2, 10 * 30 + 300, 20, "Press SPACE to return to menu", window, font);
	window.display();
	while (!sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space) && window.isOpen())
	{
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				window.close();
			}
		}
	}
}

bool Highscore::checkNameCorrection(std::string playerName)
{
	return std::regex_match(playerName, nameTemplate);
}

// czytanie z pliku i aktualizacja podr�czej tabeli wynik�w, posortowanie graczy po wyniku i wpisanie ich do pliku
void Highscore::updateFile(std::string fileName)
{
	readFile(fileName);
	sortPlayers();

	std::ofstream output(fileName);
	if (!output)
	{
		std::cerr << "Error Score file cannot be opened :( " << "\n";
	}
	int i = 0;
	output.clear();
	for(auto &player : playersScore)
	{
		output << player.first << " " << player.second;
		i++;
		if (i != playersScore.size())
			output << "\n";
	}
	output.close();
}

//zwyk�e czytanie z pliku i zapis do podr�cznej tablicy wynik�w
void Highscore::readFile(std::string fileName)
{
	std::string player;
	std::ifstream input(fileName);
	if (!input)
	{
		std::cerr << "Error Score file cannot be opened :( " << "\n";
	}
	while (std::getline(input, player))
	{
		std::istringstream data(player);
		std::string name, score;
		data >> name >> score;
		playersScore.push_back(std::make_pair(name, std::stoi(score)));
	}
	input.close();
}

// sortowanie graczy po zdobytym wyniku
void Highscore::sortPlayers()
{
	sort(playersScore.begin(), playersScore.end(),
		[](const std::pair<std::string, int> &a, const std::pair<std::string, int> &b)
		{
			return a.second > b.second;
		});
}