/*
 * Ov002_BeginMissionRun - answer the session request and start the run.
 *
 * Nothing happens until the session request goes through. Once it does, the
 * scene's ready hook runs, the world is put to sleep unless it was never armed,
 * and the saved slot decides whether this is a fresh run: with no slot the
 * remembered pair is blanked and the "no save" bit raised, otherwise the bit is
 * dropped. The run then takes over and the mission step is handed back.
 *
 * THUMB.
 */

#include "nitro/types.h"
#include "game/engine.h"

extern char *NNSi_FndGetCurrentRootHeap(void);
extern int Ov002_TickSessionRequest(void);
extern void Ov002_EnterState2AndBlankIds(void);
extern void Ov002_SetSceneObjectsActive(int bActive);
extern void Ov002_SetLazyClassEnabled(int bEnabled);
extern void Ov002_SessionTick(void);

void *Ov002_BeginMissionRun(void)
{
    char *ctx;
    void *pfnStep;

    ctx = NNSi_FndGetCurrentRootHeap();
    pfnStep = 0;
    if (Ov002_TickSessionRequest() != 0) {
        if (*(void (**)(void))(ctx + 0x8b88) != 0) {
            (*(void (**)(void))(ctx + 0x8b88))();
        }
        if (*(int *)(ctx + 0x8bcc) != -1) {
            Ov002_EnterState2AndBlankIds();
            Ov002_SetSceneObjectsActive(0);
        }
        if (LoadGlobalS8At0() == -1) {
            if ((*(u8 *)(ctx + 0x8d0c) & 1) == 0) {
                *(u16 *)(ctx + 0x8d0e) = 0;
                *(char *)(ctx + 0x8d0d) = -1;
            }
            *(u8 *)(ctx + 0x8d0c) |= 1;
        } else {
            *(u8 *)(ctx + 0x8d0c) &= ~1;
        }
        func_02020878(1);
        Ov002_SetLazyClassEnabled(0);
        pfnStep = Ov002_SessionTick;
    }
    return pfnStep;
}
