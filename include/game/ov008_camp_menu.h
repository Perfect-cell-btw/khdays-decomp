/* ov008 (camp menu, Mission Mode lobby): the overlay's globals shared between its sources. */
#ifndef GAME_OV008_CAMP_MENU_H
#define GAME_OV008_CAMP_MENU_H

/* The mission globals, 28 bytes of .bss at 0x02090f24 (defined as a word array in
 * data/ov008_bss_02090f14.c, whose layout that file proves). */
typedef struct Ov008MissionGlobals {
    void *pContext;     /* +0x00: the mission context, a root-heap block (Ov008_MissionLobbyInit) */
    void *pController;  /* +0x04: the controller instance, whose update handler (Obj +0x14) the
                         * lobby and the selection screens swap (Ov008_ArmWirelessCallback) */
    int aUnused[5];     /* +0x08: never read or written by name */
} Ov008MissionGlobals;

extern Ov008MissionGlobals data_ov008_02090f24;

#endif
