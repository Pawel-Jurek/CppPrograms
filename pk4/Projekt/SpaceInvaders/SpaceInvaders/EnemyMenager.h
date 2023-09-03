#pragma once
#include <vector>
#include <iostream>
#include "Enemy.h"
#include "SFML/Graphics.hpp"
#include "GlobalDefines.h"
#include <algorithm>
#include <random>
class EnemyMenager
{
private:
	std::vector<Enemy*> enemies;
	Sprite enemySprite;
	Texture enemyTexture;
	float movePause;
	const float bulletSpeed = -6;
	Texture bulletTexture;
	Sprite bulletSprite;
	std::default_random_engine eng;

public:
	std::vector<Bullet> enemyBullets;
	EnemyMenager();
	~EnemyMenager() = default;
	void draw(RenderWindow& window);
	void update(RenderWindow& window);
	float minLeftPosition();
	float maxRightPosition();
	inline std::vector<Bullet> getBullets() { return enemyBullets; }
	std::vector<Enemy*> getEnemies();
	void reset(unsigned int level);
	bool reachedBottom();
	unsigned int currentLevel;
};

