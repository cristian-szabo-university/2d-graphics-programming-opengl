/**
 *	Name		:	Enemy
 *	Author		:	B00233705
 *	Version		:	1.0
 *	Copyright	:	(c) 2013 http://videogamelab.co.uk/monkey-invasion
 *	Description	:	This file presents the variables and functions declarations 
 *					of class Enemy.
 */

#pragma once

#include "zeno\core.h"

const enum EnemyType
{
	ENEMY_UNUSED,
	ENEMY_IDLE,
	ENEMY_ANGRY,
	ENEMY_SPRITES,
	ENEMY_USED
};

const float MAX_HEALTH = 100.0f;

class Enemy : public Zeno::Object
{
public:

	/**
	 * @fn	Enemy::Enemy();
	 *
	 * @brief	The default constructor.
	 */

	Enemy();

	/**
	 * @fn	Enemy::~Enemy();
	 *
	 * @brief	The destructor.
	 */

	~Enemy();

	/**
	 * @fn	void Enemy::render();
	 *
	 * @brief	Renders this object.
	 */

	void render();

	/**
	 * @fn	void Enemy::restart();
	 *
	 * @brief	Restarts this object.
	 */

	void restart();

	/**
	 * @fn	void Enemy::setup();
	 *
	 * @brief	Setups this object sprites.
	 */

	void setup();

	/**
	 * @fn	bool Enemy::isHit();
	 *
	 * @brief	Query if this object is hit.
	 *
	 * @return	true if hit, false if not.
	 */

	bool isHit();

	/**
	 * @fn	void Enemy::damage(float nValue);
	 *
	 * @brief	Damages the object.
	 *
	 * @param	nValue	The amount fo damage done.
	 */

	void damage(float nValue);

	/**
	 * @fn	void Enemy::hit(bool bFlag);
	 *
	 * @brief	Hits the object.
	 *
	 * @param	bFlag	true to flag.
	 */

	void hit(bool bFlag);

	/**
	 * @fn	void Enemy::time(float nTime);
	 *
	 * @brief	Time when was hit.
	 *
	 * @param	nTime	The time in ticks.
	 */

	void time(float nTime);

	/**
	 * @fn	float Enemy::hitTime();
	 *
	 * @brief	Gets the time when the object was hit.
	 *
	 * @return	The time in ticks.
	 */

	float hitTime();

	/**
	 * @fn	void Enemy::drawHealthBar(float nPosX, float nPosY, float nWidth, float nHeight);
	 *
	 * @brief	Draw health bar.
	 *
	 * @param	nPosX  	The position x coordinate.
	 * @param	nPosY  	The position y coordinate.
	 * @param	nWidth 	The width.
	 * @param	nHeight	The height.
	 */

	void drawHealthBar(float nPosX, float nPosY, float nWidth, float nHeight);

	/**
	 * @fn	float Enemy::getHealth();
	 *
	 * @brief	Gets the health of object.
	 *
	 * @return	The health.
	 */

	float getHealth();

protected:


private:

	/**
	 * @brief	True if is hit.
	 */

	bool bHit;

	/**
	 * @brief	The time when was hit.
	 */

	float nTime;

	/**
	 * @brief	The health.
	 */

	float nHealth;

};