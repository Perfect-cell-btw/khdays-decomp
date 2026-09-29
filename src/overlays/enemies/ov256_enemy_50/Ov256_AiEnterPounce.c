/* Play SFX 0x20b7, reset the linked node (+0x454=0), flag +0x80, clear +0x4c/+0x6a, kick anim
 * 0x12 and restart sub-anim 020c9ee8, then dispatch 020cf15c. */

#include "game/engine.h"

extern int Ov107_PostTagUpdate(int, int, int);
extern int Ov107_StartAnim(int, int, int);
extern int SetIndexedSlot(int, int, void *);
extern int Ov256_TickPounceEntry(int);
void Ov256_AiEnterPounce(int param_1) {
    int owner = *(int *)(param_1 + 4);
    GameState_SetField(0x20b7, 8, 1);
    *(int *)(*(int *)owner + 0x454) = 0;
    *(int *)(owner + 0x80) = 1;
    *(int *)(owner + 0x4c) = 0;
    *(unsigned char *)(owner + 0x6a) = 0;
    Ov107_PostTagUpdate(*(int *)owner, 0x12, 0);
    Ov107_StartAnim(*(int *)(*(int *)owner + 0x450), 4, 0);
    SetIndexedSlot(param_1, *(signed char *)(param_1 + 0x20), (void *)&Ov256_TickPounceEntry);
}
