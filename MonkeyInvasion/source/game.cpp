#include "game\game.h"

Game::Game()
{
	// Set window title
	setWndTitle("Monkey Invasion");

	// Setup camera
	getCamera()->setMapWidth(1280);
	getCamera()->setMapHeight(720);
	getCamera()->setMapColumns(16);
	getCamera()->setMapRows(9);
}

Game::~Game()
{

}

void Game::setup()
{
	vecPlayerSpr.resize(PLAYER_SPRITES);
	vecEnemySpr.resize(ENEMY_SPRITES);
	vecBackgroundSpr.resize(BACKGROUND_SPRITES);
	vecAmmoSpr.resize(AMMO_SPRITES);
	vecButtonSpr.resize(BUTTON_SPRITES);
	vecNumberSpr.resize(NUMBER_SPRITES);
	vecTitleSpr.resize(TITLE_SPRITES);

	vecButtonObj.resize(MAX_BUTTON_OBJECT);
	vecAmmoObj.resize(MAX_AMMO_OBJECT);
	vecCrateObj.resize(MAX_CRATE_OBJECT);
	vecTitleObj.resize(MAX_TITLE_OBJECT);

	// Create game map
	pGameMap = new int*[getCamera()->getMapRows()];

	for (int index = 0; index < getCamera()->getMapRows(); index++)
	{
		pGameMap[index] = new int[getCamera()->getMapColumns()];
	}

	// Cannon sprites and object
	cPlayerObj.setup();

	// Monkey sprites and object
	cEnemyObj.setup();

	// Backgrounds sprites and object
	vecBackgroundSpr[BACKGROUND_MAIN].load("resources/env/bg-main.tga");
	vecBackgroundSpr[BACKGROUND_HELP].load("resources/env/bg-help.tga");
	vecBackgroundSpr[BACKGROUND_GAME].load("resources/env/bg-game.tga");
	vecBackgroundSpr[BACKGROUND_END].load("resources/env/bg-end.tga");

	cBackgroundObj.addSprite(vecBackgroundSpr);

	// Ammo sprites and objects
	vecAmmoSpr[AMMO_BLUK].load("resources/items/bluk.tga");
	vecAmmoSpr[AMMO_JABOCA].load("resources/items/jaboca.tga");
	vecAmmoSpr[AMMO_MAGOST].load("resources/items/magost.tga");
	vecAmmoSpr[AMMO_PERSIM].load("resources/items/persim.tga");
	vecAmmoSpr[AMMO_PINAP].load("resources/items/pinap.tga");
	vecAmmoSpr[AMMO_RAWST].load("resources/items/rawst.tga");
	vecAmmoSpr[AMMO_RAZZ].load("resources/items/razz.tga");

	// Adds sprites to each object
	for (int index = 0; index < MAX_AMMO_OBJECT; index++)
	{
		vecAmmoObj[index].addSprite(vecAmmoSpr);
	}
	
	// Crates sprite and objects
	cCrateSpr.load("resources/env/crate.tga");

	// Adds sprites to each object
	for (int index = 0; index < MAX_CRATE_OBJECT; index++)
	{
		vecCrateObj[index].addSprite(CRATE_DEFAULT, cCrateSpr);
		vecCrateObj[index].setImageIndex(CRATE_DEFAULT);
	}

	// Buttons sprites and objects
	vecButtonSpr[BUTTON_START].load("resources/buttons/start.tga");
	vecButtonSpr[BUTTON_BACK].load("resources/buttons/back.tga");
	vecButtonSpr[BUTTON_RETURN].load("resources/buttons/return.tga");
	vecButtonSpr[BUTTON_EXIT].load("resources/buttons/exit.tga");
	vecButtonSpr[BUTTON_HELP].load("resources/buttons/help.tga");

	// Adds sprites to each object and sets image index
	vecButtonObj[BUTTON_START].addSprite(vecButtonSpr);
	vecButtonObj[BUTTON_START].setImageIndex(BUTTON_START);
	vecButtonObj[BUTTON_BACK].addSprite(vecButtonSpr);
	vecButtonObj[BUTTON_BACK].setImageIndex(BUTTON_BACK);
	vecButtonObj[BUTTON_RETURN].addSprite(vecButtonSpr);
	vecButtonObj[BUTTON_RETURN].setImageIndex(BUTTON_RETURN);
	vecButtonObj[BUTTON_EXIT].addSprite(vecButtonSpr);
	vecButtonObj[BUTTON_EXIT].setImageIndex(BUTTON_EXIT);
	vecButtonObj[BUTTON_HELP].addSprite(vecButtonSpr);
	vecButtonObj[BUTTON_HELP].setImageIndex(BUTTON_HELP);
	
	// Sets objects position
	vecButtonObj[BUTTON_START].getParticle()->setPosition(Zeno::Vector2(130, 255));
	vecButtonObj[BUTTON_BACK].getParticle()->setPosition(Zeno::Vector2(830, 50));
	vecButtonObj[BUTTON_RETURN].getParticle()->setPosition(Zeno::Vector2(508, 124));
	vecButtonObj[BUTTON_EXIT].getParticle()->setPosition(Zeno::Vector2(155, 40));
	vecButtonObj[BUTTON_HELP].getParticle()->setPosition(Zeno::Vector2(155, 150));

	// Numbers sprites and object
	vecNumberSpr[NUMBER_ZERO].load("resources/numbers/zero.tga");
	vecNumberSpr[NUMBER_ONE].load("resources/numbers/one.tga");
	vecNumberSpr[NUMBER_TWO].load("resources/numbers/two.tga");
	vecNumberSpr[NUMBER_THREE].load("resources/numbers/three.tga");
	vecNumberSpr[NUMBER_FOUR].load("resources/numbers/four.tga");
	vecNumberSpr[NUMBER_FIVE].load("resources/numbers/five.tga");
	vecNumberSpr[NUMBER_SIX].load("resources/numbers/six.tga");
	vecNumberSpr[NUMBER_SEVEN].load("resources/numbers/seven.tga");
	vecNumberSpr[NUMBER_EIGHT].load("resources/numbers/eight.tga");
	vecNumberSpr[NUMBER_NINE].load("resources/numbers/nine.tga");

	// Adds sprites to object
	cNumberObj.addSprite(vecNumberSpr);

	// Icons sprites and object
	cIconObj.addSprite(vecAmmoSpr);

	// Sets object position
	cIconObj.getParticle()->setPosition(Zeno::Vector2(200, 600));

	// Titles sprites and objects
	vecTitleSpr[TITLE_TYPE].load("resources/titles/type.tga");
	vecTitleSpr[TITLE_AMMO].load("resources/titles/ammo.tga");
	vecTitleSpr[TITLE_GAME].load("resources/titles/game.tga");
	vecTitleSpr[TITLE_WIN].load("resources/titles/win.tga");
	vecTitleSpr[TITLE_LOST].load("resources/titles/lost.tga");

	// Adds sprites to each object and sets image index 
	vecTitleObj[TITLE_TYPE].addSprite(vecTitleSpr);
	vecTitleObj[TITLE_TYPE].setImageIndex(TITLE_TYPE);
	vecTitleObj[TITLE_AMMO].addSprite(vecTitleSpr);
	vecTitleObj[TITLE_AMMO].setImageIndex(TITLE_AMMO);
	vecTitleObj[TITLE_GAME].addSprite(vecTitleSpr);
	vecTitleObj[TITLE_GAME].setImageIndex(TITLE_GAME);
	vecTitleObj[TITLE_WIN].addSprite(vecTitleSpr);
	vecTitleObj[TITLE_WIN].setImageIndex(TITLE_WIN);
	vecTitleObj[TITLE_LOST].addSprite(vecTitleSpr);
	vecTitleObj[TITLE_LOST].setImageIndex(TITLE_LOST);

	// Sets objects position
	vecTitleObj[TITLE_TYPE].getParticle()->setPosition(Zeno::Vector2(80, 600));
	vecTitleObj[TITLE_AMMO].getParticle()->setPosition(Zeno::Vector2(80, 560));
	vecTitleObj[TITLE_GAME].getParticle()->setPosition(Zeno::Vector2(37, 383));
	vecTitleObj[TITLE_WIN].getParticle()->setPosition(Zeno::Vector2(189, 421));
	vecTitleObj[TITLE_LOST].getParticle()->setPosition(Zeno::Vector2(386, 222));

	// Loads game map details from file
	readMap("resources/map/level.txt", pGameMap, getCamera()->getMapColumns(), getCamera()->getMapRows());

	eCurrentRoom = ROOM_MENU;
}

