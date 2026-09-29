#include "game/ov006_mission_mode_select.h"
#include "game/engine.h"
/* Ov006_MissionGetCursorEntry -- Mission Mode: which menu entry is the cursor on?
 * Returns 0 while the scene is locked out (obj+0x4e8 set), the live cursor index
 * (Session_GetLocalPlayerIndex) once the entry is selectable, and 0xff otherwise. */
extern int Ov006_IsSceneState4(void);
#define MISSION_CONTEXT (data_ov006_020565e4.pContext)

#define OBJ ((int *)data_ov006_020565e4.pContext)

int Ov006_MissionGetCursorEntry(void) {
    unsigned short entry = 0xff;
    if (OBJ[0x13a] != 0) {
        entry = 0;
    } else if (Ov006_IsSceneState4() != 0) {
        entry = (unsigned short)Session_GetLocalPlayerIndex();
    }
    return entry;
}
