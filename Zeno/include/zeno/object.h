/**
 *	Name		:	Object
 *	Author		:	B00233705
 *	Version		:	1.0
 *	Copyright	:	(c) 2013 http://videogamelab.co.uk/monkey-invasion
 *	Description	:	This file presents the variables and functions declarations 
 *					of class Object to draw or animate a sprite with it's particle.
 */

#pragma once

#include <vector>

#include <zeno\particle.h>
#include <zeno\sprite.h>

namespace Zeno
{
	/**
	 * @class	Object
	 *
	 * @brief	This class allows the user to attach sprites and manage the 
	 * 			motion of the object.
	 */

	class Object
	{
	public:

		/**
		 * @fn	Object::Object();
		 *
		 * @brief	The default constructor prepares the state of the object.
		 */

		Object();

		/**
		 * @fn	Object::~Object();
		 *
		 * @brief	The default destructor.
		 */

		~Object();

		/**
		 * @fn	void Object::draw();
		 *
		 * @brief	Draws the object according to the index number.
		 */

		void draw();

		/**
		 * @fn	void Object::animate(float nTicks);
		 *
		 * @brief	Loops through sprites with the same index according to 
		 * 			animation speed. This function should be called in update
		 * 			stage of the game.
		 *
		 * @param	nTicks	The current time ticks.
		 */

		void animate(float nTicks);

		/**
		 * @fn	void Object::erase(int nIndex, bool bAll);
		 *
		 * @brief	Erases all sprites with the given index.
		 *
		 * @param	nIndex	The sprite index.
		 * @param	bAll  	true to delete all sprites with the same index.
		 */

		void erase(int nIndex, bool bAll);

		/**
		 * @fn	void Object::addSprite(int nIndex, Sprite cSprite);
		 *
		 * @brief	Adds a sprite to object with a given index.
		 *
		 * @param	nIndex 	The sprite index.
		 * @param	cSprite	The sprite object.
		 */

		void addSprite(int nIndex, Sprite cSprite);

		/**
		 * @fn	void Object::addSprite(int nIndex, std::vector<Sprite> vecSprite);
		 *
		 * @brief	Adds multiple sprites to object with the same index.
		 *
		 * @param	nIndex   	The index.
		 * @param	vecSprite	The vector sprites.
		 */

		void addSprite(int nIndex, std::vector<Sprite> vecSprite);

		/**
		 * @fn	void Object::addSprite(std::vector<Sprite> vecSprite);
		 *
		 * @brief	Adds a sprites to object with the index corresponding to 
		 * 			the position in vector.
		 *
		 * @param	vecSprite	The vector sprite.
		 */

		void addSprite(std::vector<Sprite> vecSprite);

		/**
		 * @fn	void Object::setState(int nState);
		 *
		 * @brief	Sets the state of the object. This variable is usefull 
		 * 			for the user to check if the object is ready or not.
		 *
		 * @param	nState	The state.
		 */

		void setState(int nState);

		/**
		 * @fn	void Object::setImageIndex(int nIndex);
		 *
		 * @brief	Sets which sprite to be draw.
		 *
		 * @param	nIndex	The index.
		 */

		void setImageIndex(int nIndex);

		/**
		 * @fn	void Object::setImageSpeed(int nSpeed);
		 *
		 * @brief	Sets the animation speed between sprites with the same index.
		 *
		 * @param	nSpeed	The speed.
		 */

		void setImageSpeed(int nSpeed);

		/**
		 * @fn	int Object::getState();
		 *
		 * @brief	Gets the state.
		 *
		 * @return	The state.
		 */

		int getState();

		/**
		 * @fn	int Object::getIndex();
		 *
		 * @brief	Gets the index.
		 *
		 * @return	The index.
		 */

		int getIndex();

		/**
		 * @fn	Sprite* Object::getSprite();
		 *
		 * @brief	Gets the sprite.
		 *
		 * @return	null if the index is empty, else the sprite.
		 */

		Sprite* getSprite();

		/**
		 * @fn	Particle* Object::getParticle();
		 *
		 * @brief	Gets the particle.
		 *
		 * @return	The particle object.
		 */

		Particle* getParticle();

	protected:


	private:

		/**
		 * @brief	The object state.
		 */

		int nState;

		/**
		 * @brief	The current sprite index.
		 */

		int nIndex;

		/**
		 * @brief	The animation speed.
		 */

		int nSpeed;

		/**
		 * @brief	The current sprite to be draw.
		 */

		int nCell;

		/**
		 * @brief	The vector which holds the sprites index.
		 */

		std::vector<int> vecIndex;

		/**
		 * @brief	The vector which holds the sprite objects.
		 */

		std::vector<Sprite> vecSprite;

		/**
		 * @brief	The object particle.
		 */

		Particle cParticle;

		/**
		 * @fn	int Object::checkIndex(int nIndex);
		 *
		 * @brief	Check if index exists in object.
		 *
		 * @param	nIndex	The index.
		 *
		 * @return	The index position in vector.
		 */

		int checkIndex(int nIndex);

		/**
		 * @fn	int Object::countIndex(int nIndex);
		 *
		 * @brief	Counts how many sprites are with the given index.
		 *
		 * @param	nIndex	The index.
		 *
		 * @return	The total number of sprites.
		 */

		int countIndex(int nIndex);

	};
}