#include "zeno\timer.h"

namespace Zeno
{
	Timer::Timer()
	{
		nLastFrameTicks = (float) glfwGetTime();

		nAverageFrameDuration = 0.0f;
	}

	Timer::~Timer()
	{
		
	}

	void Timer::update()
	{
		nFramesNumber++;

		float nCurrentTime = (float) glfwGetTime();

		if (nLastFrameTicks + (1.0f / nFrameRate) < nCurrentTime)
		{
			nLastFrameDuration = nCurrentTime - nLastFrameTicks;

			nLastFrameTicks = nCurrentTime;

			if (nFramesNumber > 0)
			{
				if (nAverageFrameDuration == 0)
				{
					nAverageFrameDuration = nLastFrameDuration;
				}
				else
				{
					nAverageFrameDuration = nAverageFrameDuration * 0.9f + 0.1f * nLastFrameDuration;
				}
			}

			bCanUpdate = true;
		}
		else
		{
			bCanUpdate = false;
		}	
	}

	bool Timer::canUpdate()
	{
		return bCanUpdate;
	}

	void Timer::setFrameRate(int nValue)
	{
		nFrameRate = nValue;
	}

	float Timer::getLastFrameTicks()
	{
		return nLastFrameTicks;
	}

	float Timer::getLastFrameDuration()
	{
		if (nLastFrameDuration < 0.02f)
		{
			return nLastFrameDuration;
		}
		else
		{
			return 0.0;
		}
	}

	float Timer::getFramesPerSecond()
	{
		return 1.0f / nAverageFrameDuration;
	}
}