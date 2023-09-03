#include "SpaceShip.h"
#include <iostream>

Spaceship::Spaceship()
{
	//sekcja tworz¹ca statek kosmiczny gracza
	velocity = Vector2f(0, 0);
	reloadingTimer = STANDARD_RELOAD_TIME;
	powersQuantity = 4;
	currentPowerup = powerups::none;
	health = 3;
	alive = true;
	powerTimer = 0;

	if (std::filesystem::exists(ANONYMOUS_PRO_FONT_PATH))
		font.loadFromFile(ANONYMOUS_PRO_FONT_PATH);
	else
		std::cout << "Font loading error in spaceship class\n";

	if (std::filesystem::exists(SPACESHIP_PATH))
		shipTexture.loadFromFile(SPACESHIP_PATH);
	else
		std::cout << "Spaceship texture loading error\n";


	//dla funkcjonaloœci przesuwanej tekstury w zale¿noœci od powerupa
	shipSprite.setTexture(shipTexture);
	shipSprite.setTextureRect(sf::IntRect(currentPowerup * shipSprite.getTexture()->getSize().x / powersQuantity, 0, shipSprite.getTexture()->getSize().x/powersQuantity, shipSprite.getTexture()->getSize().y));
	
	shipSprite.setOrigin(Vector2f(shipSprite.getTexture()->getSize().x / (2 * powersQuantity), shipSprite.getTexture()->getSize().y / 2));
	shipSprite.setPosition(WINDOW_WIDHT/2.f, WINDOW_HEIGHT-50);
	

	//sekcja tworz¹ca pocisk dla gracza
	if (!bulletTexture.loadFromFile(BULLET_PATH))
	{
		std::cout << "Player bullet texture loading error\n";
	}
	bulletSprite.setTexture(bulletTexture);
	bulletSprite.setScale(2, 2);
	bulletSprite.setOrigin(Vector2f(bulletSprite.getTexture()->getSize().x / 2, bulletSprite.getTexture()->getSize().y / 2));

}

Vector2f Spaceship::getPosition()
{
	return position;
}

