/* Network join/leave message: forwards requests from the host and applies confirmed joins (1/2) and
 * leaves (3/4). */

#include "game/enemy_common.h"

typedef struct Msg {
    char pad0[2];
    unsigned char field_2;
    unsigned char field_3;
} Msg;

typedef struct Res {
    char pad0[0x14];
    void (*field_14)(struct Res *self, int arg);
    char pad1[0x40 - 0x14 - 4];
    unsigned int field_40;
} Res;

typedef struct Ov107 {
    char pad[0xf8];
    unsigned int field_f8;
} Ov107;

extern unsigned int Session_GetLocalPlayerIndex(void);
extern void func_02031384(int cmd, Msg *msg, unsigned short val);

void Ov107_Region_OnSyncMessage(Ov107 *self, Msg *msg, int arg2)
{
    unsigned char state = msg->field_2;

    if (state == 1) {
        if (Session_GetLocalPlayerIndex() != 0) {
            return;
        }
        msg->field_2 = 2;
        func_02031384(4, msg, (unsigned short)arg2);
    } else if (state == 2) {
        Res *res = Ov107_FindMessageHandler(msg->field_3);
        Ov107_InitObjectFromSource((int)self, (int)res);
        res->field_40 |= 4;
        if (res->field_14) {
            res->field_14(res, 1);
        }
        self->field_f8 &= ~0xf;
    } else if (state == 3) {
        if (Session_GetLocalPlayerIndex() != 0) {
            return;
        }
        msg->field_2 = 4;
        func_02031384(4, msg, (unsigned short)arg2);
    } else if (state == 4) {
        Res *res = Ov107_FindMessageHandler(msg->field_3);
        Ov107_InvokeSlot0x74((int)self, (int)res);
        res->field_40 &= ~4;
        self->field_f8 &= ~0xf;
    }
}
