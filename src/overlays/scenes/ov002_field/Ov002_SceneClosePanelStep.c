/*
 * Ov002_SceneClosePanelStep - the step that folds the panel away.
 *
 * Nothing happens while a fade of kind 2 is still running. Once it is clear the
 * surface is closed a frame at a time; when it reports it has finished the two
 * text contexts are torn down (each only if it was ever opened), the scene state
 * goes back to 0, the two palette entries the panel borrowed are put back, and
 * the step that runs with no panel on screen is handed over.
 *
 * ARM.
 */

typedef unsigned short u16;

extern int data_ov002_0207f624;

extern int func_02023c40(void);
extern int func_02023c50(void);
extern void FreeAllListNodeSubBuffers(void *pContext);

extern void Ov002_TickTimedEffect(void *pSurface);
extern void Ov002_SelectEntryByKey(int nKey);
extern void Ov002_SelectEntry(int nId);
extern void Ov002_ReleasePendingRequest(void);
extern int Ov002_PanelIdleState(void);

void *Ov002_SceneClosePanelStep(void)
{
    int *ctx;
    void *pNext;

    pNext = 0;
    ctx = *(int **)&data_ov002_0207f624;
    if (func_02023c40() == 2 && (func_02023c50() & 1) == 1) {
        return 0;
    }

    Ov002_SelectEntryByKey(*(int *)((char *)ctx + 0x69c));
    Ov002_TickTimedEffect((char *)ctx + 0xc);
    Ov002_SelectEntry(0xb);

    if (ctx[3] == 0) {
        Ov002_ReleasePendingRequest();
        if (*(int *)((char *)ctx + 0x7b8) != 0) {
            FreeAllListNodeSubBuffers((char *)ctx + 0x6f8);
            *(int *)((char *)ctx + 0x7b8) = 0;
        }
        if (*(int *)((char *)ctx + 0x7bc) != 0) {
            FreeAllListNodeSubBuffers((char *)ctx + 0x734);
            *(int *)((char *)ctx + 0x7bc) = 0;
        }
        ctx[0] = 0;
        *(volatile u16 *)0x05000180 = 0;
        *(volatile u16 *)0x05000184 = 0x1f9f;
        pNext = Ov002_PanelIdleState;
    }

    Ov002_SelectEntryByKey(*(int *)((char *)ctx + 0x6a0));
    return pNext;
}
