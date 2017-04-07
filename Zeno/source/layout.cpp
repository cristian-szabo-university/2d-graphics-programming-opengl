#include "zeno\layout.h"
#include "zeno\log.h"

namespace Zeno
{
	Layout::Layout()
	{

		szWndTitle = "Zeno Application";

		cCamera.setMapWidth(960);

		cCamera.setMapHeight(540);

		cCamera.setMapColumns(16);

		cCamera.setMapRows(9);
	}

	Layout::~Layout()
	{

	}

	void Layout::setWndTitle(std::string szWndTitle)
	{
		this->szWndTitle = szWndTitle;
	}

	void Layout::setTimer(int nFrameRate)
	{
		cTimer.setFrameRate(nFrameRate);
	}

	void Layout::setCamera(int nMapWidth, int nMapHeight, int nMapColumns, int nMapRows)
	{
		cCamera.setMapWidth(nMapWidth);

		cCamera.setMapHeight(nMapHeight);

		cCamera.setMapColumns(nMapColumns);

		cCamera.setMapRows(nMapRows);
	}

	std::string Layout::getWndTitle()
	{

		return szWndTitle;
	}

	Camera* Layout::getCamera()
	{
		return &cCamera;
	}

	Timer* Layout::getTimer()
	{
		return &cTimer;
	}
}