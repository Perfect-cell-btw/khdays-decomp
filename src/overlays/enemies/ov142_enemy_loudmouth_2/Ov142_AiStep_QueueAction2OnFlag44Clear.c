/* AI step: when the byte behind context +0x44 is clear, pendingAction (+0x1c7) = 2 and the step
 * handler is cleared. */

#include "game/ai_task.h"

extern int SetIndexedSlot();

struct Inner {
    unsigned char *ptr0;
    char pad4[0x40];
    unsigned char *ptr44;
};

struct Obj {
    AI_TASK_FIELDS(struct Inner)
};

void Ov142_AiStep_QueueAction2OnFlag44Clear(struct Obj *obj) {
    struct Inner *inner = obj->pState;
    if (inner->ptr44[0] != 0) {
        return;
    }
    inner->ptr0[0x1c7] = 2;
    SetIndexedSlot(obj, obj->slot, 0);
}