void Game::cleanup()
{

}

void Game::render()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

	switch (eCurrentRoom)
	{
	case ROOM_MENU:
		{
			cBackgroundObj.setImageIndex(BACKGROUND_MAIN);
			cBackgroundObj.draw();

			vecTitleObj[TITLE_GAME].draw();

			vecButtonObj[BUTTON_START].draw();

			vecButtonObj[BUTTON_HELP].draw();

			vecButtonObj[BUTTON_EXIT].draw();

			break;
		}
	case ROOM_HELP:
		{
			cBackgroundObj.setImageIndex(BACKGROUND_HELP);
			cBackgroundObj.draw();

			vecButtonObj[BUTTON_BACK].draw();

			break;
		}
	case ROOM_LEVEL:
		{
			cBackgroundObj.setImageIndex(BACKGROUND_GAME);
			cBackgroundObj.draw();
			
			if (cEnemyObj.getHealth() < 0.0f)
			{
				eCurrentRoom = ROOM_END;
			}
			else
			{				
				for (int index = 0; index < MAX_CRATE_OBJECT; index++)
				{
					if (vecCrateObj[index].getState() == CRATE_USED)
					{
						vecCrateObj[index].draw();
					}
				}
				
				for (int index = 0; index < MAX_AMMO_OBJECT; index++)
				{
					if (vecAmmoObj[index].getState() == AMMO_USED)
					{
						vecAmmoObj[index].draw();
					}
				}
				
				cPlayerObj.render();

				if (cPlayerObj.canFire() == true)
				{
					cPlayerObj.addPower(1.1f);

					cPlayerObj.drawChargeBar(40.0f, 3.0f, getCamera()->getMapCellWidth() / 2.0f, 14.0f);
				}
				
				cEnemyObj.render();

				if (cEnemyObj.hitTime() + 1.5f < cTimer.getLastFrameTicks())
				{
					cEnemyObj.hit(false);
				}

				cEnemyObj.drawHealthBar(0.0f, getCamera()->getMapCellHeight() + 10.0f, getCamera()->getMapCellWidth(), 14.0f);
				
				vecTitleObj[TITLE_TYPE].draw();

				cIconObj.setImageIndex(eCurrentAmmo);
				cIconObj.draw();

				vecTitleObj[TITLE_AMMO].draw();

				Zeno::drawNumber(nAvailableAmmo[eCurrentAmmo], Zeno::Vector2(160, 560), &cNumberObj);
			}
			
			break;
		}
	case ROOM_END:
		{
			cBackgroundObj.setImageIndex(BACKGROUND_END);
			cBackgroundObj.draw();

			if (cEnemyObj.getHealth() < 0.0f)
			{
				vecTitleObj[TITLE_WIN].draw();
			}
			else
			{
				vecTitleObj[TITLE_LOST].draw();		
			}

			vecButtonObj[BUTTON_RETURN].draw();

			break;
		}
	}
}

