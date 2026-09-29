/* When the watched flag clears rolls the move timer. */

#include "game/ai_task.h"

extern int RandNextScaled();
extern int SetIndexedSlot();

struct Inner {
    char _pad0[0x224];
    int field_224;          /* 0x224 */
    int field_228;          /* 0x228 */
};

struct Sub {
    struct Inner *inner;    /* 0x00 */
    char _pad1[0x40 - 4];
    int field_40;           /* 0x40 */
    char _pad2[0x50 - 0x44];
    unsigned char *p50;     /* 0x50 */
};

struct Flags {
    char _pad[0x1c7];
    unsigned char field_1c7; /* 0x1c7 */
};

struct Obj {
    AI_TASK_FIELDS(struct Sub)
};

void Ov139_AiRollTimerOnFlagClear(struct Obj *this) {
    struct Sub *s = this->pState;
    int base;
    int diff;

    if (*s->p50 != 0) {
        return;
    }

    base = s->inner->field_224;
    diff = s->inner->field_228 - base;
    if (diff < 0) diff = -diff;
    s->field_40 = base + RandNextScaled(diff + 1);

    ((struct Flags *)s->inner)->field_1c7 = 2;

    SetIndexedSlot(this, this->slot, 0);
}
