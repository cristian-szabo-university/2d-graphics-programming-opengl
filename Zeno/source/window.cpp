#include "zeno\window.h"

namespace Zeno
{
	Window* Window::pcInstance = NULL;

	Window::~Window()
	{
		glfwTerminate();

		Zeno::Log::endLog();
	}

	void Window::run()
	{
		// Checks if user has added a game layout object
		if (pcLayout != NULL)
		{
			LOG(LOG_INFO) << "Game name : " << pcLayout->getWndTitle();
			LOG(LOG_INFO) << "Game (width x height) : " << pcLayout->getCamera()->getMapWidth() << " x " << pcLayout->getCamera()->getMapHeight();
			LOG(LOG_INFO) << "Game (columns x rows) : " << pcLayout->getCamera()->getMapColumns() << " x " << pcLayout->getCamera()->getMapRows();
			LOG(LOG_INFO) << "Game cell (width x height) : " << pcLayout->getCamera()->getMapCellWidth() << " x " << pcLayout->getCamera()->getMapCellHeight();

			// Initialize GLFW plugin
			if (iniGlfw() == true)
			{
				LOG(Zeno::LOG_DEBUG) << "GLFW library configured succesfully";

				setupCallbackFunctions();

				pcLayout->setup();

				// Enter game loop
				while(glfwGetWindowParam(GLFW_OPENED) != NULL)
				{
					pcLayout->getTimer()->update();

					if (pcLayout->getTimer()->canUpdate() == true)
					{
						pcLayout->update();

						pcLayout->render();

						glfwSwapBuffers();
					}					
				}

				pcLayout->cleanup();
			}
			else
			{
				LOG(Zeno::LOG_ERROR) << "GLFW library could not be setup";
			}
		}
		else
		{
			LOG(Zeno::LOG_ERROR) << "No game layout was configured";
			LOG(Zeno::LOG_INFO) << "Note: Use the setLayout() function to load the layout to the window";
		}
	}

	void Window::setLayout(Layout* pcLayout)
	{
		this->pcLayout = pcLayout;
	}

	Zeno::Window* Window::getInstance()
	{
		// Create window object if instance null
		if (pcInstance == NULL)
		{
			pcInstance = new Zeno::Window;
		}

		return pcInstance;
	}

	Window::Window()
	{
		Zeno::Log::iniLog();
	}

	void GLFWCALL Window::callbackSize(int nWidth, int nHeight)
	{
		pcInstance->getLayout()->reshape(nWidth, nHeight);
	}

	void GLFWCALL Window::callbackSpecialKeys(int key, int action)
	{
		pcInstance->getLayout()->specialKeys(key, action);
	}

	void GLFWCALL Window::callbackCharacterKeys(int key, int action)
	{
		pcInstance->getLayout()->characterKeys(key, action);
	}

	void GLFWCALL Window::callbackMouseButtons(int button, int action)
	{
		pcInstance->getLayout()->mouseButtons(button, action);
	}

	void GLFWCALL Window::callbackMousePosition(int x, int y)
	{
		pcInstance->getLayout()->mousePosition(x, y);
	}

	void Window::setupCallbackFunctions()
	{
		glfwSetWindowSizeCallback(callbackSize);
		glfwSetKeyCallback(callbackSpecialKeys);
		glfwSetCharCallback(callbackCharacterKeys);
		glfwSetMouseButtonCallback(callbackMouseButtons);
		glfwSetMousePosCallback(callbackMousePosition);
	}

	bool Window::iniGlfw()
	{
		GLFWvidmode videoMode;

		// Initialize GLFW plugin
		if (glfwInit() == NULL)
		{
			return false;
		}

		// Get monitor settings (width, height, read blue and green bits)
		glfwGetDesktopMode(&videoMode);

		// Create window with monitor and game layout settings
		if (glfwOpenWindow(pcLayout->getCamera()->getMapWidth(), pcLayout->getCamera()->getMapHeight(),
			videoMode.RedBits,		
			videoMode.GreenBits,	
			videoMode.BlueBits,	
			NULL,					
			24,						
			NULL,					
			GLFW_WINDOW) == NULL)
		{
			return false;
		}

		// VSync off
		glfwSwapInterval(0);

		// Set window title
		glfwSetWindowTitle(pcLayout->getWndTitle().c_str());

		// Position the window in the middle of the screen
		glfwSetWindowPos((videoMode.Width - pcLayout->getCamera()->getMapWidth()) / 2, (videoMode.Height - pcLayout->getCamera()->getMapHeight()) / 2);

		return true;
	}

	Layout* Window::getLayout()
	{
		return pcLayout;
	}
}