/* Clear +0x30, kick the idle animation, then dispatch via c634. */

#include "game/enemy_common.h"

extern int SetIndexedSlot(int, int, void *);
extern int Ov237_AiComboCount(int);
void Ov237_AiEnterCombo(int param_1) {
    int owner = *(int *)(param_1 + 4);
    *(int *)(owner + 0x30) = 0;
    Ov107_PostTagUpdate((Actor *)(*(int *)owner), 0, 0);
    SetIndexedSlot(param_1, *(signed char *)(param_1 + 0x20), (void *)&Ov237_AiComboCount);
}
