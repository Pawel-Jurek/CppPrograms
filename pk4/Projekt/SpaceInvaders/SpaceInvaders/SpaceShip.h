#pragma once
#include <SFML\Graphics.hpp>
#include "Bullet.h"
#include "Enemy.h"
#include "EnemyMenager.h"
#include "Ufo.h"
#include <filesystem>

using namespace sf;
using namespace std;

class Spaceship
{
public:
	Spaceship();
	~Spaceship() = default;
	void draw(RenderWindow& window);
	Vector2f getPosition();
	void update(RenderWindow& window, EnemyMenager& enemyMenager, int& score, Ufo& ufo, default_random_engine& engine);
	float left();
	float right();
	IntRect getHitbox();
	inline bool isAlive() { return alive; }
	void hit();
	void reset(bool newGame = false);
	inline int getCurrentPowerup() { return currentPowerup; }
	inline int getPowerupTimer() { return powerTimer; }

private:
	Font font;
	Sprite shipSprite;
	Texture shipTexture;
	Image shipImage;
	Vector2f position;
	int currentPowerup;
	
	int powersQuantity;
	float reloadingTimer;
	int health;
	bool alive;
	const float shipVelocity{ 6.f };
	Vector2f velocity{ shipVelocity, 0.f };
	Texture bulletTexture;
	Sprite bulletSprite;
	vector<Bullet> playerBullets;
	float powerTimer;
	enum powerups {none, tripleShoot, shield, reloadSpeed };

};

