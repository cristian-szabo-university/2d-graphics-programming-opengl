/**
 *	Name		:	Layout
 *	Author		:	B00233705
 *	Version		:	1.0
 *	Copyright	:	(c) 2013 http://videogamelab.co.uk/monkey-invasion
 *	Description	:	This file presents the variables and functions declarations 
 *					of class Layout which is the core system of the game arhitecture.
 */

#pragma once

#include <string>

#include <zeno\timer.h>
#include <zeno\camera.h>

namespace Zeno
{
	/**
	 * @class	Layout
	 *
	 * @brief	This class helps the user to draw and update the objects of the 
	 * 			game. Note that the class is abstract and all the virtual function
	 * 			should be declared in order to get full controll of keyboard and 
	 * 			mouse events.
	 */

	class Layout
	{
	public:

		/**
		 * @fn	Layout::Layout();
		 *
		 * @brief	The default constructor configure the default camera settings
		 * 			and the default window title.
		 */

		Layout();

		/**
		 * @fn	virtual Layout::~Layout();
		 *
		 * @brief	The default destructor.
		 */

		virtual ~Layout();

		/**
		 * @fn	virtual void Layout::setup() = 0;
		 *
		 * @brief	Gives access to user to initialize any pointers, 
		 * 			sprites and objects before the game loop starts.
		 */

		virtual void setup() = 0;

		/**
		 * @fn	virtual void Layout::cleanup() = 0;
		 *
		 * @brief	Called after the game loop ends and it should free
		 * 			the memory allocated for any object.	
		 */

		virtual void cleanup() = 0;

		/**
		 * @fn	virtual void Layout::render() = 0;
		 *
		 * @brief	Renders the objects.
		 */

		virtual void render() = 0;

		/**
		 * @fn	virtual void Layout::update() = 0;
		 *
		 * @brief	Updates the objects particle, collisions and time.
		 */

		virtual void update() = 0;

		/**
		 * @fn	virtual void Layout::reshape(int nWidth, int nHeight) = 0;
		 *
		 * @brief	Reshapes the window screen according to game map and 
		 * 			camera object.
		 *
		 * @param	nWidth 	The window width.
		 * @param	nHeight	The window height.
		 */

		virtual void reshape(int nWidth, int nHeight) = 0;

		/**
		 * @fn	virtual void Layout::specialKeys(int nKey, int nAction) = 0;
		 *
		 * @brief	Performs special keys press/release event.
		 *
		 * @param	nKey   	The key code.
		 * @param	nAction	The key action (pressed or released).
		 */

		virtual void specialKeys(int nKey, int nAction) = 0;

		/**
		 * @fn	virtual void Layout::characterKeys(int nKey, int nAction) = 0;
		 *
		 * @brief	Performs character keys press/release event.
		 *
		 * @param	nKey   	The key code.
		 * @param	nAction	The key action (pressed or released).
		 */

		virtual void characterKeys(int nKey, int nAction) = 0;

		/**
		 * @fn	virtual void Layout::mouseButtons(int nButton, int bAction) = 0;
		 *
		 * @brief	Performs mouse buttons press/release event.
		 *
		 * @param	nButton	The button code.
		 * @param	bAction	The button action (pressed or released).
		 */

		virtual void mouseButtons(int nButton, int bAction) = 0;

		/**
		 * @fn	virtual void Layout::mousePosition(int nX, int nY) = 0;
		 *
		 * @brief	Performs mouse position event.
		 *
		 * @param	nX	The mouse x coordinate.
		 * @param	nY	The mouse y coordinate.
		 */

		virtual void mousePosition(int nX, int nY) = 0;

		/**
		 * @fn	void Layout::setWndTitle(std::string szWndTitle);
		 *
		 * @brief	Sets window title.
		 *
		 * @param	szWndTitle	The window title.
		 */

		void setWndTitle(std::string szWndTitle);

		/**
		 * @fn	std::string Layout::getWndTitle();
		 *
		 * @brief	Gets window title.
		 *
		 * @return	The window title.
		 */

		std::string getWndTitle();

		/**
		 * @fn	Camera* Layout::getCamera();
		 *
		 * @brief	Gets the camera object.
		 *
		 * @return	Camera object.
		 */

		Camera* getCamera();

		/**
		 * @fn	Timer* Layout::getTimer();
		 *
		 * @brief	Gets the timer object.
		 *
		 * @return	Timer object.
		 */

		Timer* getTimer();

	protected:
		

	private:

		/**
		 * @brief	The window title.
		 */

		std::string szWndTitle;

		/**
		 * @brief	The camera object.
		 */

		Camera cCamera;

		/**
		 * @brief	The timer object.
		 */

		Timer cTimer;

	};
}