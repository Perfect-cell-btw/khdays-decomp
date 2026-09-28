/* Ov253_SubStateDispatchC -- sub-state dispatcher: in kind 5 a +0x3bc target whose +0x1e4 carries
 * flag 4 has its +0x18c rider refreshed and released (020ad8e0 / 020ad838), bits 1 and 7 of
 * its +0x60 high byte cleared, is dropped and sub-state 2 requested; then a requested
 * sub-state (+0x1c7) clears bits 1, 3, 6-7 of the actor's +0x60 high byte, bit 0 of +0x1ae and
 * of the +0x3b4 item's +8 low byte, becomes the +0x1c6 kind and installs the matching slot 1
 * node (0: 020cf04c, 1: 020cf244, 2: 020cf35c, 4: 020cf5f4, 5: 020cfbc4, 6: 020d09a8,
 * 3: 020d0bbc, 7: 020d0cac); the request is then cleared (-1). */
#include "nitro/types.h"
struct w8 { unsigned int lo : 8, rest : 24; };

extern void Ov022_ToggleBit13ByMode(int target, int a);
extern void func_ov022_020ad838(int target, int a);
extern void SetIndexedSlot(int *node, int slot, void *cb);
extern void Ov253_stSetDispFlags82(void);
extern void Ov253_ChargeEnter(void);
extern void Ov253_IdleEnter(void);
extern void Ov253_ReleaseEnter(void);
extern void Ov253_ShoutEnter(void);
extern void Ov253_AiEnterTaunt(void);
extern void Ov253_StunEnter(void);
extern void Ov253_BeginAnim3AndReset(void);

void Ov253_SubStateDispatchC(int *node) {
    int *state = (int *)node[1];

    if (*(signed char *)(*state + 0x100 + 0xc6) == 5) {
        int target = *(int *)(*state + 0x3bc);
        if (target != 0 && (*(int *)(target + 0x1e4) & 4) != 0) {
            Ov022_ToggleBit13ByMode(*(int *)(target + 0x18c), 0);
            func_ov022_020ad838(*(int *)(*(int *)(*state + 0x3bc) + 0x18c), 0);
            {
                int t = *(int *)(*state + 0x3bc);
                u16 hw = *(u16 *)(t + 0x60);
                *(u16 *)(t + 0x60) = (hw & ~0xff00) |
                    (((unsigned int)(unsigned short)((((unsigned int)hw << 0x10) >> 0x18) & ~0x82) << 0x18) >> 0x10);
            }
            *(int *)(*state + 0x3bc) = 0;
            *(unsigned char *)(*state + 0x1c7) = 2;
        }
    }
    if (*(signed char *)(*state + 0x100 + 0xc7) == -1) {
        return;
    }
    {
        u16 hw = *(u16 *)(*state + 0x60);
        *(u16 *)(*state + 0x60) = (hw & ~0xff00) |
            (((unsigned int)(unsigned short)((((unsigned int)hw << 0x10) >> 0x18) & ~0xca) << 0x18) >> 0x10);
    }
    *(u16 *)(*state + 0x100 + 0xae) &= ~1;
    ((struct w8 *)(*(int *)(*state + 0x3b4) + 8))->lo &= ~1;
    *(signed char *)(*state + 0x1c6) = *(signed char *)(*state + 0x100 + 0xc7);
    switch (*(signed char *)(*state + 0x100 + 0xc6)) {
    case 0:
        SetIndexedSlot(node, 1, Ov253_stSetDispFlags82);
        break;
    case 1:
        SetIndexedSlot(node, 1, Ov253_ChargeEnter);
        break;
    case 2:
        SetIndexedSlot(node, 1, Ov253_IdleEnter);
        break;
    case 4:
        SetIndexedSlot(node, 1, Ov253_ReleaseEnter);
        break;
    case 5:
        SetIndexedSlot(node, 1, Ov253_ShoutEnter);
        break;
    case 6:
        SetIndexedSlot(node, 1, Ov253_AiEnterTaunt);
        break;
    case 3:
        SetIndexedSlot(node, 1, Ov253_StunEnter);
        break;
    case 7:
        SetIndexedSlot(node, 1, Ov253_BeginAnim3AndReset);
        break;
    }
    *(signed char *)(*state + 0x1c7) = -1;
}
