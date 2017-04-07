/**
 *	Name		:	Player
 *	Author		:	B00233705
 *	Version		:	1.0
 *	Copyright	:	(c) 2013 http://videogamelab.co.uk/monkey-invasion
 *	Description	:	This file presents the variables and functions declarations 
 *					of class Player.
 */

#pragma once

#include <iostream>

#include "zeno\core.h"

const enum PlayerType
{
	PLAYER_UNUSED,
	PLAYER_GUN,
	PLAYER_WHEEL,
	PLAYER_SPRITES,
	PLAYER_USED
};

const float MAX_POWER = 100.0f;

class Player : public Zeno::Object
{
	public:

		/**
		 * @fn	Player::Player();
		 *
		 * @brief	The default constructor.
		 */

		Player();

		/**
		 * @fn	Player::~Player();
		 *
		 * @brief	The destructor.
		 */

		~Player();

		/**
		 * @fn	void Player::render();
		 *
		 * @brief	Renders this object.
		 */

		void render();

		/**
		 * @fn	void Player::restart();
		 *
		 * @brief	Restarts this object stats.
		 */

		void restart();

		/**
		 * @fn	void Player::setup();
		 *
		 * @brief	Setups this object sprites.
		 */

		void setup();

		/**
		 * @fn	void Player::addPower(float nValue);
		 *
		 * @brief	Increases the power.
		 *
		 * @param	nValue	The value.
		 */

		void addPower(float nValue);

		/**
		 * @fn	void Player::drawChargeBar(float nPosX, float nPosY, float nWidth, float nHeight);
		 *
		 * @brief	Draw charge bar.
		 *
		 * @author	Cristi Szabo
		 * @date	5/1/2013
		 *
		 * @param	nPosX  	The position x coordinate.
		 * @param	nPosY  	The position y coordinate.
		 * @param	nWidth 	The width.
		 * @param	nHeight	The height.
		 */

		void drawChargeBar(float nPosX, float nPosY, float nWidth, float nHeight);

		/**
		 * @fn	void Player::fire(bool bFlag);
		 *
		 * @brief	Fires.
		 *
		 * @param	bFlag	true to flag.
		 */

		void fire(bool bFlag);

		/**
		 * @fn	bool Player::canFire();
		 *
		 * @brief	Determine if we can fire.
		 *
		 * @return	true if we can fire, false if not.
		 */

		bool canFire();

		/**
		 * @fn	void Player::setAngle(float nValue);
		 *
		 * @brief	Sets the angle rotation.
		 *
		 * @param	nValue	The value.
		 */

		void setAngle(float nValue);

		/**
		 * @fn	float Player::getAngle();
		 *
		 * @brief	Gets the angle.
		 *
		 * @return	The angle value.
		 */

		float getAngle();

		/**
		 * @fn	float Player::getPower();
		 *
		 * @brief	Gets the power.
		 *
		 * @return	The power value.
		 */

		float getPower();

	protected:


	private:

		/**
		 * @brief	True to fire.
		 */

		bool bFire;

		/**
		 * @brief	The power.
		 */

		float nPower;

		/**
		 * @brief	The angle.
		 */

		float nAngle;

};