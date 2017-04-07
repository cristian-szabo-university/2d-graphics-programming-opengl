/**
 *	Name		:	Sprite
 *	Author		:	B00233705
 *	Version		:	1.0
 *	Copyright	:	(c) 2013 http://videogamelab.co.uk/monkey-invasion
 *	Description	:	This file presents the variables and functions declarations 
 *					of class Sprite to load an image to OpenGL memory.
 */

#pragma once

#include <string>

#include <gl\glfw.h>
#include <zeno\log.h>

namespace Zeno
{
	/**
	 * @class	Sprite
	 *
	 * @brief	The class holds information regarding TGA files.
	 */

	class Sprite
	{
	public:

		/**
		 * @fn	Sprite::Sprite();
		 *
		 * @brief	The default constructor prepares the state of the sprite.
		 */

		Sprite();

		/**
		 * @fn	Sprite::Sprite(std::string szFileName);
		 *
		 * @brief	The explicit constructor loads the file into OpenGL memory.
		 *
		 * @param	szFileName	Filename of the TGA file.
		 */

		Sprite(std::string szFileName);

		/**
		 * @fn	Sprite::~Sprite();
		 *
		 * @brief	Destructor.
		 */

		~Sprite();

		/**
		 * @fn	void Sprite::load(std::string szFileName);
		 *
		 * @brief	If the state is false then the loading adn reading process 
		 * 			is starting.
		 *
		 * @param	szFileName	Filename of the TGA file.
		 */

		void load(std::string szFileName);

		/**
		 * @fn	void Sprite::bind();
		 *
		 * @brief	Sets the current texture to the first one in OpenGL memory.
		 */

		void bind();

		/**
		 * @fn	void Sprite::erase();
		 *
		 * @brief	Erases the texture from OpenGL memory and allows the object
		 * 			to use the load function again.
		 */

		void erase();

		/**
		 * @fn	bool Sprite::ready();
		 *
		 * @brief	Checks if the object si ready to be used.
		 *
		 * @return	true if texture is ready to be draw.
		 */

		bool ready();

		/**
		 * @fn	int Sprite::getWidth();
		 *
		 * @brief	Gets the texture width.
		 *
		 * @return	The texture width.
		 */

		int getWidth();

		/**
		 * @fn	int Sprite::getHeight();
		 *
		 * @brief	Gets the textureheight.
		 *
		 * @return	The texture height.
		 */

		int getHeight();

	protected:
		

	private:

		/**
		 * @brief	The OpenGL index number.
		 */

		unsigned int nIndex;

		/**
		 * @brief	The sprite status.
		 */

		bool bReady;

		/**
		 * @brief	The texture width.
		 */

		int nWidth;

		/**
		 * @brief	The texture height.
		 */

		int nHeight;

		/**
		 * @fn	void Sprite::loadFile(std::string szFileName);
		 *
		 * @brief	Loads the TGA file into OpenGL memory using the GLFW plugin.
		 * 			Note that the image needs to be 32bits TGA file. For converting
		 * 			an image to the desired format use this link :
		 * 			http://www.online-utility.org/image_converter.jsp?outputType=TGA
		 *
		 * @param	szFileName	Filename of the TGA file.
		 */

		void loadFile(std::string szFileName);

	};
}