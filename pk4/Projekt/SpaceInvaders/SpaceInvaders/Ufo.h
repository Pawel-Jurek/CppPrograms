#pragma once
#include "SFML/Graphics.hpp"
#include "GlobalDefines.h"
#include <random>
#include "Powerup.h"
#include <filesystem>

using namespace sf;
class Ufo
{
public:
	Ufo(std::default_random_engine& engine);
	~Ufo() = default;
	void reset(std::default_random_engine& engine);
	void update(std::default_random_engine& engine);
	void draw(RenderWindow& window);
	Vector2f getPosition() { return position; }
	bool checkBulletCollision(std::default_random_engine& engine, const IntRect& bulletHitbox);
	int checkPlayerCollision(const IntRect& bulletHitbox);
	IntRect getHitbox();
private:
	Vector2f position;
	bool alive;
	float timer;
	std::uniform_int_distribution<unsigned short> timerDistribution;
	std::uniform_int_distribution<unsigned short> powerupDistribution;
	Texture ufoTexture;
	Sprite ufoSprite;
	std::vector<Powerup>powerups;
};

