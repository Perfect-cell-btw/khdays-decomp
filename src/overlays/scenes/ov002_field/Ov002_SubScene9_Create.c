#include "game/engine.h"

extern char *NNSi_FndGetCurrentRootHeap(void);
extern void INITi_CpuClear32_0x01ff86fc(int value, void *dst, int size);
extern char *data_ov002_0207fa08;
extern void Ov002_StartSession(void);
extern void Ov002_SubScene9_IdleStep(void);

/* Allocates the state block for sub-scene 9 out of the root heap, seeds it from the
 * caller's config and picks the first tick depending on whether the load started. */
void *Ov002_SubScene9_Create(int *cfg) {
    char *st = NNSi_FndGetCurrentRootHeap();
    *(char **)&data_ov002_0207fa08 = st;
    *(int *)st = 9;
    *(int *)(st + 0xc) = *cfg;
    *(int *)(st + 0x10) = 0;
    *(int *)(st + 0x14) = 0;
    INITi_CpuClear32_0x01ff86fc(0, st + 0x18, 8);
    if (Session_IsReady() != 0) {
        return (void *)&Ov002_StartSession;
    }
    return (void *)&Ov002_SubScene9_IdleStep;
}
