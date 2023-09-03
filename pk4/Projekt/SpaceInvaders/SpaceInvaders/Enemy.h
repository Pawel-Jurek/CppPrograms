#pragma once
#include "SFML/Graphics.hpp"
#include "GlobalDefines.h"
#include "Bullet.h"
#include <filesystem>

using namespace sf;


class Enemy
{
public:
	Enemy(float t_x, float t_y, std::string texturePath);
	~Enemy() = default;
	Enemy() = delete;

	void update();
	float left();
	float bottom();
	float right();
	void moveDown();
	void changeDirection();
	void draw(RenderWindow& window);
	virtual void shoot(std::vector<Bullet>& enemy_bullets, float size_x, float size_y) = 0;
	int getDirection();
	bool isAlive();
	IntRect getHitbox();
	void hit();
	virtual int getPoints() = 0;

protected:
	int direction;
	int previous;
	int health;
	Vector2f position;
	constexpr static float widht = ENEMY_WIDHT;
	constexpr static float height = ENEMY_HEIGHT;
	Sprite enemySprite;
	Texture enemyTexture;
	bool alive;
};

class Octopus : public Enemy
{
	const int points = 10;
public:
	Octopus(float t_x, float t_y, std::string texturePath):
		Enemy(t_x, t_y, texturePath) {
		health = 1;
	}
	Octopus() = delete;
	~Octopus() = default;
	int getPoints() { return points; }
	void shoot(std::vector<Bullet>& enemy_bullets,float size_x, float size_y);
};

class Crab : public Enemy
{
	const int points = 30;
public:
	Crab(float t_x, float t_y, std::string texturePath) :
		Enemy(t_x, t_y, texturePath) {
		health = 2;
	}
	Crab() = delete;
	~Crab() = default;
	int getPoints() { return points; }
	void shoot(std::vector<Bullet>& enemy_bullets, float size_x, float size_y);
};

class Squide : public Enemy
{
	const int points = 50;
public:
	Squide(float t_x, float t_y, std::string texturePath) :
		Enemy(t_x, t_y, texturePath) {
		health = 3;
	}
	Squide() = delete;
	~Squide() = default;
	int getPoints() { return points; }
	void shoot(std::vector<Bullet>& enemy_bullets, float size_x, float size_y);
};