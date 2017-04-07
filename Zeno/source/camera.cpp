#include "zeno\camera.h"

namespace Zeno
{
	Camera::Camera()
	{

	}

	Camera::~Camera()
	{

	}

	void Camera::setViewport(int nWidth, int nHeight)
	{
		float nWndLeft, nWndRight, nWndBottom, nWndTop;
		float wndWidthCenter, wndNewWidthCenter, wndHeightCenter, wndNewHeightCenter;

		nWndWidth = nWidth;
		nWndHeight = nHeight;

		nWndWidthScale = (float) nMapWidth / nWndWidth;
		nWndHeightScale = (float) nMapHeight / nWndHeight;

		if (nWndWidthScale < nWndHeightScale)
		{
			nWndScale = nWndHeightScale / nWndWidthScale;
			wndWidthCenter = nMapWidth / 2.0f ;
			wndNewWidthCenter = wndWidthCenter * nWndScale;

			nWndLeft = wndWidthCenter - wndNewWidthCenter;
			nWndRight = wndWidthCenter + wndNewWidthCenter;
			nWndBottom = 0.0;
			nWndTop = (float) nMapHeight;		
		}
		else 
		{
			nWndScale = nWndWidthScale / nWndHeightScale;
			wndHeightCenter = nMapHeight / 2.0f;
			wndNewHeightCenter = wndHeightCenter * nWndScale;
 
			nWndLeft = 0.0;
			nWndRight = (float) nMapWidth;
			nWndBottom = wndHeightCenter - wndNewHeightCenter;
			nWndTop = wndHeightCenter + wndNewHeightCenter;
		}

		glViewport(0, 0, nWndWidth, nWndHeight);

		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();

		glOrtho(nWndLeft, nWndRight, nWndBottom, nWndTop, -1.0, 1.0);

		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();
	}

	void Camera::setMapWidth(int nMapWidth)
	{
		this->nMapWidth = nMapWidth;

		nMapCellWidth = (float) this->nMapWidth / nMapColumns;
	}

	void Camera::setMapHeight(int nMapHeight)
	{
		this->nMapHeight = nMapHeight;

		nMapCellHeight = (float) this->nMapHeight / nMapRows;
	}

	void Camera::setMapColumns(int nMapColumns)
	{
		this->nMapColumns = nMapColumns;

		nMapCellWidth = (float) nMapWidth / this->nMapColumns;
	}

	void Camera::setMapRows(int nMapRows)
	{
		this->nMapRows = nMapRows;

		nMapCellHeight = (float) nMapHeight / this->nMapRows;
	}

	int Camera::getMapWidth()
	{
		return nMapWidth;
	}

	int Camera::getMapHeight()
	{
		return nMapHeight;
	}

	int Camera::getMapColumns()
	{
		return nMapColumns;
	}

	int Camera::getMapRows()
	{
		return nMapRows;
	}

	float Camera::getMapCellWidth()
	{
		return nMapCellWidth;
	}

	float Camera::getMapCellHeight()
	{
		return nMapCellHeight;
	}

	int Camera::getWndWidth()
	{
		return nWndWidth;
	}

	int Camera::getWndHeight()
	{
		return nWndHeight;
	}

	float Camera::getWndWidthScale()
	{
		return nWndWidthScale;
	}

	float Camera::getWndHeightScale()
	{
		return nWndHeightScale;
	}

	float Camera::getWndScale()
	{
		return nWndScale;
	}
}