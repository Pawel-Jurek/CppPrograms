#pragma once
#include "SFML/Graphics.hpp"
#include "GlobalDefines.h"
#include <filesystem>
#include <iostream>

using namespace sf;

class Powerup
{
public:
	enum Type {tripleShoot, shield, reloadSpeed};
	Powerup(int pType, Vector2f pPosition);
	~Powerup() = default;
	inline Vector2f getPosition() { return position; }	
	friend class Ufo;
	IntRect getHitbox();
	inline int getType() { return type; }
protected:
	Sprite powerupSprite;
	bool alive;
	Vector2f position;
	Type type;	
	Texture powerupTexture;
};

