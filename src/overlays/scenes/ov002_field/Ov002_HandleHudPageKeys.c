/*
 * Ov002_HandleHudPageKeys - turn the tutorial pages, or close them.
 *
 * R steps to the next page when there is one. L steps back: the record stream
 * is rewound and replayed up to the start of the previous page, two records a
 * page or four in the wide layout. Start only answers on the last page - it
 * asks for the closing caption, or arms state 3 when the page owns a follow-up
 * - then raises this tutorial's game flag and plays the closing sound.
 *
 * THUMB.
 */

#include "nitro/types.h"

extern int *data_ov002_0207f9fc;
extern u16 data_0204c190;

extern int Ov002_Res_GetCount(void *pStream);
extern void Ov002_Res_BindSecondBlock(void *pStream);
extern void *Ov002_NextStreamRecord(void *pStream);
extern void Ov002_ArmScene(u16 nPage);
extern int Ov002_Field_HasPendingEvent(void);
extern void Ov002_RequestCaption(int nMode, int nTake);
extern void GameState_SetFlag(int nEvent);
extern void PlaySound(int nBank, int nCue);

void Ov002_HandleHudPageKeys(void)
{
    int hud;
    int nNext;
    int nStep;
    int i;

    hud = (int)data_ov002_0207f9fc;
    if ((data_0204c190 & 0x100) != 0) {
        nNext = *(u16 *)(hud + 2) + 1;
        if (nNext < Ov002_Res_GetCount((void *)(hud + 0xc))) {
            Ov002_ArmScene((u16)nNext);
            PlaySound(0, 2);
        }
    } else if ((data_0204c190 & 0x200) != 0) {
        if (*(u16 *)(hud + 2) != 0) {
            if (*(int *)(hud + 0x30) != 0) {
                nStep = 4;
            } else {
                nStep = 2;
            }
            Ov002_Res_BindSecondBlock((void *)(hud + 0xc));
            for (i = 0; i < (*(u16 *)(hud + 2) - 1) * nStep; i++) {
                Ov002_NextStreamRecord((void *)(hud + 0xc));
            }
            Ov002_ArmScene((u16)(*(u16 *)(hud + 2) - 1));
            PlaySound(0, 2);
        }
    } else if ((data_0204c190 & 8) != 0) {
        if (*(u16 *)(hud + 2) + 1 >= Ov002_Res_GetCount((void *)(hud + 0xc))) {
            if (*(int *)(hud + 0x1a8) == 0) {
                if (Ov002_Field_HasPendingEvent() != 0) {
                    Ov002_RequestCaption(2, 0);
                } else {
                    Ov002_RequestCaption(0, 0);
                }
            } else {
                *(int *)(hud + 0x28) = 3;
            }
            GameState_SetFlag(*(u16 *)hud + 0x3c2b);
            PlaySound(0, 0xa);
        }
    }
}
