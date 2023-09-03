#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "SpaceShip.h"
#include "GlobalDefines.h"
#include "Enemy.h"
#include "EnemyMenager.h"
#include "DrawText.h"
#include "Menu.h"
#include "Ufo.h"
#include "Highscore.h"


bool gameplay(RenderWindow &window, Event &event, EnemyMenager &enemyMenager, Spaceship &spaceship, int &points, Font &font, Text &score, Ufo &ufo, default_random_engine& engine, Sprite& powerupBarSprite, Sprite& backgroud)
{
    while (window.isOpen())
    {
        window.clear();
        window.draw(backgroud);
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        if (spaceship.isAlive() && !enemyMenager.reachedBottom())
        {
            if (enemyMenager.getEnemies().size() > 0)
            {

                spaceship.update(window, enemyMenager, points, ufo, engine);

                score.setString("SCORE: " + to_string(points));
                window.draw(score);
                enemyMenager.update(window);

                if (spaceship.getCurrentPowerup() > 0)
                {
                    powerupBarSprite.setColor(Color(255, 255, 255));
                    powerupBarSprite.setTextureRect(IntRect(0, 0, powerupBarSprite.getTexture()->getSize().x, powerupBarSprite.getTexture()->getSize().y / 2));
                    powerupBarSprite.setOrigin(powerupBarSprite.getTexture()->getSize().x / 2, 0);
                    powerupBarSprite.setPosition(WINDOW_WIDHT / 2, 0);
                    window.draw(powerupBarSprite);

                    powerupBarSprite.setTextureRect(IntRect(0, powerupBarSprite.getTexture()->getSize().y / 2, powerupBarSprite.getTexture()->getSize().x * 1. * spaceship.getPowerupTimer() / POWERUP_DURATION, powerupBarSprite.getTexture()->getSize().y / 2));

                    switch (spaceship.getCurrentPowerup())
                    {
                    case 1:
                        powerupBarSprite.setColor(Color(237, 28, 36));
                        break;
                    case 2:
                        powerupBarSprite.setColor(Color(63, 72, 204));
                        break;
                    case 3:
                        powerupBarSprite.setColor(Color(255, 201, 14));
                    }
                    window.draw(powerupBarSprite);
                }

                enemyMenager.draw(window);
                spaceship.draw(window);
                ufo.update(engine);
                ufo.draw(window);
                window.display();
            }
            else if(enemyMenager.currentLevel< LEVELS)
            {          
                enemyMenager.reset(++enemyMenager.currentLevel);
                spaceship.reset();
                ufo.reset(engine);

                drawText(WINDOW_WIDHT / 2, WINDOW_HEIGHT / 2 - 100, 40, "Level " + to_string(enemyMenager.currentLevel), window, font);
                drawText(WINDOW_WIDHT / 2, WINDOW_HEIGHT / 2, 20, "Click space to PLAY", window, font);

                window.display();
                while (!Keyboard::isKeyPressed(Keyboard::Key::Space) && window.isOpen())
                {
                    while (window.pollEvent(event))
                    {
                        if (event.type == sf::Event::Closed)
                        {
                            window.close();
                            break;
                        }                          
                    }
                }                              
            }
            else
                return true; // wygrana                
        }
        else
            return false; // przegrana
    }
    return false;
}


using namespace sf;
using namespace std;


