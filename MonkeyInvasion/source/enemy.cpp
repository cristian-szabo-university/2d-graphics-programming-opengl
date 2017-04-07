#include "game\enemy.h"

Enemy::Enemy()
{
	setState(ENEMY_USED);

	getParticle()->setVelocity(Zeno::Vector2(40.0f, 0.0f));
}

Enemy::~Enemy()
{

}

void Enemy::render()
{
	if (bHit == true)
	{
		setImageIndex(ENEMY_ANGRY);
	}
	else
	{
		setImageIndex(ENEMY_IDLE);
	}

	Object::draw();
}

void Enemy::restart()
{
	bHit = false;

	nTime = 0.0f;

	nHealth = MAX_HEALTH;
}

void Enemy::setup()
{
	addSprite(ENEMY_IDLE, Zeno::Sprite("resources/characters/monkey/idle.tga"));
	addSprite(ENEMY_ANGRY, Zeno::Sprite("resources/characters/monkey/angry.tga"));

	setImageIndex(ENEMY_IDLE);
}

bool Enemy::isHit()
{
	return bHit;
}

void Enemy::damage(float nValue)
{
	nHealth -= nValue;
}

void Enemy::hit(bool bFlag)
{
	bHit = bFlag;
}

void Enemy::time(float nTime)
{
	this->nTime = nTime;
}

float Enemy::hitTime()
{
	return nTime;
}

void Enemy::drawHealthBar(float nX, float nY, float nW, float nH)
{
	float nPosX, nPosY, nWidth, nHeight;

	nPosX = getParticle()->getPosition()->getX() + nX;
	nPosY = getParticle()->getPosition()->getY() + nY;
	nWidth = nHealth / MAX_HEALTH * nW;
	nHeight = nH;

	glPushMatrix();
		glColor3f(255, 0, 0);
		glBegin(GL_QUADS);
			glVertex2d(nPosX, nPosY);
			glVertex2d(nPosX + nW, nPosY);
			glVertex2d(nPosX + nW, nPosY + nHeight);
			glVertex2d(nPosX, nPosY + nHeight);
		glEnd();

		glColor3f(0, 255, 0);
		glBegin(GL_QUADS);
			glVertex2d(nPosX, nPosY);
			glVertex2d(nPosX + nWidth, nPosY);
			glVertex2d(nPosX + nWidth, nPosY + nHeight);
			glVertex2d(nPosX, nPosY + nHeight);
		glEnd();
	glPopMatrix();
}

float Enemy::getHealth()
{
	return nHealth;
}