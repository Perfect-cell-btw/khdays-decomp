/* When the watched flag clears rolls the move timer and queues action 2. */

#include "game/ai_task.h"
#include "game/engine.h"

extern int SetIndexedSlot();

struct S0 {
    int* field_0;
    char pad[0x224 - 4];
    int field_224;
    int field_228;
};

struct S1 {
    struct S0* field_0;
    char pad4[0x34 - 4];
    int field_34;
    char pad38[0x48 - 0x38];
    unsigned char* field_48;
};

struct S2 {
    AI_TASK_FIELDS(struct S1)
};

void Ov132_AiRollTimerQueue2(struct S2* a) {
    struct S1* b = a->pState;
    if (*b->field_48 != 0) {
        return;
    }
    {
        struct S0* c = b->field_0;
        int lo = c->field_224;
        int diff = c->field_228 - lo;
        if (diff < 0) diff = -diff;
        b->field_34 = lo + RandNextScaled(diff + 1);
    }
    *(unsigned char*)((char*)b->field_0 + 0x1c7) = 2;
    SetIndexedSlot(a, a->slot, 0);
}
