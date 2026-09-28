
#include "nitro/types.h"

extern void *Ov002_GetModuleScale(char *pElement);
extern int Ov002_AdvanceElementClock(char *pElement, char *pAnim, void *pCtx,
                               int nMode, int nRange, void *pOut);
extern void Ov002_ParkSpareEntry(void *pElement);
extern void Ov002_ElementStartTrack(char *pElement, short *pAnim, int nTrack,
                                int nParamA, int nParamB, int bEffect);
extern int Session_GetLocalPlayerIndex(void);
extern int Ov002_RecordElementHit(void *pElement, void *pMsg, int nKind);
extern unsigned int GameState_GetField(int nField, int nWidth);
extern void GameState_SetField(unsigned int nField, unsigned int nWidth, unsigned int nValue);
extern void Ov002_SetFieldBit0(char *pElement, int nMode);
extern void ReleaseNodeResources(char *pObj);
extern void Scene_DrawNode(u16 *pAnim);

/* Run one step of a line element's second model.
 *
 * Step 0 just keeps the model advancing. Step 2 starts the model's own track,
 * taking the speed from the owner and running the special case the owner names,
 * then moves to step 3. Step 3 advances the model, reports the hit once the
 * owner's distance is reached, and when both the advance and the report are
 * done either turns the model round for its return or, for a short owner,
 * releases the element. Whatever happened, an active model is stepped at the
 * end.
 */
int Ov002_TravelElementStep(char *pElement)
{
    char *pOwner;
    void *pCtx;
    int bDone;
    unsigned int nState;
    u8 aMsg[4];

    pOwner = *(char **)(pElement + 8);
    pCtx = Ov002_GetModuleScale(pElement);

    switch (*(u8 *)(pElement + 0x2c1)) {
    case 0:
        Ov002_AdvanceElementClock(pElement, pElement + 0x1b0, pCtx, 1,
                            *(int *)(pElement + 0x2bc), pElement + 0x2b8);
        break;

    case 2:
        if (*(short *)(pOwner + 0x74) == 0x35) {
            Ov002_ParkSpareEntry(pElement);
        }

        *(u8 *)(pElement + 0x2c0) = 1;
        *(int *)(pElement + 0x2bc) = *(short *)(pOwner + 0x7a) << 12;

        Ov002_ElementStartTrack(pElement, (short *)(pElement + 0x1b0),
                            *(u8 *)(pElement + 0x2c0),
                            *(int *)(pElement + 0x2bc), 0, 1);

        *(u16 *)(pElement + 0x12) &= ~8;
        *(u8 *)(pElement + 0x2c1) = 3;
        break;

    case 3:
        bDone = Ov002_AdvanceElementClock(pElement, pElement + 0x1b0, pCtx, 0,
                                    *(int *)(pElement + 0x2bc),
                                    pElement + 0x2b8) == 0;

        if ((*(u8 *)(pElement + 0x2c3) & 1) == 0
            && (*(int *)(pElement + 0x2b8) >> 12) >= *(short *)(pOwner + 0x7c)
            && Session_GetLocalPlayerIndex() == 0) {
            aMsg[0] = 2;
            if (Ov002_RecordElementHit(pElement, aMsg, 4) != 0) {
                *(u8 *)(pElement + 0x2c3) |= 1;
            }
        }

        if (bDone && (*(u8 *)(pElement + 0x2c3) & 1) != 0) {
            *(u8 *)(pElement + 0x2c1) = 4;

            if (*(signed char *)(pOwner + 0x78) > 2) {
                *(u8 *)(pElement + 0x2c0) = 2;
                *(int *)(pElement + 0x2bc) = 0;

                nState = GameState_GetField(*(u16 *)(pElement + 0x14), *(u8 *)(pElement + 0x16));
                GameState_SetField(*(u16 *)(pElement + 0x14), *(u8 *)(pElement + 0x16),
                                   (u16)((nState & ~0xfffe) | 2));

                Ov002_ElementStartTrack(pElement, (short *)(pElement + 0x1b0),
                                    *(u8 *)(pElement + 0x2c0),
                                    *(int *)(pElement + 0x2bc), 0, 0);
            } else if (*(signed char *)(pOwner + 0x7e) != 0) {
                Ov002_SetFieldBit0(pElement, 0);

                if ((*(u16 *)(pElement + 0x12) & 2) != 0) {
                    ReleaseNodeResources(pElement + 0x2c);
                    *(u16 *)(pElement + 0x12) &= ~2;
                }
            }
        }
        break;
    }

    if ((*(u16 *)(pElement + 0x12) & 4) != 0) {
        Scene_DrawNode((u16 *)(pElement + 0x1b0));
    }

    return 0;
}
