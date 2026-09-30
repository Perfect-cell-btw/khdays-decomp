/* When the calendar ends, sets the new day, resets the day state and the party, and requests the
 * next scene. */

#include "nitro/types.h"
#include "game/engine.h"

#include "game/scene.h"
typedef struct BootModeState {
    u8 flags;
    u8 state;
    u16 elapsed;
    u16 resetWord;
} BootModeState;

typedef struct Ov004SceneState {
    void *task;
    int selectedDay;
} Ov004SceneState;

extern Ov004SceneState *data_ov004_02051380;
extern BootModeState data_0204c240;

extern int Ov004_GetResult(void);
extern void Ov004_ResetPartyMemberAndLayout(int arg, int unused);

int Ov004_StepMissionSelectScene(void) {
    if (Ov004_GetResult() != 0) {
        GameState_ClearFlag(0x18ae);
        GameState_SetField(0, 9, (u16)data_ov004_02051380->selectedDay);

        data_0204c240.elapsed =
            data_ov004_02051380->selectedDay == 0x165 ? 0x2711 : 0x2710;
        data_0204c240.resetWord = 0;
        data_0204c240.state = 0;

        PartyState_ResetBuffers();
        Ov004_ResetPartyMemberAndLayout(0, 0);
        Scene_RequestPending(SCENE_FIELD, 0);
        return -2;
    }
    return 0;
}
