/* Scene entry gate: refuse (reporting no step) while data_0204be04 is set, and
 * again if Ov002_TickSessionRequest finds nothing to show. Only then close the
 * pending dialog and run the setup, handing back the step at
 * Ov002_TeardownGameplayScene. NNSi_FndGetCurrentRootHeap is called for its side effect
 * only -- the ROM discards r0. */

#include "game/engine.h"

extern void *NNSi_FndGetCurrentRootHeap(void);
extern int Ov002_TickSessionRequest(void);
extern void Ov002_UpdatePartyEntries(void);
extern void Ov002_TeardownGameplayScene(void);

extern unsigned char data_0204be04;

void *Ov002_EnterDialogSceneIfAllowed(void) {
    NNSi_FndGetCurrentRootHeap();

    if (data_0204be04 != 0) {
        return 0;
    }
    if (Ov002_TickSessionRequest() == 0) {
        return 0;
    }

    SetGameMode(0);
    Ov002_UpdatePartyEntries();
    return (void *)&Ov002_TeardownGameplayScene;
}