void Game::update()
{
	switch (eCurrentRoom)
	{
	case ROOM_LEVEL :
		{
			cTimer.update();
	
			float duration = (float) cTimer.getLastFrameDuration();
			
			// Update enemy particle
			cEnemyObj.getParticle()->integrate(duration * 3.5f);
			
			for (int index = 0; index < MAX_AMMO_OBJECT; index++)
			{
				if (vecAmmoObj[index].getState() == AMMO_USED)
				{
					// Update ammo particle if is used
					vecAmmoObj[index].getParticle()->integrate(duration * 4.5f);
					
					// Check ammo collision with enemy
					if (Zeno::checkCollision(&vecAmmoObj[index], &cEnemyObj) == true)
					{
						cEnemyObj.damage(DAMAGE_AMMO[vecAmmoObj[index].getIndex()]);

						cEnemyObj.hit(true);

						cEnemyObj.time((float) cTimer.getLastFrameTicks());

						vecAmmoObj[index].setState(AMMO_UNUSED);

						if (nTotalAmmo == 0)
						{
							eCurrentRoom = ROOM_END;
						}

						break;
					}	
					
					// Check ammo collision with crates
					for (int index2 = 0; index2 < MAX_CRATE_OBJECT; index2++)
					{
						if (vecCrateObj[index2].getState() == CRATE_USED)
						{
							if (Zeno::checkCollision(&vecAmmoObj[index], &vecCrateObj[index2]) == true)
							{
								vecAmmoObj[index].setState(AMMO_UNUSED);

								if (nTotalAmmo == 0)
								{
									eCurrentRoom = ROOM_END;
								}

								break;
							}
						}
					}				
				}
			}

			// Check enemy collision with crates
			for (int index = 0; index < MAX_CRATE_OBJECT; index++)
			{
				if (vecCrateObj[index].getState() == CRATE_USED)
				{
					if (Zeno::checkCollision(&cEnemyObj, &vecCrateObj[index]) == true)
					{
						cEnemyObj.getParticle()->getVelocity()->inverse();

						break;
					}
				}
			}
		}
	}
}

