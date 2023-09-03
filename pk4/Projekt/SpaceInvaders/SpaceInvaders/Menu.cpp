#include "menu.h"
Menu::Menu()
{

    if (std::filesystem::exists(ARIAL_FONT_PATH))
        font.loadFromFile(ARIAL_FONT_PATH);
    else
        std::cout << "Font loading error in Menu class\n";
    

    menu[0].setFont(font);
    menu[0].setCharacterSize(35);
    menu[0].setFillColor(Color::Red);
    menu[0].setString("Play");
    menu[0].setPosition(Vector2f(WINDOW_WIDHT / 2, WINDOW_HEIGHT / (items + 1)));

    menu[1].setFont(font);
    menu[1].setCharacterSize(35);
    menu[1].setFillColor(Color::White);
    menu[1].setString("Highscore table");
    menu[1].setPosition(Vector2f(WINDOW_WIDHT / 2, WINDOW_HEIGHT / (items + 1)));

    menu[2].setFont(font);
    menu[2].setCharacterSize(35);
    menu[2].setFillColor(Color::White);
    menu[2].setString("Instruction");
    menu[2].setPosition(Vector2f(WINDOW_WIDHT / 2, WINDOW_HEIGHT / (items + 1)));

    menu[3].setFont(font);
    menu[3].setCharacterSize(35);
    menu[3].setFillColor(Color::White);
    menu[3].setString("Exit");
    menu[3].setPosition(Vector2f(WINDOW_WIDHT / 2, WINDOW_HEIGHT / (items + 1)));

    selectedItemIndex = 0;
}

//rysowanie menu
void Menu::draw(RenderWindow& window)
{
    for (int i = 0; i < items; ++i)
    {
        drawText(WINDOW_WIDHT / 2, WINDOW_HEIGHT / 4 + 2*i*menu[0].getCharacterSize(), 35, menu[i].getString(), window, font, menu[i].getFillColor());
    }
    drawText(WINDOW_WIDHT / 2, WINDOW_HEIGHT / 4 + 2 * (items+2) * menu[0].getCharacterSize() - 30, 20, info1.getString(), window, font);
    drawText(WINDOW_WIDHT / 2, WINDOW_HEIGHT / 4 + 2 * (items+2) * menu[0].getCharacterSize(), 20, info2.getString(), window, font);
}

//dekrementacja indexu i zmiana czerwonego napisu, czyli aktualnego
void Menu::MoveUp()
{
    if (selectedItemIndex > 0)
    {
        menu[selectedItemIndex].setFillColor(Color::White);
        selectedItemIndex--;
        menu[selectedItemIndex].setFillColor(Color::Red);
    }
}

//inkrementacja indexu i zmiana czerwonego napisu, czyli aktualnego
void Menu::MoveDown()
{
    if (selectedItemIndex + 1 < items)
    {
        menu[selectedItemIndex].setFillColor(Color::White);
        selectedItemIndex++;
        menu[selectedItemIndex].setFillColor(Color::Red);
    }
}