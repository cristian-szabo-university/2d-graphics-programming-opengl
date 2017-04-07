/**
 *	Name		:	Camera
 *	Author		:	B00233705
 *	Version		:	1.0
 *	Copyright	:	(c) 2013 http://videogamelab.co.uk/monkey-invasion
 *	Description	:	This file presents the variables and functions declarations 
 *					of class Camera to setup the window and map proprietes 
 *					(width, height, rows and columns) of the game.
 */

#pragma once

#include <gl\glfw.h>

namespace Zeno
{
	/**
	 * @class	Camera
	 *
	 * @brief	This class stores the windows size and the game map dimensions.
	 * 			It also can setup the viewport of the window screen for the 
	 * 			current game to have a fixed size even if the window was resized.
	 */

	class Camera
	{
	public:

		/**
		 * @fn	Camera::Camera();
		 *
		 * @brief	The default constructor.
		 */

		Camera();

		/**
		 * @fn	Camera::~Camera();
		 *
		 * @brief	The default destructor.
		 */

		~Camera();

		/**
		 * @fn	virtual void Camera::setViewport(int nWidth, int nHeight);
		 *
		 * @brief	Sets the game viewport with a fixed size even if the window
		 * 			was resized using the map settings.
		 *
		 * @param	nWidth 	The current window width.
		 * @param	nHeight	The current window height.
		 */

		virtual void setViewport(int nWidth, int nHeight);

		/**
		 * @fn	void Camera::setMapWidth(int nMapWidth);
		 *
		 * @brief	Sets map width.
		 *
		 * @param	nMapWidth	Width of the map.
		 */

		void setMapWidth(int nMapWidth);

		/**
		 * @fn	void Camera::setMapHeight(int nMapHeight);
		 *
		 * @brief	Sets map height.
		 *
		 * @param	nMapHeight	Height of the map.
		 */

		void setMapHeight(int nMapHeight);

		/**
		 * @fn	void Camera::setMapColumns(int nMapColumns);
		 *
		 * @brief	Sets map columns.
		 *
		 * @param	nMapColumns	The map columns.
		 */

		void setMapColumns(int nMapColumns);

		/**
		 * @fn	void Camera::setMapRows(int nMapRows);
		 *
		 * @brief	Sets map rows.
		 *
		 * @param	nMapRows	The map rows.
		 */

		void setMapRows(int nMapRows);

		/**
		 * @fn	int Camera::getMapWidth();
		 *
		 * @brief	Gets map width.
		 *
		 * @return	The map width.
		 */

		int getMapWidth();

		/**
		 * @fn	int Camera::getMapHeight();
		 *
		 * @brief	Gets map height.
		 *
		 * @return	The map height.
		 */

		int getMapHeight();

		/**
		 * @fn	int Camera::getMapColumns();
		 *
		 * @brief	Gets map columns.
		 *
		 * @return	The map columns.
		 */

		int getMapColumns();

		/**
		 * @fn	int Camera::getMapRows();
		 *
		 * @brief	Gets map rows.
		 *
		 * @return	The map rows.
		 */

		int getMapRows();

		/**
		 * @fn	float Camera::getMapCellWidth();
		 *
		 * @brief	Gets map cell width.
		 *
		 * @return	The map cell width.
		 */

		float getMapCellWidth();

		/**
		 * @fn	float Camera::getMapCellHeight();
		 *
		 * @brief	Gets map cell height.
		 *
		 * @return	The map cell height.
		 */

		float getMapCellHeight();

		/**
		 * @fn	int Camera::getWndWidth();
		 *
		 * @brief	Gets window width.
		 *
		 * @return	The window width.
		 */

		int getWndWidth();

		/**
		 * @fn	int Camera::getWndHeight();
		 *
		 * @brief	Gets window height.
		 *
		 * @return	The window height.
		 */

		int getWndHeight();

		/**
		 * @fn	float Camera::getWndWidthScale();
		 *
		 * @brief	Gets window width scale.
		 *
		 * @return	The window width scale.
		 */

		float getWndWidthScale();

		/**
		 * @fn	float Camera::getWndHeightScale();
		 *
		 * @brief	Gets window height scale.
		 *
		 * @return	The window height scale.
		 */

		float getWndHeightScale();

		/**
		 * @fn	float Camera::getWndScale();
		 *
		 * @brief	Gets window scale.
		 *
		 * @return	The window scale.
		 */

		float getWndScale();

	protected:


	private:

		/**
		 * @brief	Width of the map.
		 */

		int nMapWidth;

		/**
		 * @brief	Height of the map.
		 */

		int nMapHeight;

		/**
		 * @brief	The map columns.
		 */

		int nMapColumns;

		/**
		 * @brief	The map rows.
		 */

		int nMapRows;

		/**
		 * @brief	Width of the map cell.
		 */

		float nMapCellWidth;

		/**
		 * @brief	Height of the map cell.
		 */

		float nMapCellHeight;

		/**
		 * @brief	Width of the window.
		 */

		int nWndWidth;

		/**
		 * @brief	Height of the window.
		 */

		int nWndHeight;

		/**
		 * @brief	The window width scale.
		 */

		float nWndWidthScale;

		/**
		 * @brief	The window height scale.
		 */

		float nWndHeightScale;

		/**
		 * @brief	The window scale.
		 */

		float nWndScale;

	};
}