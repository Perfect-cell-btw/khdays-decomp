/* Ov256_AiDispatchAction -- ov256's move dispatcher, with a BOSS PHASE TRANSITION bolted on the
 * front. The dispatcher half is the usual family shape; the interesting part is the check that
 * runs before it.
 *
 * Accumulated damage lives at ctx+0x48 and the phase counter at ctx+0x68. A transition is due
 * when:
 *   phase 0 -- damage has reached 0x2d000
 *   phase 1 -- damage has reached 0xb0000   (so phase 1 takes nearly four times as much)
 *   phase 2+ -- damage has reached 0x2d000 again
 * ...and from phase 2 on it is only a 50/50: on the other half the damage counter is simply reset
 * and the boss stays put, so late phases can be survived twice.
 *
 * A transition zeroes the damage, bumps the phase, raises the flag at ctx+0x78 (the same
 * "alternate stance" flag ov221/ov225/ov227 gate their hw60 on) and queues move 6. The flag at
 * ctx+0x7c queues move 6 too, unconditionally -- so something else can force the same transition
 * animation.
 *
 * ctx[0]+0x45c == 4 disables the whole thing: presumably the death state.
 *
 * Written with gotos because the three damage/phase tests all converge on one transition block and
 * the ROM branches them there directly; nesting them duplicates it.
 *
 * Case 0 is absent from the switch. Every case body is 20 bytes here (not the usual 16) because
 * self lives in r5 and each arm restores r0 -- that is normal for this function, not extra code. */

typedef struct {
    unsigned short lo : 8;
    unsigned short hi : 8;
} Hw60;

typedef struct {
    unsigned f : 8;
} B8;

extern int RandNextScaled(int n);
extern void SetIndexedSlot(int self, int slot, void (*cb)(void));
extern void Ov256_EnterState(void);
extern void Ov256_AiEnterThink(void);
extern void Ov256_AiEnterStep(void);
extern void Ov256_AiEnterWalk(void);
extern void Ov256_AiArmClawsAndStep(void);
extern void Ov256_AiEnterLeap(void);
extern void Ov256_AiEnterPounce(void);
extern void Ov256_AiEnterClawWindup(void);
extern void Ov256_AiEnterCharge(void);
extern void Ov256_AiEnterClawLob(void);
extern void Ov256_ClawLobTick(void);
extern void Ov256_ClawThrowEntry(void);
extern void Ov256_AiEnterStomp(void);
extern void Ov256_AiEnterCollapse(void);
extern void Ov256_TickFall(void);

void Ov256_AiDispatchAction(int self) {
    int *ctx;

    ctx = *(int **)(self + 4);
    if (*(signed char *)(ctx[0] + 0x1c7) == -1) {
        goto tail;
    }

    if (*(int *)(ctx[0] + 0x45c) != 4) {
        if (ctx[0x12] >= 0x2d000 && *(unsigned char *)((char *)ctx + 0x68) == 0) {
            goto transition;
        }
        if (ctx[0x12] >= 0xb0000 && *(unsigned char *)((char *)ctx + 0x68) == 1) {
            goto transition;
        }
        if (ctx[0x12] < 0x2d000) {
            goto forced;
        }
        if (*(unsigned char *)((char *)ctx + 0x68) < 2) {
            goto forced;
        }

    transition:
        if (*(unsigned char *)((char *)ctx + 0x68) >= 2
            && (unsigned int)RandNextScaled(100) > 0x32) {
            ctx[0x12] = 0;
            goto forced;
        }
        ctx[0x12] = 0;
        *(unsigned char *)((char *)ctx + 0x68) = *(unsigned char *)((char *)ctx + 0x68) + 1;
        ctx[0x1e] = 1;
        *(signed char *)(ctx[0] + 0x1c7) = 6;
    }

forced:
    if (ctx[0x1f] != 0) {
        *(signed char *)(ctx[0] + 0x1c7) = 6;
    }

    *(signed char *)(ctx[0] + 0x1c6) = *(signed char *)(ctx[0] + 0x1c7);
    ((Hw60 *)(ctx[0] + 0x60))->hi &= ~0x86;
    *(unsigned short *)(ctx[0] + 0x1ae) &= ~3;
    ((B8 *)(*(int *)(ctx[0] + 0x428) + 8))->f |= 1;

    switch (*(signed char *)(ctx[0] + 0x1c6)) {
    case 1:
        SetIndexedSlot(self, 1, Ov256_EnterState);
        break;
    case 2:
        SetIndexedSlot(self, 1, Ov256_AiEnterThink);
        break;
    case 3:
        SetIndexedSlot(self, 1, Ov256_AiEnterWalk);
        break;
    case 4:
        SetIndexedSlot(self, 1, Ov256_AiEnterStep);
        break;
    case 5:
        SetIndexedSlot(self, 1, Ov256_AiArmClawsAndStep);
        break;
    case 6:
        SetIndexedSlot(self, 1, Ov256_AiEnterLeap);
        break;
    case 7:
        SetIndexedSlot(self, 1, Ov256_AiEnterPounce);
        break;
    case 8:
        SetIndexedSlot(self, 1, Ov256_AiEnterClawWindup);
        break;
    case 9:
        SetIndexedSlot(self, 1, Ov256_AiEnterCharge);
        break;
    case 10:
        SetIndexedSlot(self, 1, Ov256_AiEnterClawLob);
        break;
    case 11:
        SetIndexedSlot(self, 1, Ov256_ClawThrowEntry);
        break;
    case 12:
        SetIndexedSlot(self, 1, Ov256_ClawLobTick);
        break;
    case 13:
        SetIndexedSlot(self, 1, Ov256_AiEnterStomp);
        break;
    case 14:
        SetIndexedSlot(self, 1, Ov256_AiEnterCollapse);
        break;
    case 15:
        SetIndexedSlot(self, 1, Ov256_TickFall);
        break;
    }

tail:
    *(signed char *)(ctx[0] + 0x1c7) = -1;
}
