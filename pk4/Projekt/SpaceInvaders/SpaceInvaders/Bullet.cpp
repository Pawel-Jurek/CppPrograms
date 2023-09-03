#include "Bullet.h"
#include <iostream>

Bullet::Bullet(float p_x, float p_y, float v_x, float v_y, float t_widht, float t_height)
{
	alive = true;
	widht = t_widht;
	height = t_height;
	position = Vector2f(p_x, p_y);
	velocity = Vector2f(v_x, v_y) ;
}

Vector2f Bullet::getPosition()
{
	return position;
}

void Bullet::update(RenderWindow& window)
{
	if (alive)
	{	
		//je¿eli pozycja pocisku po aktualizacji nadal bêdzie znajdowa³a siê w zakresie wysokoœci ekranu, to przesuñ go o wektor prêdkoœci
		if (position.y + height/2 < window.getSize().y && position.y - height/2 > 0)
		{
			position.x += velocity.x;
			position.y += velocity.y;
		}
		else
			alive = false;
	}
}

bool Bullet::isAlive()
{
	return alive;
}

IntRect Bullet::getHitbox()
{
	return IntRect(position.x - widht/2,position.y - height/2,widht,height);
}

void Bullet::killBullet()
{
	alive = false;
}

