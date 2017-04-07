#include "game\player.h"

Player::Player()
{
	setState(PLAYER_USED);

	nAngle = 0.0f;
	nPower = 0.0f;
}

Player::~Player()
{

}

void Player::render()
{
	float nRotX, nRotY;

	setImageIndex(PLAYER_GUN);

	nRotX = getParticle()->getPosition()->getX() + getSprite()->getWidth() / 4.0f;
	nRotY = getParticle()->getPosition()->getY() + getSprite()->getHeight() / 4.0f;

	glPushMatrix();
		glTranslatef(nRotX, nRotY, 0.0f);

		glRotatef(nAngle, 0.0f, 0.0f, 1.0f);

		glTranslatef(-nRotX, -nRotY, 0.0f);

		Object::draw();
	glPopMatrix();

	setImageIndex(PLAYER_WHEEL);

	Object::draw();

	if (bFire == false)
	{
		nPower = 0.0f;
	}
}

void Player::restart()
{
	bFire = false;

	nPower = 0.0f;

	nAngle = 0.0f;
}

void Player::setup()
{
	addSprite(PLAYER_GUN, Zeno::Sprite("resources/characters/cannon/gun.tga"));
	addSprite(PLAYER_WHEEL, Zeno::Sprite("resources/characters/cannon/wheel.tga"));

	setImageIndex(PLAYER_GUN);
}

void Player::addPower(float nValue)
{
	nPower += nValue;

	if (nPower > MAX_POWER)
	{
		nPower = MAX_POWER;
	}
}

void Player::drawChargeBar(float nX, float nY, float nW, float nH)
{
	float nPosX, nPosY, nWidth, nHeight;

	nPosX = getParticle()->getPosition()->getX() + nX;
	nPosY = getParticle()->getPosition()->getY() + nY;
	nWidth = nPower / MAX_POWER * nW;
	nHeight = nH;

	glPushMatrix();
		glColor3f(255, 0, 0);
		glBegin(GL_QUADS);
			glVertex2d(nPosX, nPosY);
			glVertex2d(nPosX + nW, nPosY);
			glVertex2d(nPosX + nW, nPosY + nHeight);
			glVertex2d(nPosX, nPosY + nHeight);
		glEnd();

		glColor3f(255, 255, 0);
		glBegin(GL_QUADS);
			glVertex2d(nPosX, nPosY);
			glVertex2d(nPosX + nWidth, nPosY);
			glVertex2d(nPosX + nWidth, nPosY + nHeight);
			glVertex2d(nPosX, nPosY + nHeight);
		glEnd();
	glPopMatrix();
}

void Player::fire(bool bFlag)
{
	this->bFire = bFlag;
}

bool Player::canFire()
{
	return bFire;
}

void Player::setAngle(float nAngle)
{
	this->nAngle = nAngle;
}

float Player::getAngle()
{
	return nAngle;
}

float Player::getPower()
{
	return nPower;
}