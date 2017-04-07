/**
 *	Name		:	Timer
 *	Author		:	B00233705
 *	Version		:	1.0
 *	Copyright	:	(c) 2013 http://videogamelab.co.uk/monkey-invasion
 *	Description	:	This file presents the variables and functions declarations 
 *					of class Timer to manage the last frame time and game FPS.
 */

#pragma once

#include <gl\glfw.h>

namespace Zeno
{
	/**
	 * @class	Timer
	 *
	 * @brief	The class stores the last frame time and calculates the game FPS.
	 */

	class Timer
	{
	public:

		/**
		 * @fn	Timer::Timer();
		 *
		 * @brief	The default constructor initializes the varaibles.
		 */

		Timer();

		/**
		 * @fn	Timer::~Timer();
		 *
		 * @brief	Destructor.
		 */

		~Timer();

		/**
		 * @fn	void Timer::update();
		 *
		 * @brief	Updates the variables values. This function should pe called
		 * 			at every step because it calculates the last frame duration
		 * 			and when the last frame ended. Also it can display the FPS.
		 */

		void update();

		/**
		 * @fn	float Timer::getLastFrameTicks();
		 *
		 * @brief	Gets the last frame ticks.
		 *
		 * @return	The last frame ticks.
		 */

		float getLastFrameTicks();

		/**
		 * @fn	float Timer::getLastFrameDuration();
		 *
		 * @brief	Gets the last frame duration.
		 *
		 * @return	The last frame duration.
		 */

		float getLastFrameDuration();

		/**
		 * @fn	float Timer::getFramesPerSecond();
		 *
		 * @brief	Gets the game FPS.
		 *
		 * @return	The game FPS.
		 */

		float getFramesPerSecond();

	protected:


	private:

		/**
		 * @brief	The total frames number since the game started.
		 */

		unsigned long nFramesNumber;

		/**
		 * @brief	The last frame ticks.
		 */

		float nLastFrameTicks;

		/**
		 * @brief	Duration of the last frame.
		 */

		float nLastFrameDuration;

		/**
		 * @brief	The average frame duration which is the inverse of actual FPS.
		 */

		float nAverageFrameDuration;
	};
}