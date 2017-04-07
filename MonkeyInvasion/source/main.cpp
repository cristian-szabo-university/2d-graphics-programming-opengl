#include "game\game.h"

int main()
{
	Zeno::Layout* myLayout = NULL;
	Zeno::Window* myWnd = NULL;

	myLayout = new Game;
	myWnd = Zeno::Window::getInstance();

	myWnd->setLayout(myLayout);

	myWnd->run();

	delete myWnd;
	delete myLayout;

	return false;
}