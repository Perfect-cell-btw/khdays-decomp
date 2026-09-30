#include "game/engine.h"

extern char *NNSi_FndGetCurrentRootHeap(void);
extern void Ov002_ResetNineSlots(void);
extern void Ov002_ScheduleRetry(void);
extern void Ov002_SetLazyClassEnabled(int mode);
extern void Ov002_StreamFormattedLine(int a, void *b);
extern void Ov002_SetStateRecordStage(void);
extern void Ov002_EnterResultScene(void);
extern void Ov002_TickGameplayState(void);
extern int gOv002IName;

/* Finishes the save step and picks the next screen: the error page when the slot index went
 * negative, otherwise the normal follow-up. */
void *Ov002_FinishSaveStep(void) {
    char *heap = NNSi_FndGetCurrentRootHeap();
    EntityManager_ResetSingleton();
    Ov002_ResetNineSlots();
    Ov002_ScheduleRetry();
    if (*(short *)(heap + 0x8baa) < 0) {
        Ov002_SetLazyClassEnabled(0);
        return (void *)&Ov002_EnterResultScene;
    }
    Ov002_StreamFormattedLine(0, &gOv002IName);
    Ov002_SetStateRecordStage();
    return (void *)&Ov002_TickGameplayState;
}
