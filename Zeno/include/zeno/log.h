/**
 *	Name		:	Log
 *	Author		:	B00233705
 *	Version		:	1.0
 *	Copyright	:	(c) 2013 http://videogamelab.co.uk/monkey-invasion
 *	Description	:	This file presents the variables and functions declarations 
 *					of class Log to output the game results.
 */

#pragma once

#include <fstream>
#include <sstream>
#include <time.h>

namespace Zeno
{
	/**
	 * @enum	LogLevel
	 *
	 * @brief	Values that represent teh log level.
	 */

	const enum LogLevel 
	{
		LOG_ERROR = 0, 
		LOG_WARNING, 
		LOG_INFO, 
		LOG_DEBUG,
	};

	/**
	 * @class	Log
	 *
	 * @brief	This class allows the user to output messages if something fails 
	 * 			without stoping the game loop. Notice that the user should not 
	 * 			create an object fo this class.
	 * 			
	 */

	class Log
	{
	public:

		/**
		 * @fn	Log::Log();
		 *
		 * @brief	The default constructor.
		 */

		Log();

		/**
		 * @fn	Log::~Log();
		 *
		 * @brief	The default destructor.
		 */

		~Log();

		/**
		 * @fn	std::ostringstream& Log::Output(LogLevel level);
		 *
		 * @brief	Outputs the given log level and message.
		 *
		 * @param	level	The log level type.
		 */

		std::ostringstream& Output(LogLevel level);

		/**
		 * @fn	static void Log::iniLog();
		 *
		 * @brief	Initialises the log file and format. This function should
		 * 			not be used by the user.
		 */

		static void iniLog();

		/**
		 * @fn	static void Log::endLog();
		 *
		 * @brief	Ends the log file. This function should not be used by the user.
		 */

		static void endLog();

	protected:
    
	private:
		/**
		 * @brief	The output message in file.
		 */

		std::ostringstream m_szOutput;

		/**
		 * @fn	std::string Log::m_printLevel(LogLevel level);
		 *
		 * @brief	Transform log level in string.
		 *
		 * @param	level	The log level.
		 *
		 * @return	the string of log level.
		 */

		std::string m_printLevel(LogLevel level);

		/**
		 * @fn	std::string Log::m_printTime();
		 *
		 * @brief	Gets the string time.
		 *
		 * @return	The string time.
		 */

		std::string m_printTime();
	};
}

/**
 * @def	LOG(level) Zeno::Log().Output(level)
 *
 * @brief	This function should be used by the user to output errors in log file.
 *
 * @param	level	The log level.
 */

#define LOG(level) Zeno::Log().Output(level)