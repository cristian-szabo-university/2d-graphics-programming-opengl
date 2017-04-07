#include "zeno\sprite.h"

namespace Zeno
{
	Sprite::Sprite()
	{
		bReady = false;
		nIndex = NULL;
	}

	Sprite::Sprite(std::string szFileName)
	{
		bReady = false;
		nIndex = NULL;

		loadFile(szFileName);
	}

	Sprite::~Sprite()
	{
		
	}

	void Sprite::load(std::string szFileName)
	{
		if (bReady == true)
		{
			erase();
		}

		loadFile(szFileName);
	}

	void Sprite::bind()
	{
		// Select current texture
		glBindTexture(GL_TEXTURE_2D, nIndex);
	}

	void Sprite::erase()
	{
		// Delete this texture
		glDeleteTextures(1, &nIndex);

		bReady = false;
		nIndex = NULL;
	}

	bool Sprite::ready()
	{
		return bReady;
	}

	void Sprite::loadFile(std::string szFileName)
	{
		GLFWimage sImageData;
		int nResultRead, nResultLoad;

		LOG(LOG_DEBUG) << "<b>Processing image</b> " << szFileName;
		LOG(LOG_INFO) << "Note : The image must be a .tga file";	

		// Read TGA file information
		nResultRead = glfwReadImage(szFileName.c_str(), &sImageData, GLFW_NO_RESCALE_BIT | GLFW_ALPHA_MAP_BIT);	

		if (nResultRead != NULL)
		{
			LOG(LOG_DEBUG) << "Reading image data ... OKEY";

			// Allocate one texture name in OpenGL memory
			glGenTextures(1, &nIndex);

			// Select current texture
			glBindTexture(GL_TEXTURE_2D, nIndex);
			
			// Build texture
			nResultLoad = glfwLoadTextureImage2D(&sImageData, GLFW_BUILD_MIPMAPS_BIT | GLFW_ALPHA_MAP_BIT);	

			if (nResultLoad != NULL)
			{
				LOG(LOG_DEBUG) << "Loading image in OpenGL memory ... OKEY";

				// Save texture size
				nWidth = sImageData.Width;
				nHeight = sImageData.Height;

				LOG(LOG_INFO) << "Image size : " << nWidth << " x " << nHeight;

				bReady = true;
			}
			else
			{
				// Delete allocated name if build stage failed
				glDeleteTextures(1, &nIndex);

				LOG(LOG_WARNING) << "Loading image in OpenGL memory ... FAIL";
			}
		}
		else
		{
			LOG(LOG_WARNING) << "Reading image data ... FAIL";
		}

		if (bReady == true)
		{
			LOG(LOG_DEBUG) << "Sprite object status ... OKEY";
		}
		else
		{
			LOG(LOG_WARNING) << "Sprite object status ... FAIL";
		}

		glfwFreeImage(&sImageData);
	}

	int Sprite::getWidth()
	{
		return nWidth;
	}

	int Sprite::getHeight()
	{
		return nHeight;
	}
}