/*
 * Ov002_UpdatePendingRequest - advance the pending-request record at root-context+0x8dc0
 * (a u16 slot at +0x8dc0 and a u8 tag at +0x8dc2). Called from the ov002 gameplay constructor
 * (Ov002_ConstructGameplayScene).
 *
 * If the session is active (Session_IsReady != 0) and the record's tag matches the current
 * source id (GetGlobalU16At6): when the slot is unallocated (0xffff) it allocates a new one via
 * Ov002_BuildSessionCommand(0x1a, ...) and stores it; otherwise it polls MsgQueue_Contains(slot) and,
 * if that returns 0 (complete), marks the request done. If the session is NOT active: when the
 * tag differs it builds a 2-byte notification (tag 0x19 + Session_GetLocalPlayerIndex()) and sends it via
 * MsgQueue_SendGate(7, ..., 2); when it matches it marks the request done.
 *
 * On "done" it resets the slot to 0xffff and the tag to 0 and returns the follow-up handler
 * Ov002_TickGameplayState; otherwise it returns NULL. THUMB. The slot value is passed to
 * MsgQueue_Contains (it is not a no-arg call), which is what keeps it in r0 across the poll.
 */

#include "nitro/types.h"

extern int  Session_IsReady(void);
extern unsigned short  GetGlobalU16At6(void);
extern u16  Ov002_BuildSessionCommand(int kind, void *out);
extern int  MsgQueue_Contains(int slot);
extern int  Session_GetLocalPlayerIndex(void);
extern void MsgQueue_SendGate(int a, void *b, int c);
extern void Ov002_TickGameplayState(void);
extern int  data_ov002_0207fa00;

void *Ov002_UpdatePendingRequest(void)
{
    char *ctx = (char *)data_ov002_0207fa00;
    char local[4];
    int ok = 0;

    if (Session_IsReady() != 0) {
        if (*(u8 *)(ctx + 0x8dc2) == GetGlobalU16At6()) {
            u16 slot = *(u16 *)(ctx + 0x8dc0);
            if (slot == 0xffff) {
                *(u16 *)(ctx + 0x8dc0) = Ov002_BuildSessionCommand(0x1a, local);
            } else {
                if (MsgQueue_Contains(slot) == 0) ok = 1;
            }
        }
    } else {
        if (*(u8 *)(ctx + 0x8dc2) != GetGlobalU16At6()) {
            local[1] = 0x19;
            local[2] = Session_GetLocalPlayerIndex();
            MsgQueue_SendGate(7, local + 1, 2);
        } else {
            ok = 1;
        }
    }
    if (ok != 0) {
        *(u16 *)(ctx + 0x8dc0) = 0xffff;
        *(u8 *)(ctx + 0x8dc2) = 0;
        return (void *)Ov002_TickGameplayState;
    }
    return 0;
}
