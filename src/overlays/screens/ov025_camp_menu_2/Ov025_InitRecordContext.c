/* Zeroes the 0x100-byte context, installs the fetch/dispatch callbacks (defaults MsgDb_FetchRecord
 * / DispatchByNodeKind) and inits its three lists. */

#include "game/engine.h"

extern void MI_CpuFill8();
extern void NNS_FndInitList();

typedef struct {
    char pad0[8];
    char field8[12];
    char field20[12];
    char field32[16];
    char pad48[0xc8];
    void *field248;
    void *field252;
} Struct;

void Ov025_InitRecordContext(void *a, void **b) {
    Struct *s = (Struct *)a;
    MI_CpuFill8(s, 0, 0x100);
    if (b == 0) {
        s->field248 = (void *)MsgDb_FetchRecord;
        s->field252 = (void *)DispatchByNodeKind;
    } else {
        s->field248 = b[0] ? b[0] : (void *)MsgDb_FetchRecord;
        s->field252 = b[1] ? b[1] : (void *)DispatchByNodeKind;
    }
    NNS_FndInitList(s->field8, 0x18);
    NNS_FndInitList(s->field20, 0x18);
    NNS_FndInitList(s->field32, 0x10);
}