void Game::reshape(int nWidth, int nHeight)
{
	getCamera()->setViewport(nWidth, nHeight);
}

void Game::specialKeys(int nKey, int nAction)
{
	if (nKey == GLFW_KEY_ESC && nAction == GLFW_PRESS)
	{
		eCurrentRoom = ROOM_MENU;
	}
}

void Game::characterKeys(int nKey, int nAction)
{
	switch (eCurrentRoom)
	{
	case ROOM_LEVEL :
		{
			switch (nKey)
			{
				case '1' : eCurrentAmmo = AMMO_BLUK; break;
				case '2' : eCurrentAmmo = AMMO_JABOCA; break;
				case '3' : eCurrentAmmo = AMMO_MAGOST; break;
				case '4' : eCurrentAmmo = AMMO_PERSIM; break;
				case '5' : eCurrentAmmo = AMMO_PINAP; break;
				case '6' : eCurrentAmmo = AMMO_RAWST; break;
				case '7' : eCurrentAmmo = AMMO_RAZZ; break;
			}

			break;
		}
	}
}
void Game::mouseButtons(int nButton, int nAction)
{
	switch (eCurrentRoom)
	{
	case ROOM_MENU :
		{
			if (nButton == GLFW_MOUSE_BUTTON_LEFT && nAction == GLFW_RELEASE)
			{
				if (Zeno::checkMouseHover(&vecButtonObj[BUTTON_START], getCamera()) == true)
				{
					eCurrentRoom = ROOM_LEVEL;

					restartGame();
				}
				else if (Zeno::checkMouseHover(&vecButtonObj[BUTTON_HELP], getCamera()) == true)
				{
					eCurrentRoom = ROOM_HELP;
				}
				else if (Zeno::checkMouseHover(&vecButtonObj[BUTTON_EXIT], getCamera()) == true)
				{
					exit(EXIT_SUCCESS);
				}
			}

			break;
		}
	case ROOM_HELP :
		{
			if (nButton == GLFW_MOUSE_BUTTON_LEFT && nAction == GLFW_RELEASE)
			{
				if (Zeno::checkMouseHover(&vecButtonObj[BUTTON_BACK], getCamera()) == true)
				{
					eCurrentRoom = ROOM_MENU;
				}
			}

			break;
		}
	case ROOM_LEVEL :
		{
			if (nTotalAmmo >= 1 && nAvailableAmmo[eCurrentAmmo] >= 1)				
			{
				if(nButton == GLFW_MOUSE_BUTTON_LEFT && nAction == GLFW_PRESS)
				{
					cPlayerObj.fire(true);
				}

				if(nButton == GLFW_MOUSE_BUTTON_LEFT && nAction == GLFW_RELEASE)
				{				
					cPlayerObj.fire(false);
			
					nTotalAmmo--;

					nAvailableAmmo[eCurrentAmmo] -= 1;

					fireAmmo(eCurrentAmmo, cPlayerObj.getPower());
				}
			}

			break;
		}
	case ROOM_END :
		{
			if (nButton == GLFW_MOUSE_BUTTON_LEFT && nAction == GLFW_RELEASE)
			{
				if (Zeno::checkMouseHover(&vecButtonObj[BUTTON_RETURN], getCamera()) == true)
				{
					eCurrentRoom = ROOM_MENU;
				}
			}

			break;
		}
	}
}

