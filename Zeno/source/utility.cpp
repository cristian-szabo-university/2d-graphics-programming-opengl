#include "zeno\utility.h"

namespace Zeno
{
	bool checkCollision(Zeno::Object* pObj1, Zeno::Object* pObj2)
	{
		float left1, left2;
		float right1, right2;
		float top1, top2;
		float bottom1, bottom2;

		left1 = pObj1->getParticle()->getPosition()->getX();
		left2 = pObj2->getParticle()->getPosition()->getX();

		right1 = pObj1->getParticle()->getPosition()->getX() + (float) pObj1->getSprite()->getWidth();
		right2 = pObj2->getParticle()->getPosition()->getX() + (float) pObj2->getSprite()->getWidth();

		top1 = pObj1->getParticle()->getPosition()->getY();
		top2 = pObj2->getParticle()->getPosition()->getY();

		bottom1 = pObj1->getParticle()->getPosition()->getY() + (float) pObj1->getSprite()->getHeight();
		bottom2 = pObj2->getParticle()->getPosition()->getY() + (float) pObj2->getSprite()->getHeight();

		if (bottom1 < top2) return false;
		if (top1 > bottom2) return false;

		if (right1 < left2) return false;
		if (left1 > right2) return false;

		return true;
	}

	bool checkMouseHover(Zeno::Object* pObj, Zeno::Camera* cCamera)
	{
		int nMousePosX, nMousePosY;
		int nWidth, nHeight;
		float nX, nY;

		glfwGetMousePos(&nMousePosX, &nMousePosY);
		
		nX = pObj->getParticle()->getPosition()->getX();
		nY = pObj->getParticle()->getPosition()->getY();
		nWidth = pObj->getSprite()->getWidth();
		nHeight = pObj->getSprite()->getHeight();

		if (cCamera->getWndWidthScale() < cCamera->getWndHeightScale())
		{
			nMousePosX -= (int)((cCamera->getMapWidth() / 2.0 * (cCamera->getWndScale() - 1.0)) / cCamera->getWndHeightScale());
			nMousePosY = cCamera->getWndHeight() - nMousePosY;

			nX /= cCamera->getWndHeightScale();
			nY /= cCamera->getWndHeightScale();
		}
		else 
		{
			nMousePosY = (int)((cCamera->getWndHeight() - nMousePosY) - (cCamera->getMapHeight() / 2.0 * (cCamera->getWndScale() - 1.0)) / cCamera->getWndWidthScale());

			nX /= cCamera->getWndWidthScale();
			nY /= cCamera->getWndWidthScale();
		}

		if (nMousePosX > nX && nMousePosX < nX + nWidth &&
			nMousePosY > nY && nMousePosY < nY + nHeight)
		{
			return true;
		}

		return false;
	}

	void updateMousePos(int* nX, int* nY, Zeno::Camera* cCamera)
	{
		if (cCamera->getWndWidthScale() < cCamera->getWndHeightScale())
		{
			*nX -= (int)((cCamera->getMapWidth() / 2.0 * (cCamera->getWndScale() - 1.0)) / cCamera->getWndHeightScale());
			*nY = cCamera->getWndHeight() - *nY;
		}
		else 
		{
			*nY = (int)((cCamera->getWndHeight() - *nY) - (cCamera->getMapHeight() / 2.0 * (cCamera->getWndScale() - 1.0)) / cCamera->getWndWidthScale());
		}
	}

	void drawNumber(int nValue, Vector2 cVector, Zeno::Object* pcObject)
	{
		int nCount, nWidth, nNewValue;
		float nPosX;

		pcObject->getParticle()->getPosition()->setX(cVector.getX());
		pcObject->getParticle()->getPosition()->setY(cVector.getY());

		nCount = 1;
		nNewValue = nValue;

		while (nNewValue > 9)
		{
			nCount *= 10;

			nNewValue /= 10;
		}

		nNewValue = nValue;

		while (nCount != 0)
		{
			pcObject->setImageIndex(nNewValue / nCount + 1);

			nPosX = pcObject->getParticle()->getPosition()->getX();			
			nWidth = pcObject->getSprite()->getWidth();

			pcObject->getParticle()->getPosition()->setX(nPosX + nWidth);

			pcObject->draw();

			nNewValue %= nCount;
			nCount /= 10;
		}
	}
}