int main()
{
    RenderWindow window(VideoMode(WINDOW_WIDHT, WINDOW_HEIGHT),"Space Invaders");
    Sprite backgroundSprite;
    window.setFramerateLimit(60);
    
    Spaceship spaceship;
    int points = 0;
    Text score;
    EnemyMenager enemyMenager;
    Highscore highscoreTable;

    Font font;
    if (std::filesystem::exists(ANONYMOUS_PRO_FONT_PATH))
        font.loadFromFile(ANONYMOUS_PRO_FONT_PATH);
    else
        std::cout << "Font loading error in main\n";

    score.setFont(font);
    score.setFillColor(Color::White);
    sf::Event event;
    std::default_random_engine engine;
    Ufo ufo(engine);

    Sprite powerupBarSprite;
    Texture powerupBarTexture;
    if (std::filesystem::exists(POWERUP_BAR_PATH))
        powerupBarTexture.loadFromFile(POWERUP_BAR_PATH);
    else
        std::cout << "PowerupBar texture loading error\n";
    powerupBarSprite.setTexture(powerupBarTexture);
    
    Sprite instructionSprite;
    Texture instructionTexture;
    if (std::filesystem::exists(INSTRUCTION_PATH))
        instructionTexture.loadFromFile(INSTRUCTION_PATH);
    else
        std::cout << "Instruction texture loading error\n";
    instructionSprite.setTexture(instructionTexture);

    Sprite menuBgSprite;
    Texture menuBgTexture;
    if (std::filesystem::exists(MENU_BG_PATH))
        menuBgTexture.loadFromFile(MENU_BG_PATH);
    else
        std::cout << "Menu texture loading error\n";
    menuBgSprite.setTexture(menuBgTexture);

    Sprite highscoreSprite;
    Texture highscoreTexture;
    if (std::filesystem::exists(HIGHSCORE_BG_PATH))
        highscoreTexture.loadFromFile(HIGHSCORE_BG_PATH);
    else
        std::cout << "Highscore texture loading error\n";
    highscoreSprite.setTexture(highscoreTexture);

    Sprite bgSprite;
    Texture bgTexture;
    if (std::filesystem::exists(GAME_BG_PATH))
        bgTexture.loadFromFile(GAME_BG_PATH);
    else
        std::cout << "Main backgroud texture loading error\n";
    bgSprite.setTexture(bgTexture);

    Menu menu;
    window.draw(menuBgSprite);
    while (window.isOpen())
    {
        while (window.pollEvent(event))
        {
            points = 0;
            switch (event.type)
            {
            case Event::Closed:
                window.close();
                break;
            case Event::KeyReleased:
                switch (event.key.code)
                {
                case Keyboard::Up:
                    menu.MoveUp();
                    break;
                case Keyboard::Down:
                    menu.MoveDown();
                    break;
                case Keyboard::Enter:
                    switch (menu.GetPressedIndex())
                    {
                    case 0:
                        ufo.reset(engine);
                        enemyMenager.reset(1);
                        spaceship.reset(true);
                        points = 0;

                        if (gameplay(window, event, enemyMenager, spaceship, points, font, score, ufo, engine, powerupBarSprite, bgSprite))
                        {
                            window.clear();
                            drawText(WINDOW_WIDHT / 2, WINDOW_HEIGHT / 2 - 100, 40, "You Won!!!", window, font);
                        }
                        else
                        {
                            if (!window.isOpen())
                                break;
                            window.clear();
                            drawText(WINDOW_WIDHT / 2, WINDOW_HEIGHT / 2 - 100, 40, "You have been defeated", window, font);
                        }
                        drawText(WINDOW_WIDHT / 2, WINDOW_HEIGHT / 2 - 20, 35, "Your score: " + to_string(points), window, font);                     
                        window.display();
                        sleep(seconds(3));
                        highscoreTable.addPlayer(window, points, WINDOW_HEIGHT / 2 - 200, font, event, "highscore.txt");
                        highscoreTable.draw(window, font, event, "highscore.txt", highscoreSprite, true);
                        sleep(seconds(0.5));

                        break;
                    case 1:   
                        highscoreTable.draw(window, font, event, "highscore.txt", highscoreSprite, false);
                        break;

                    case 2:
                        window.clear();
                        window.draw(instructionSprite);
                        window.display();
                        while (!Keyboard::isKeyPressed(Keyboard::Key::Space) && window.isOpen())
                        {
                            while (window.pollEvent(event))
                            {
                                if (event.type == sf::Event::Closed)
                                {
                                    window.close();
                                    break;
                                }
                            }
                        }
                        break;

                    case 3:
                        window.close();
                        break;
                    }
                    break;
                }
            }
        }
        window.clear();
        window.draw(menuBgSprite);
        menu.draw(window);
        window.display();
    }
    
    return 0;
}