void Game::mousePosition(int nX, int nY)
{
	Zeno::updateMousePos(&nX, &nY, getCamera());

	switch (eCurrentRoom)
	{
	case ROOM_LEVEL :
		{
			float nPosX, nPosY, nAngle;

			nPosX = cPlayerObj.getParticle()->getPosition()->getX();
			nPosY = cPlayerObj.getParticle()->getPosition()->getY();

			nAngle = atan(((nY - nPosY) / (nX - nPosX))) * RAD2DEG;

			if (nX > nPosX && nY > nPosY)
			{
				cPlayerObj.setAngle(nAngle);
			}

			break;
		}
	}
}

void Game::fireAmmo(AmmoType eAmmoType, float nPower)
{
	int index;
	float nPosX, nPosY, nAngle;

	// Look for a unused ammo object
	for (index = 0; index < MAX_AMMO_OBJECT; index++)
	{
		if (vecAmmoObj[index].getState() == AMMO_UNUSED)
		{
			break;
		}
	}

	// If found, set states
	if (index != MAX_AMMO_OBJECT)
	{
		vecAmmoObj[index].setState(AMMO_USED);		
		vecAmmoObj[index].setImageIndex(eAmmoType);
		
		nPosX = cPlayerObj.getParticle()->getPosition()->getX();
		nPosY = cPlayerObj.getParticle()->getPosition()->getY();
		nAngle = cPlayerObj.getAngle();

		vecAmmoObj[index].getParticle()->getPosition()->setX(nPosX - (getCamera()->getMapCellWidth() / 4) * sin(nAngle * DEG2RAD) + getCamera()->getMapCellWidth() * cos(nAngle * DEG2RAD));
		vecAmmoObj[index].getParticle()->getPosition()->setY(nPosY + (getCamera()->getMapCellHeight() / 3) * cos(nAngle * DEG2RAD) + getCamera()->getMapCellHeight() * sin(nAngle * DEG2RAD));
		vecAmmoObj[index].getParticle()->getVelocity()->setX(nPower * cos(nAngle * DEG2RAD));
		vecAmmoObj[index].getParticle()->getVelocity()->setY(nPower * sin(nAngle * DEG2RAD));
		vecAmmoObj[index].getParticle()->setAcceleration(Zeno::Vector2(0.0f, -9.81f));

		switch (eAmmoType)
		{
		case AMMO_BLUK:
			{
				vecAmmoObj[index].getParticle()->setMass(4.0f);
				vecAmmoObj[index].getParticle()->setAmortization(0.99f);

				break;
			}
		case AMMO_JABOCA:
			{
				vecAmmoObj[index].getParticle()->setMass(9.0f);
				vecAmmoObj[index].getParticle()->setAmortization(0.99f);

				break;
			}
		case AMMO_MAGOST:
			{
				vecAmmoObj[index].getParticle()->setMass(12.0f);
				vecAmmoObj[index].getParticle()->setAmortization(0.98f);

				break;
			}
		case AMMO_PERSIM:
			{
				vecAmmoObj[index].getParticle()->setMass(18.0f);
				vecAmmoObj[index].getParticle()->setAmortization(0.98f);

				break;
			}
		case AMMO_PINAP:
			{
				vecAmmoObj[index].getParticle()->setMass(16.0f);
				vecAmmoObj[index].getParticle()->setAmortization(0.97f);

				break;
			}
		case AMMO_RAWST:
			{
				vecAmmoObj[index].getParticle()->setMass(7.0f);
				vecAmmoObj[index].getParticle()->setAmortization(0.97f);

				break;
			}
		case AMMO_RAZZ:
			{
				vecAmmoObj[index].getParticle()->setMass(12.0f);
				vecAmmoObj[index].getParticle()->setAmortization(0.96f);

				break;
			}
		}	
	}
}

