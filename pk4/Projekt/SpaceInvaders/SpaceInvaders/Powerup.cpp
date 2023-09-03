#include "Powerup.h"

Powerup::Powerup(int pType, Vector2f pPosition)
{
	type = static_cast<Type>(pType);
	position = pPosition;
	alive = true;
	
	switch (type)
	{
	case Type::tripleShoot:
		if (std::filesystem::exists(TRIPLE_PU_PATH))
			powerupTexture.loadFromFile(TRIPLE_PU_PATH);
		else
			std::cout << "Loading Powerup1 error\n";		
		break;
	case Type::shield:
		if (std::filesystem::exists(SHIELD_PU_PATH))
			powerupTexture.loadFromFile(SHIELD_PU_PATH);
		else
			std::cout << "Loading Powerup2 error\n";
		break;
	case Type::reloadSpeed:
		if (std::filesystem::exists(RELOAD_PU_PATH))
			powerupTexture.loadFromFile(RELOAD_PU_PATH);
		else
			std::cout << "Loading Powerup3 error\n";
		break;	
	}

	powerupSprite.setTexture(powerupTexture);
	powerupSprite.setScale(0.5, 0.5);
	powerupSprite.setOrigin(Vector2f(powerupSprite.getTexture()->getSize().x / 2, powerupSprite.getTexture()->getSize().y / 2));
}

IntRect Powerup::getHitbox()
{
	return IntRect(position.x - powerupSprite.getTexture()->getSize().x / 2, position.y - powerupSprite.getTexture()->getSize().y / 2, powerupSprite.getTexture()->getSize().x, powerupSprite.getTexture()->getSize().y);
}