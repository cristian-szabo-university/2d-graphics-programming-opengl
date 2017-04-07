#include "zeno\log.h"

namespace Zeno
{
	Log::Log()
	{
		 
	}

	Log::~Log()
	{
		m_szOutput << "</td>";
		m_szOutput << "</tr>";

		std::ofstream file;

		file.open("log/index.html", std::ios::out | std::ios::app);

		if (file.is_open() == true)
		{
			file << m_szOutput.str() << std::endl;
		}

		file.close();
	}

	std::ostringstream& Log::Output(LogLevel level)
	{
		switch (level)
		{
		case Zeno::LOG_ERROR : m_szOutput << "<tr class=\"error\">";
			break;
		case Zeno::LOG_WARNING : m_szOutput << "<tr class=\"warning\">";
			break;
		case Zeno::LOG_INFO : m_szOutput << "<tr class=\"info\">";
			break;
		case Zeno::LOG_DEBUG : m_szOutput << "<tr class=\"success\">";
			break;
		default:
			break;
		}

		m_szOutput << "<td>" << m_printTime() << "</td>";
		m_szOutput << "<td>" << m_printLevel(level) << "</td>";
		m_szOutput << "<td>";

		return m_szOutput;
	}

	std::string Log::m_printLevel(LogLevel level)
	{
		std::string szBuffer[] = {"LOG_ERROR", "LOG_WARNING", "LOG_INFO", "LOG_DEBUG"};

		return szBuffer[level];
	}

	std::string Log::m_printTime()
	{
		time_t sCurrentTime = time(NULL);
		tm  sTime;
		char cBuffer[100];

		sTime = *localtime(&sCurrentTime);

		strftime(cBuffer, sizeof(cBuffer), "%Y/%m/%d %X", &sTime);

		return cBuffer;
	}

	void Log::iniLog()
	{
		std::ofstream file;

		file.open("log/index.html");

		if (file.is_open() == true)
		{
			file << "<!DOCTYPE html>";
			file << "<html>";
			file << "<head>";
			file << "<title>Zeno Application Debug</title>";
			file << "<meta name=\"viewport\" content=\"width=device-width, initial-scale=1.0\">";
			file << "<link href=\"css/bootstrap.min.css\" rel=\"stylesheet\" media=\"screen\">";
			file << "</head>";
			file << "<body>";
			file << "<div class=\"container\" style=\"padding:30px 0px 0px 0px;\">";
			file << "<div class=\"row\">";
			file << "<div class=\"span12\">";
			file << "<div class=\"hero-unit\"><h1>Zeno Application Debug</h1><p>Welcome to debug output of your application.</p></div>";
			file << "</div>";
			file << "<div class=\"span12\">";
			file << "<table class=\"table table-bordered table-hover\">";
			file << "<thead><tr><th>Time</th><th>Level</th><th>Message</th></tr></thead>";
			file << "<tbody>";
		}

		file.close();
	}

	void Log::endLog()
	{
		std::ofstream file;

		file.open("log/index.html", std::ios::out | std::ios::app);

		if (file.is_open() == true)
		{
			file << "</tbody>";
			file << "</table>";
			file << "</div>";
			file << "</div>";
			file << "</div>";
			file << "</div>";
			file << "<script src=\"http://code.jquery.com/jquery.js\"></script>";
			file << "<script src=\"js/bootstrap.min.js\"></script>";
			file << "</body>";
			file << "</html>";
		}

		file.close();
	}
}