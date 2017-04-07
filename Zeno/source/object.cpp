#include "zeno\object.h"

namespace Zeno
{
	Object::Object()
	{
		nState = NULL;

		nIndex = NULL;

		nCell = 0;

		nSpeed = 15;
	}

	Object::~Object()
	{
		
	}

	void Object::draw()
	{
		static bool bShowOnce = true;
		size_t nIndexVec;

		if (nIndex != NULL)
		{
			int nCurrentCell = 0;

			for (nIndexVec = 0; nIndexVec < vecIndex.size(); nIndexVec++)
			{
				if (vecIndex[nIndexVec] == nIndex)
				{
					if (nCurrentCell == nCell)
					{
						glPushMatrix();
							// Enable texturing and blending options
							glEnable(GL_TEXTURE_2D);
							glEnable(GL_BLEND);

							// Sets the pixel arithmethic for transparency
							glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

							// Specifies how texture is interpreted.
							glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);		

							// Select current sprite
							vecSprite[nIndexVec].bind();

							// Draws the sprite over a square shape
							glBegin(GL_QUADS);
								glTexCoord2i(0, 0);
								glVertex2f(cParticle.getPosition()->getX(), cParticle.getPosition()->getY());
								glTexCoord2i(1, 0);
								glVertex2f(cParticle.getPosition()->getX() + vecSprite[nIndexVec].getWidth(), cParticle.getPosition()->getY());
								glTexCoord2i(1, 1);
								glVertex2f(cParticle.getPosition()->getX() + vecSprite[nIndexVec].getWidth(), cParticle.getPosition()->getY() + vecSprite[nIndexVec].getHeight());
								glTexCoord2i(0, 1);
								glVertex2f(cParticle.getPosition()->getX(), cParticle.getPosition()->getY() + vecSprite[nIndexVec].getHeight());
							glEnd();

							glDisable(GL_BLEND);
							glDisable(GL_TEXTURE_2D);
						glPopMatrix();
					}

					nCurrentCell++;
				}
			}
		}
		else
		{
			if (bShowOnce == true)
			{
				LOG(LOG_WARNING) << "The index is null";
				LOG(LOG_INFO) << "Note: This means there was no sprite added to object or the bind() function was used wrong";

				bShowOnce = false;
			}
		}
	}

	void Object::animate(float nTicks)
	{
		static double nOldTime = nTicks;

		if (nOldTime + (1.0 / nSpeed) > nTicks)
		{
			// Do nothing
		}
		else
		{
			if (nCell < countIndex(nIndex) - 1)
			{
				nCell++;
			}
			else
			{
				nCell = 0;
			}

			nOldTime = nTicks;
		}
	}

	void Object::erase(int nIndex, bool bAll)
	{
		int nGetIndexVec;

		nGetIndexVec = checkIndex(nIndex);

		if (bAll == true)
		{
			while (nGetIndexVec >= 0)
			{
				vecSprite.erase(vecSprite.begin() + nGetIndexVec);
				vecIndex.erase(vecIndex.begin() + nGetIndexVec);
			}
		}
		else
		{
			if (nGetIndexVec >= 0)
			{
				vecSprite.erase(vecSprite.begin() + nGetIndexVec);
				vecIndex.erase(vecIndex.begin() + nGetIndexVec);
			}
		}
	}

	void Object::setState(int nState)
	{
		if (nState != NULL)
		{
			this->nState = nState;
		}
		else
		{
			this->nState = NULL;
		}
	}

	void Object::setImageIndex(int nIndex)
	{
		static bool bShowOnce = true;		
		int nGetIndexVec;

		nGetIndexVec = checkIndex(nIndex);

		if (nGetIndexVec >= 0)
		{
			this->nIndex = vecIndex[nGetIndexVec];
		}
		else
		{
			if (bShowOnce == true)
			{
				LOG(LOG_WARNING) << "Can't bind because the index is not found";

				bShowOnce = false;
			}
		}
	}

	void Object::setImageSpeed(int nSpeed)
	{
		this->nSpeed = nSpeed;
	}

	void Object::addSprite(int nIndex, Sprite cSprite)
	{
		if (nIndex != NULL)
		{
			if (cSprite.ready() == true)
			{
				vecIndex.push_back(nIndex);
				vecSprite.push_back(cSprite);
			}
		}
		else
		{
			LOG(LOG_WARNING) << "Adding a sprite with a null index is not allowed";
		}
	}

	void Object::addSprite(int nIndex, std::vector<Sprite> vecSprite)
	{
		size_t nIndexVec;

		if (nIndex != NULL)
		{
			for (nIndexVec = 0; nIndexVec < vecSprite.size(); nIndexVec++)
			{
				if (vecSprite[nIndexVec].ready() == true)
				{
					vecIndex.push_back(nIndex);
					this->vecSprite.push_back(vecSprite[nIndexVec]);
				}
			}
		}
		else
		{
			LOG(LOG_WARNING) << "Adding a sprite with a null index is not allowed";
		}
	}

	void Object::addSprite(std::vector<Sprite> vecSprite)
	{
		size_t nIndexVec;

		for (nIndexVec = 0; nIndexVec < vecSprite.size(); nIndexVec++)
		{
			if (nIndexVec != NULL)
			{
				if (vecSprite[nIndexVec].ready() == true)
				{
					vecIndex.push_back(nIndexVec);
					this->vecSprite.push_back(vecSprite[nIndexVec]);
				}
			}
		}
	}

	int Object::getState()
	{
		return nState;
	}

	int Object::getIndex()
	{
		return nIndex;
	}

	Sprite* Object::getSprite()
	{
		static bool bShowOnce = true;
		int nGetIndexVec;

		if (nIndex != NULL)
		{
			nGetIndexVec = checkIndex(nIndex);

			if (nGetIndexVec >= 0)
			{
				return &vecSprite[nGetIndexVec];
			}
			else
			{
				if (bShowOnce == true)
				{
					LOG(LOG_WARNING) << "The sprite you want to get is not ready or doesn't exists";

					bShowOnce = false;
				}
			}
		}
		else
		{
			LOG(LOG_WARNING) << "The index is null";
		}

		return NULL;
	}

	Particle* Object::getParticle()
	{
		return &cParticle;
	}

	int Object::checkIndex(int nIndex)
	{
		size_t nIndexVec;

		for (nIndexVec = 0; nIndexVec < vecIndex.size(); nIndexVec++)
		{
			if (vecIndex[nIndexVec] == nIndex)
			{
				return nIndexVec;
			}
		}

		return -1;
	}

	int Object::countIndex(int nIndex)
	{
		size_t nIndexVec;
		int nTotal;

		nTotal = 0;

		for (nIndexVec = 0; nIndexVec < vecIndex.size(); nIndexVec++)
		{
			if (vecIndex[nIndexVec] == nIndex)
			{
				nTotal++;
			}
		}

		return nTotal;
	}
}