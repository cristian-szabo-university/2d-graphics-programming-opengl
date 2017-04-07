/**
 *	Name		:	Game
 *	Author		:	B00233705
 *	Version		:	1.0
 *	Copyright	:	(c) 2013 http://videogamelab.co.uk/monkey-invasion
 *	Description	:	This file presents the variables and functions declarations 
 *					of class Game which setup the game objects and how they are
 *					rendered, updated and any mouse or keyboard events.
 */

#pragma once

#include <iostream>
#include <string>
#include <vector>

#include "zeno\core.h"
#include "game\player.h"
#include "game\enemy.h"

// Constants for radians to degrees transformation
const float RAD2DEG = 180.0f / 3.141592f;

const float DEG2RAD = 3.141592f / 180.0f;

// Maximum number of objects in game for each type
const int MAX_BACKGROUND_OBJECT = 1;

const int MAX_AMMO_OBJECT = 20;

const int MAX_CRATE_OBJECT = 144;

const int MAX_BUTTON_OBJECT = 6;

const int MAX_TITLE_OBJECT = 6;

const enum MapType
{
	MAP_UNUSED,
	MAP_CRATE,
	MAP_PLAYER,
	MAP_ENEMY,
	MAP_MAX_OBJECTS,
	MAP_USED
};

const enum RoomType
{
	ROOM_UNUSED,
	ROOM_MENU,
	ROOM_HELP,
	ROOM_LEVEL,
	ROOM_END,
	ROOM_MAX_SPRITES,
	ROOM_USED
};

const enum BackgroundType
{
	BACKGROUND_UNUSED,
	BACKGROUND_MAIN,
	BACKGROUND_HELP,
	BACKGROUND_GAME,
	BACKGROUND_END,
	BACKGROUND_SPRITES,
	BACKGROUND_USED
};

const enum CrateType
{
	CRATE_UNUSED,
	CRATE_DEFAULT,
	CRATE_MAX_SPRITES,
	CRATE_USED
};

const enum AmmoType
{
	AMMO_UNUSED,
	AMMO_BLUK,
	AMMO_JABOCA,
	AMMO_MAGOST,
	AMMO_PERSIM,
	AMMO_PINAP,
	AMMO_RAWST,
	AMMO_RAZZ,
	AMMO_SPRITES,
	AMMO_USED
};

const enum ButtonType
{
	BUTTON_UNUSED,
	BUTTON_START,
	BUTTON_BACK,
	BUTTON_RETURN,
	BUTTON_EXIT,
	BUTTON_HELP,
	BUTTON_SPRITES,
	BUTTON_USED
};

const enum NumberType
{
	NUMBER_UNUSED,
	NUMBER_ZERO,
	NUMBER_ONE,
	NUMBER_TWO,
	NUMBER_THREE,
	NUMBER_FOUR,
	NUMBER_FIVE,
	NUMBER_SIX,
	NUMBER_SEVEN,
	NUMBER_EIGHT,
	NUMBER_NINE,
	NUMBER_SPRITES,
	NUMBER_USED
};

const enum TitleType
{
	TITLE_UNUSED,
	TITLE_TYPE,
	TITLE_AMMO,
	TITLE_GAME,
	TITLE_WIN,
	TITLE_LOST,
	TITLE_SPRITES,
	TITLE_USED
};

// Damage delt by each ammo type
const float DAMAGE_AMMO[AMMO_SPRITES + 1] = {0, 12, 14, 16, 18, 20, 22, 24};

// Available munition for each ammo type
const int AVAILABLE_AMMO[AMMO_SPRITES + 1] = {0, 7, 6, 5, 4, 3, 2, 1};

class Game : public Zeno::Layout
{
public:
	Game();

	~Game();

	void setup();

	void cleanup();

	void render();

	void update();

	void reshape(int nWidth, int nHeight);

	void specialKeys(int nKey, int nAction);

	void characterKeys(int nKey, int nAction);

	void mouseButtons(int nButton, int nAction);

	void mousePosition(int nX, int nY);

protected:
	Zeno::Timer cTimer;
	
	std::vector<Zeno::Sprite> vecBackgroundSpr;

	Zeno::Object cBackgroundObj;

	std::vector<Zeno::Sprite> vecButtonSpr;

	std::vector<Zeno::Object> vecButtonObj;
	
	std::vector<Zeno::Sprite> vecAmmoSpr;

	std::vector<Zeno::Object> vecAmmoObj;

	Zeno::Sprite cCrateSpr;

	std::vector<Zeno::Object> vecCrateObj;

	std::vector<Zeno::Sprite> vecNumberSpr;

	Zeno::Object cNumberObj;

	std::vector<Zeno::Sprite> vecTitleSpr;

	std::vector<Zeno::Object> vecTitleObj;

	Zeno::Object cIconObj;
	
	std::vector<Zeno::Sprite> vecPlayerSpr;

	Player cPlayerObj;

	std::vector<Zeno::Sprite> vecEnemySpr;

	Enemy cEnemyObj;
	
	AmmoType eCurrentAmmo;

	RoomType eCurrentRoom;

	int** pGameMap;

	int nTotalAmmo;

	int nAvailableAmmo[AMMO_SPRITES];
	
	void fireAmmo(AmmoType eAmmoType, float nPower);

	void readMap(std::string szFileName, int** pGameMap, int nMapColumns, int nMapRows);

	void setupMap();

	void loadMagazine(AmmoType eAmmoType, int nValue);	

	void restartGame();

private:


};