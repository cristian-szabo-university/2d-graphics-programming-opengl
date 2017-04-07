/**
 *	Name		:	Windows
 *	Author		:	B00233705
 *	Version		:	1.0
 *	Copyright	:	(c) 2013 http://videogamelab.co.uk/monkey-invasion
 *	Description	:	This file presents the variables and functions declarations 
 *					of class Window to create and run a simple application.
 */

#pragma once

#include <string>

#include <gl\glfw.h>
#include <zeno\layout.h>
#include <zeno\log.h>

namespace Zeno
{
	/**
	 * @class	Window
	 *
	 * @brief	The class initializes the GLFW plugin and prepares the 
	 * 			game environment for the user to draw and animate object into
	 * 			a window.
	 */

	class Window
	{
	public:

		/**
		 * @fn	Window::~Window();
		 *
		 * @brief	Destructor of class Window deinitializes any resources 
		 * 			created by the GLFW plugin and ends writing in the log file
		 * 			the last output processes.
		 */

		~Window();

		/**
		 * @fn	void Window::run();
		 *
		 * @brief	Initializing the game loop
		 */

		void run();

		/**
		 * @fn	void Window::setLayout(Layout* pcLayout);
		 *
		 * @brief	Sets the game layout with all the keyboard and mouse checks, 
		 * 			display, reshape and update functions used in game loop.
		 *
		 * @param [in,out]	pcLayout	If non-null, the game layout.
		 */

		void setLayout(Layout* pcLayout);

		/**
		 * @fn	static Window* Window::getInstance();
		 *
		 * @brief	The user is not allowed to create an instance of class
		 * 			Window. This function should be used to run the game
		 * 			and setup the game layout.
		 *
		 * @return	null if it fails, else the instance.
		 */

		static Window* getInstance();

	protected:


	private:

		/**
		 * @brief	The game layout.
		 */

		Layout* pcLayout;

		/**
		 * @brief	The instance of class window.
		 */

		static Window* pcInstance;

		/**
		 * @fn	Window::Window();
		 *
		 * @brief	The constructor creates and initializes the log system.
		 */

		Window();

		static void GLFWCALL callbackSize(int nWidth, int nHeight);

		static void GLFWCALL callbackSpecialKeys(int nKey, int nAction);

		static void GLFWCALL callbackCharacterKeys(int nKey, int nAction);

		static void GLFWCALL callbackMouseButtons(int nButton, int bAction);

		static void GLFWCALL callbackMousePosition(int nX, int nY);

		/**
		 * @fn	void Window::setupCallbackFunctions();
		 *
		 * @brief	Sets up the callback functions.
		 */

		void setupCallbackFunctions();

		/**
		 * @fn	bool Window::iniGlfw();
		 *
		 * @brief	Initializes the GLFW plugin.
		 *
		 * @return	true if it succeeds, false if it fails.
		 */

		bool iniGlfw();

		/**
		 * @fn	Layout* Window::getLayout();
		 *
		 * @brief	Gets the game layout object.
		 *
		 * @return	null if it fails, else the layout.
		 */

		Layout* getLayout();

	};
}