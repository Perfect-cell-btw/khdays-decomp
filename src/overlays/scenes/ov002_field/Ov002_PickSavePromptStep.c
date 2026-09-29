#include "game/engine.h"

extern char *NNSi_FndGetCurrentRootHeap(void);
extern int Ov002_IsLocalPlayerCurrent(void);
extern int Ov002_Hud_IsPanelOpen(void);
extern int Ov002_HasLinkIdAssigned(void);
extern void Ov002_StepSessionEvent(void);

/* Picks the follow-up step for the save prompt: the confirm page when the slot is usable and
 * nothing else objects, otherwise nothing. */
void *Ov002_PickSavePromptStep(void) {
    *(char *)(NNSi_FndGetCurrentRootHeap() + 0x8b68) = 0x20;
    if (Ov002_IsLocalPlayerCurrent() != 0 && Ov002_Hud_IsPanelOpen() == 0) {
        if (Session_IsReady() != 0 && Ov002_HasLinkIdAssigned() == 0) {
            return 0;
        }
        return (void *)&Ov002_StepSessionEvent;
    }
    return 0;
}
