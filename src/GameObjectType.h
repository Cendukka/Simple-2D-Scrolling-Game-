#pragma once
#ifndef __GAME_OBJECT_TYPE__
#define __GAME_OBJECT_TYPE__
enum GameObjectType {
	NONE = -1,
	PLAYER,
	ENEMY,
	CASH,
	DYNAMITE,	
	START_BUTTON,
	INSTRU_BUTTON,
	EXIT_BUTTON,
	NEXT_LEVEL_BUTTON,
	BACK_GROUND,
	POWER_UP,
	NUM_OF_TYPES
};

#endif /* defined (__GAME_OBJECT_TYPE__)*/