void Game::readMap(std::string szFileName, int** pGameMap, int nMapColumns, int nMapRows)
{
	std::ifstream file;
	int nRow = 0, nColumn = 0;

	file.open(szFileName.c_str());

	if (file.is_open()) 
	{
		while (!file.eof()) 
		{
			file >> pGameMap[nRow][nColumn];

			nColumn++;

			if (nColumn == nMapColumns)
			{
				nRow++;
				nColumn = 0;
			}

			if (nRow == nMapRows)
			{
				break;
			}
		}
	}

	file.close();
}

void Game::setupMap()
{
	int i, j, nIndex;
	float nPosX, nPosY;

	nIndex = 0;

	// Update crates, player and enemy position accordingly to game map
	for(i = 0, nPosY = getCamera()->getMapHeight() - getCamera()->getMapCellHeight(); i < getCamera()->getMapRows() ; i++, nPosY -= getCamera()->getMapCellHeight())
	{
		for(j = 0, nPosX = 0; j < getCamera()->getMapColumns(); j++, nPosX += getCamera()->getMapCellWidth())
		{
			if (pGameMap[i][j] == MAP_CRATE)
			{
				vecCrateObj[nIndex].setState(CRATE_USED);

				vecCrateObj[nIndex].getParticle()->setPosition(Zeno::Vector2(nPosX, nPosY));

				nIndex++;
			}
			else if (pGameMap[i][j] == MAP_PLAYER)
			{
				cPlayerObj.getParticle()->setPosition(Zeno::Vector2(nPosX, nPosY));
			}
			else if (pGameMap[i][j] == MAP_ENEMY)
			{
				cEnemyObj.setState(ENEMY_USED);

				cEnemyObj.getParticle()->setPosition(Zeno::Vector2(nPosX, nPosY + 1.0f));
			}
		}
	}
}

void Game::loadMagazine(AmmoType eAmmoType, int nValue)
{
	nAvailableAmmo[eAmmoType] = nValue;

	nTotalAmmo += nValue;
}

void Game::restartGame()
{
	int index;

	eCurrentAmmo = AMMO_BLUK;

	nTotalAmmo = 0;

	loadMagazine(AMMO_BLUK, 7);
	loadMagazine(AMMO_JABOCA, 6);
	loadMagazine(AMMO_MAGOST, 5);
	loadMagazine(AMMO_PERSIM, 4);
	loadMagazine(AMMO_PINAP, 3);
	loadMagazine(AMMO_RAWST, 2);
	loadMagazine(AMMO_RAZZ, 1);
	
	for (index = 0; index < MAX_AMMO_OBJECT; index++)
	{
		vecAmmoObj[index].setState(AMMO_UNUSED);
	}

	cPlayerObj.restart();

	cEnemyObj.restart();

	setupMap();
}