/**
 *	Name		:	Utility
 *	Author		:	B00233705
 *	Version		:	1.0
 *	Copyright	:	(c) 2013 http://videogamelab.co.uk/monkey-invasion
 *	Description	:	This file presents the functions declarations to improve 
 *					user experience and time while building the game.
 *	Reference	:	http://www.gamedev.net/page/resources/_/technical/game-programming/collision-detection-r735
 */

#pragma once

#include <zeno\camera.h>
#include <zeno\object.h>

namespace Zeno
{
	/**
	 * @fn	bool checkCollision(Zeno::Object* pcObject1, Zeno::Object* pcObject2);
	 *
	 * @brief	Checks collision between two objects.
	 *
	 * @param [in,out]	pcObject1	The first object.
	 * @param [in,out]	pcObject2	The second object.
	 *
	 * @return	true if objects are collided.
	 */

	bool checkCollision(Zeno::Object* pcObject1, Zeno::Object* pcObject2);

	/**
	 * @fn	bool checkMouseHover(Zeno::Object* pcObject, Zeno::Camera* pcCamera);
	 *
	 * @brief	Checks if mouse is over an object.
	 *
	 * @param [in,out]	pcObject	The object.
	 * @param [in,out]	pcCamera	The camera.
	 *
	 * @return	true if mouse is over object.
	 */

	bool checkMouseHover(Zeno::Object* pcObject, Zeno::Camera* pcCamera);

	/**
	 * @fn	void updateMousePos(int* pnX, int* pnY, Zeno::Camera* pcCamera);
	 *
	 * @brief	Updates the mouse to a new position.
	 *
	 * @param [in,out]	pnX			The x coordinate of mouse.
	 * @param [in,out]	pnY			The y coordinate of mouse.
	 * @param [in,out]	pcCamera	The camera.
	 */

	void updateMousePos(int* pnX, int* pnY, Zeno::Camera* pcCamera);

	/**
	 * @fn	void drawNumber(int nValue, Vector2 cVector, Zeno::Object* pcObject);
	 *
	 * @brief	Draws a number between 0 and 64575485.
	 *
	 * @param	nValue				The value.
	 * @param	cVector				The vector position.
	 * @param [in,out]	pcObject	The object with the sprites.
	 */

	void drawNumber(int nValue, Vector2 cVector, Zeno::Object* pcObject);
}