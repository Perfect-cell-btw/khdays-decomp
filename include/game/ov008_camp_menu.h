/* ov008 (camp menu, Mission Mode lobby): the overlay's globals shared between its sources. */
#ifndef GAME_OV008_CAMP_MENU_H
#define GAME_OV008_CAMP_MENU_H

#include "game/mission_lobby.h"

/* The mission globals (.bss 0x02090f24; defined as a word array in data/ov008_bss_02090f14.c,
 * whose layout that file proves). */
extern MissionGlobals data_ov008_02090f24;

#endif
