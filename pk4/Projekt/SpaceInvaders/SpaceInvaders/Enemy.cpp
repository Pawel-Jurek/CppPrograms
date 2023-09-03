#include "Enemy.h"
#include "GlobalDefines.h"
#include <iostream>



Enemy::Enemy(float t_x, float t_y, std::string texturePath)
{
	position = Vector2f(t_x, t_y);
	direction = -1; // left
	alive = true;
	previous = direction;

	if (std::filesystem::exists(texturePath))
		enemyTexture.loadFromFile(texturePath);
	else
		std::cout << "Alien texture loading error\n";
	

	health = 1;
	enemySprite.setTexture(enemyTexture);
	float initial_x = enemySprite.getTexture()->getSize().x;
	float initial_y = enemySprite.getTexture()->getSize().y;
	enemySprite.setScale(widht / initial_x, height / initial_y);
	enemySprite.setOrigin(Vector2f(enemySprite.getTexture()->getSize().x / 2, enemySprite.getTexture()->getSize().y / 2));
	enemySprite.setPosition(position);
}


float Enemy::left()
{
	return enemySprite.getPosition().x - enemySprite.getTexture()->getSize().x /2.f - ENEMY_STEP;
}

float Enemy::right()
{
	return enemySprite.getPosition().x + enemySprite.getTexture()->getSize().x / 2.f + ENEMY_STEP;
}

float Enemy::bottom()
{
	return enemySprite.getPosition().y + enemySprite.getTexture()->getSize().x / 2.f;
}

void Enemy::moveDown()
{
	enemySprite.move(0, 60);
}

void Enemy::changeDirection()
{
	direction = -direction;
}

void Enemy::update()
{
	enemySprite.move(direction * ENEMY_STEP, 0);
	position = enemySprite.getPosition();
}

void Enemy::draw(RenderWindow& window)
{
	window.draw(enemySprite);
}

int Enemy::getDirection()
{
	return direction;
}

bool Enemy::isAlive()
{
	return health > 0;
}

IntRect Enemy::getHitbox()
{
	// 2/3 * szerokoœæ i wysokoœæ, tak ¿eby zmmniejszyæ hitboxa
	return IntRect(position.x - (2/3.)*(ENEMY_WIDHT / 2), position.y - (2 / 3.)*ENEMY_HEIGHT / 2, (2 / 3.) * ENEMY_WIDHT, (2 / 3.) * ENEMY_HEIGHT);
}

void Enemy::hit()
{
	health--;
	if (health <= 0)
		alive = false;
}

void Octopus::shoot(std::vector<Bullet>& enemy_bullets, float size_x, float size_y)
{
	enemy_bullets.emplace_back(enemySprite.getPosition().x, enemySprite.getPosition().y, 0, ENEMY_BULLET_SPEED, size_x, size_y);
}

void Crab::shoot(std::vector<Bullet>& enemy_bullets, float size_x, float size_y)
{
	enemy_bullets.emplace_back(enemySprite.getPosition().x, enemySprite.getPosition().y, 0.125 * ENEMY_BULLET_SPEED, ENEMY_BULLET_SPEED, size_x, size_y);
	enemy_bullets.emplace_back(enemySprite.getPosition().x, enemySprite.getPosition().y, -0.125 * ENEMY_BULLET_SPEED, ENEMY_BULLET_SPEED, size_x, size_y);
}

void Squide::shoot(std::vector<Bullet>& enemy_bullets, float size_x, float size_y)
{
	enemy_bullets.emplace_back(enemySprite.getPosition().x, enemySprite.getPosition().y, 0.25 * ENEMY_BULLET_SPEED, ENEMY_BULLET_SPEED, size_x, size_y);
	enemy_bullets.emplace_back(enemySprite.getPosition().x, enemySprite.getPosition().y, 0, ENEMY_BULLET_SPEED, size_x, size_y);
	enemy_bullets.emplace_back(enemySprite.getPosition().x, enemySprite.getPosition().y, -0.25 * ENEMY_BULLET_SPEED, ENEMY_BULLET_SPEED, size_x, size_y);
}