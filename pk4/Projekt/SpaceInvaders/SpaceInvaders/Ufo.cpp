#include "Ufo.h"
#include<iostream>

Ufo::Ufo(std::default_random_engine& engine):timerDistribution(UFO_MIN_TIMER, UFO_MAX_TIMER), powerupDistribution(0,2)
{
	if (std::filesystem::exists(UFO_PATH))
		ufoTexture.loadFromFile(UFO_PATH);
	else
		std::cout << "Ufo texture loading error\n";

	ufoSprite.setTexture(ufoTexture);
	ufoSprite.setScale(0.5, 0.5);
	ufoSprite.setOrigin(Vector2f(ufoSprite.getTexture()->getSize().x / 2, ufoSprite.getTexture()->getSize().y / 2));
	reset(engine);	
}

void Ufo::reset(std::default_random_engine& engine)
{
	//ustawienie losowego czasu generowania ufa z odpowiedniego przedzia³u i ogólny reset
	position.x = WINDOW_WIDHT;
	position.y = 50;
	timer = timerDistribution(engine);
	powerups.clear();
	alive = false;
}

void Ufo::update(std::default_random_engine& engine)
{
	//jeœli ¿yje to przesuwaj w lewo, dopóki nie dojdzie do lewej krawêdzi
	if (alive)
	{
		if (getPosition().x - UFO_SPEED > 0)
			position.x -= UFO_SPEED;
		else
			alive = false;
	}
	// w przeciwnym razie czekaj, a¿ timer dojdzie do 0
	else
	{
		if (0 == timer)
		{
			reset(engine);
			alive = true;
		}		
		else
			timer--;
	}
	//aktualizacja spadania wzmocnienia
	for (auto& powerup : powerups)
	{
		powerup.position.y += POWERUP_SPEED;

		if (WINDOW_HEIGHT <= powerup.position.y)
		{
			powerup.alive = false;
		}
	}

	//usuwanie nieaktywnych wzmocnieñ
	powerups.erase(remove_if(powerups.begin(), powerups.end(), [](const Powerup& i_powerup)
		{
			return !i_powerup.alive;
		}), powerups.end());
}

void Ufo::draw(RenderWindow& window)
{
	if (alive)
	{
		ufoSprite.setPosition(getPosition());
		window.draw(ufoSprite);
	}
	for (auto& powerup : powerups)
	{
		powerup.powerupSprite.setPosition(powerup.getPosition());
		window.draw(powerup.powerupSprite);
	}
}

bool Ufo::checkBulletCollision(std::default_random_engine& engine, const sf::IntRect& bulletHitbox)
{
	if (alive && getHitbox().intersects(bulletHitbox))
	{
		alive = false;
		powerups.emplace_back(powerupDistribution(engine), position);
		return true;
	}
	return false;
}

int Ufo::checkPlayerCollision(const IntRect& playerHitbox)
{
	for (auto& powerup : powerups)
	{
		if (powerup.getHitbox().intersects(playerHitbox))
		{
			powerup.alive = false;
			return 1 + powerup.getType();
		}
	}
	return 0;
	
}

IntRect Ufo::getHitbox()
{
	return IntRect(position.x - (2/3.) * ufoSprite.getTexture()->getSize().x / 2, position.y - (2 / 3.) * ufoSprite.getTexture()->getSize().y / 2, (2 / 3.) * ufoSprite.getTexture()->getSize().x, (2 / 3.) * ufoSprite.getTexture()->getSize().y);
}