void Spaceship::update(RenderWindow& window, EnemyMenager& enemyMenager, int& score, Ufo& ufo, default_random_engine& engine)
{
	Text lives;
	int powerupType;
	lives.setFont(font);
	lives.setFillColor(Color::Green);
	lives.setPosition(WINDOW_WIDHT - 150, 0);
	lives.setString("LIVES: " + to_string(health));
	
	window.draw(lives);
	if (alive)
	{

		shipSprite.move(velocity);
		shipSprite.setTextureRect(sf::IntRect(currentPowerup * shipSprite.getTexture()->getSize().x / powersQuantity, 0, shipSprite.getTexture()->getSize().x / powersQuantity, shipSprite.getTexture()->getSize().y));
		if (Keyboard::isKeyPressed(Keyboard::Key::Left) && left() > 0)
			velocity.x = -shipVelocity;
		else if (Keyboard::isKeyPressed(Keyboard::Key::Right) && right() < window.getSize().x)
			velocity.x = shipVelocity;
		else
			velocity.x = 0;

		if (reloadingTimer == 0)
		{
			if (Keyboard::isKeyPressed(Keyboard::Key::Space)) {
				switch (currentPowerup)
				{
				case powerups::tripleShoot:
					playerBullets.emplace_back(shipSprite.getPosition().x, shipSprite.getPosition().y, 0, PLAYER_BULLET_SPEED, bulletTexture.getSize().x, bulletTexture.getSize().y);
					playerBullets.emplace_back(shipSprite.getPosition().x - 20, shipSprite.getPosition().y, 0, PLAYER_BULLET_SPEED, bulletTexture.getSize().x, bulletTexture.getSize().y);
					playerBullets.emplace_back(shipSprite.getPosition().x + 20, shipSprite.getPosition().y, 0, PLAYER_BULLET_SPEED, bulletTexture.getSize().x, bulletTexture.getSize().y);
					reloadingTimer = STANDARD_RELOAD_TIME;
					break;
				case powerups::reloadSpeed:
					playerBullets.emplace_back(shipSprite.getPosition().x, shipSprite.getPosition().y, 0, PLAYER_BULLET_SPEED, bulletTexture.getSize().x, bulletTexture.getSize().y);
					reloadingTimer = BOOSTED_RELOAD_TIME;
					break;
				default:
					playerBullets.emplace_back(shipSprite.getPosition().x, shipSprite.getPosition().y, 0, PLAYER_BULLET_SPEED, bulletTexture.getSize().x, bulletTexture.getSize().y);
					reloadingTimer = STANDARD_RELOAD_TIME;
				}
			}
		}
		else
			reloadingTimer--;

		// przy trafieniu w statek dezaktywuj pocisk i wykonaj funkcjê zwi¹zan¹ z trafieniem gracza
		for (auto& enemy_bullet : enemyMenager.enemyBullets)
		{
			if (enemy_bullet.isAlive() && getHitbox().intersects(enemy_bullet.getHitbox()))
			{
				hit();
				enemy_bullet.killBullet();
				break;
			}
		}


		//sprawdzenie kolizji z przciwnikami
		for (Enemy*& enemy : enemyMenager.getEnemies())
		{
			if (enemy->getHitbox().intersects(getHitbox()))
			{
				alive = false;
				break;
			}
				
			for (auto& bullet : playerBullets)
			{
				// przy trafieniu dezaktywuj pocisk
				if (enemy->isAlive() && enemy->getHitbox().intersects(bullet.getHitbox()) && bullet.isAlive())
				{
					bullet.killBullet();
					enemy->hit();
					if (!enemy->isAlive())
						score += enemy->getPoints();
					break;
				}
			}
		}

		//usuwanie nieaktywnych pocisków
		playerBullets.erase(remove_if(playerBullets.begin(), playerBullets.end(), [](Bullet& i_bullet)
			{
				return !i_bullet.isAlive();
			}), playerBullets.end());

		//aktualizacja wszystkich pocisków gracza i sprawdzenie kolizji z graczem
		for (Bullet& bullet : playerBullets)
		{
			bullet.update(window);

			if (bullet.isAlive())
			{
				if (ufo.checkBulletCollision(engine, bullet.getHitbox()))
				{
					bullet.killBullet();
					score += 100;
				}
			}
		}
		//ufo.checkPlayerCollision(getHitbox()) zawsze zwraca wartoœæ, dlatego to sprawdzenie z 0, jako wartoœci¹ braku wzmocnienia
		powerupType = ufo.checkPlayerCollision(getHitbox());
		if(powerupType > 0)
		{ 
			currentPowerup = powerupType;
			powerTimer = POWERUP_DURATION;
		}
		
		if (powerTimer == 0)
		{
			currentPowerup = powerups::none;
		}
		else
			powerTimer--;
	}

}

float Spaceship::left()
{
	return shipSprite.getPosition().x - shipSprite.getTexture()->getSize().x / (2.f * powersQuantity);
}

float Spaceship::right()
{
	return shipSprite.getPosition().x + shipSprite.getTexture()->getSize().x / (2.f * powersQuantity);
}

void Spaceship::draw(RenderWindow& window)
{
	shipSprite.setTextureRect(sf::IntRect(currentPowerup * shipSprite.getTexture()->getSize().x / powersQuantity, 0, shipSprite.getTexture()->getSize().x / powersQuantity, shipSprite.getTexture()->getSize().y));
	shipSprite.setOrigin(Vector2f(shipSprite.getTexture()->getSize().x / (2 * powersQuantity), shipSprite.getTexture()->getSize().y / 2));
	window.draw(shipSprite);

	for (auto& bullet : playerBullets)
	{
		bulletSprite.setPosition(bullet.getPosition());
		window.draw(bulletSprite);
	}
}

IntRect Spaceship::getHitbox()
{
	return IntRect(shipSprite.getPosition().x - shipSprite.getTexture()->getSize().x / (2*powersQuantity), shipSprite.getPosition().y - shipSprite.getTexture()->getSize().y / 2, shipSprite.getTexture()->getSize().x / powersQuantity, shipSprite.getTexture()->getSize().y);
}

void Spaceship::hit()
{
	if (currentPowerup == powerups::shield)
		currentPowerup = powerups::none;
	else
	{
		health--;
		if (health <= 0)
			alive = false;
	}
	
}

void Spaceship::reset(bool newGame)
{
	if (newGame)
	{
		alive = true;
		health = 3;
	}
		
	playerBullets.clear();
	currentPowerup = powerups::none;
	shipSprite.setPosition(WINDOW_WIDHT / 2.f, WINDOW_HEIGHT - 50);
	reloadingTimer = STANDARD_RELOAD_TIME;
}
