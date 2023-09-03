#include "EnemyMenager.h"
#include <algorithm>

EnemyMenager::EnemyMenager()
{
	movePause = ENEMY_MOVE_PAUSE;
	currentLevel = 1;

	if (!bulletTexture.loadFromFile(ENEMY_BULLET_PATH))
	{
		std::cout << "Player bullet texture loading error\n";		
	}
	bulletSprite.setTexture(bulletTexture);
	bulletSprite.setScale(2, 2);
	bulletSprite.setOrigin(Vector2f(bulletSprite.getTexture()->getSize().x / 2, bulletSprite.getTexture()->getSize().y / 2));
	reset(1);
}


void EnemyMenager::draw(RenderWindow& window)
{
	for (Enemy* &enemy : enemies)
	{
		enemy->draw(window);
	}
	for (auto& bullet : enemyBullets)
	{
		bulletSprite.setPosition(bullet.getPosition());
		window.draw(bulletSprite);
	}
}


void EnemyMenager::update(RenderWindow &window)
{
	if (movePause == 0)
	{		
		// je¿eli kosmici poruszaj¹ siê w lewo i najdalej oddalony na lewo ma jeszcze zapas ruchu, 
		// albo analogicznie dla ca³oœci w prawo, to przemieœæ ka¿dego kosmitê w zadanym kierunku (funkcja update)
		// w przeciwnym razie opuœæ w dó³ i zmieñ kierunek
		if ((enemies.front()->getDirection() == -1 && minLeftPosition() > 0) || (enemies.back()->getDirection() == 1 && maxRightPosition() < WINDOW_WIDHT))
		{
			for (Enemy*& enemy : enemies)
			{
				enemy->update();				
			}
		}
		else
		{
			for (Enemy*& enemy : enemies)
			{
				enemy->moveDown();
				enemy->changeDirection();
			}
		}
		movePause = ENEMY_MOVE_PAUSE + enemies.size();
	}
	else
		movePause--;

	// znalezienie iteratora pocz¹tku nie¿yj¹cych kosmitów
	auto dead_enemies_start = remove_if(enemies.begin(), enemies.end(), [](Enemy*& i_enemy)
		{
			return 0 == i_enemy->isAlive();
		});
	// usuwanie nie¿yj¹cych kosmitów
	enemies.erase(dead_enemies_start, enemies.end());

	for (auto& enemy : enemies)
	{
		// losowe generowanie pocisków
		if (0 == std::uniform_int_distribution<int>(0, 300 * enemies.size())(eng))
			enemy->shoot(enemyBullets, bulletSprite.getTexture()->getSize().x, bulletSprite.getTexture()->getSize().y);
	}

	for (auto& bullet : enemyBullets)
	{
		bullet.update(window);
	}

	// usuwanie nieaktywnych pocisków
	enemyBullets.erase(remove_if(enemyBullets.begin(), enemyBullets.end(), [](Bullet& i_bullet)
		{
			return !i_bullet.isAlive();
		}), enemyBullets.end());

}

// znalezienie minimalnej pozycji kosmity z lewej strony
float EnemyMenager::minLeftPosition()
{
	float minLeft = WINDOW_WIDHT;
	for (auto& enemy : enemies)
	{
		minLeft = std::min(minLeft, enemy->left());
	}
	return minLeft;
}

// znalezienie maksymalnej pozycji kosmity z prawej strony
float EnemyMenager::maxRightPosition()
{
	float maxRight = 0;
	for (auto& enemy : enemies)
	{
		maxRight = std::max(maxRight, enemy->right());
	}
	return maxRight;
}

std::vector<Enemy*> EnemyMenager::getEnemies()
{
	return enemies;
}

// resetowanie rozgrywki i wczytywanie poziomów
void EnemyMenager::reset(unsigned int level)
{
	for (auto& enemy : enemies)
		delete enemy;
	enemies.clear();
	enemyBullets.clear();

	std::string levelUnits;
	currentLevel = level;
	switch (level) {
	case 1:
		levelUnits = "1111111111\n1111111111";
		break;

	case 2:
		levelUnits = "1111111111\n1111111111\n1111111111";
		break;

	case 3:
		levelUnits = "1121112111\n1211121121\n1121112111";
		break;

	case 4:
		levelUnits = "1121212111\n1212121121\n1122112111";
		break;

	case 5:
		levelUnits = "1123132111\n1213231121\n1122122311";
		break;

	case 6:
		levelUnits = "1332222331\n3321121132\n1323321233";
		break;

	case 7:
		levelUnits = "2233333322\n2223333222\n2222332222";
		break;

	case 8:
		levelUnits = "2233333322\n2333333332\n3333333333";
		break;
	}
	int enemyX = 0;
	int enemyY = 0;
	
	for (auto& unitType : levelUnits)
	{
		switch (unitType)
		{
		case '1':
			enemies.push_back(new Octopus(((WINDOW_WIDHT - ENEMY_COLS * ENEMY_WIDHT) / 2) + enemyX * (ENEMY_WIDHT + 10), (3 + enemyY) * 50, ENEMY1_PATH));
			break;
		case '2':
			enemies.push_back(new Crab(((WINDOW_WIDHT - ENEMY_COLS * ENEMY_WIDHT) / 2) + enemyX * (ENEMY_WIDHT + 10), (3 + enemyY) * 50, ENEMY2_PATH));
			break;
		case '3':
			enemies.push_back(new Squide(((WINDOW_WIDHT - ENEMY_COLS * ENEMY_WIDHT) / 2) + enemyX * (ENEMY_WIDHT + 10), (3 + enemyY) * 50, ENEMY3_PATH));
			break;
		case '\n':
			enemyY++;
			enemyX = 0;
			continue;
		}
		enemyX++;
	}

}

//sprawdzenie czy któryœ z kosmitów dotar³ do dolnej krawêdzi
bool EnemyMenager::reachedBottom()
{
	for (auto& enemy : enemies)
	{
		if (enemy->bottom() >= WINDOW_HEIGHT)
			return true;
	}
	return false;
}
