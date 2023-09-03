#pragma once
#include <SFML\Graphics.hpp>
#include "GlobalDefines.h"

using namespace sf;
class Bullet
{
public:
	Bullet(float p_x, float p_y, float v_x, float v_y, float t_widht, float t_height);
	Bullet() = delete;
	~Bullet() = default;
	Vector2f getPosition();
	void update(RenderWindow& window);
	bool isAlive();
	IntRect getHitbox();
	void killBullet();
private:
	bool alive;
	float widht;
	float height;
	Vector2f position;
	Vector2f velocity;
};

