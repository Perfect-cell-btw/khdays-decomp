/* Ov211_AiDispatchAction -- ov210's move dispatcher: play whatever move is queued at ctx[0]+0x1c7 and
 * clear the slot. Third of its kind after Ov228_AiDispatchAction and Ov231_AiDispatchAction, and the
 * same shape: -1 means nothing queued, the id is copied to +0x1c6 and it is that copy the switch
 * reads, and the slot is cleared on every path.
 *
 * The reset before dispatching: hw60 hi loses 0xce, bit 0 of the halfword at +0x1ae is cleared,
 * and bit 0 of the byte field at *(ctx[0]+0x3b0)+8 is set.
 *
 * Source case order is 0,1,2,4,5,6,7,8,9,10,11,12,13,14,15,16,3,17,18 -- the order the ROM lays
 * the bodies out, which with a jump table IS the source order (the table itself is index-ordered).
 * Case 3 sitting late is the third dispatcher in a row to do this, so whatever move id 3 is, it
 * was added to all of them after the fact.
 *
 * The hw60 write HAS the `lsl#0x10 ; lsr#0x10` trunc pair -> bitfield form; the field at +8 is a
 * byte-in-word. See codegen-cracks.md. */

typedef struct {
    unsigned short lo : 8;
    unsigned short hi : 8;
} Hw60;

typedef struct {
    unsigned f : 8;
} B8;

extern void SetIndexedSlot(int self, int slot, void (*cb)(void));
extern void Ov211_AiLockAndPostUpdate(void);
extern void Ov211_AiEnterRecover(void);
extern void Ov211_SeedRandomTimer(void);
extern void Ov211_PickMeleeReaction(void);
extern void Ov211_RiseDecision(void);
extern void Ov211_FlagsKickSubNode(void);
extern void Ov211_EnterLeap(void);
extern void Ov211_AimSetupNotifyArm(void);
extern void Ov211_AiEnterFire(void);
extern void Ov211_EnterRiseStrike(void);
extern void Ov211_AiEnterSteerFire(void);
extern void Ov211_AiEnterAim(void);
extern void Ov211_AcquireOrTimedRecover(void);
extern void Ov211_AcquireOrTimedRecoverB(void);
extern void Ov211_AiEnterRise(void);
extern void Ov211_BeginPounce(void);
extern void Ov211_SpawnEffect4dReconfigureFlags(void);
extern void Ov211_EnterRise(void);
extern void Ov211_AiEnterDefeat(void);

void Ov211_AiDispatchAction(int self) {
    int *ctx;

    ctx = *(int **)(self + 4);
    if (*(signed char *)(ctx[0] + 0x1c7) != -1) {
        *(signed char *)(ctx[0] + 0x1c6) = *(signed char *)(ctx[0] + 0x1c7);
        ((Hw60 *)(ctx[0] + 0x60))->hi &= ~0xce;
        *(unsigned short *)(ctx[0] + 0x1ae) &= ~1;
        ((B8 *)(*(int *)(ctx[0] + 0x3b0) + 8))->f |= 1;

        switch (*(signed char *)(ctx[0] + 0x1c6)) {
        case 0:
            SetIndexedSlot(self, 1, Ov211_AiLockAndPostUpdate);
            break;
        case 1:
            SetIndexedSlot(self, 1, Ov211_AiEnterRecover);
            break;
        case 2:
            SetIndexedSlot(self, 1, Ov211_SeedRandomTimer);
            break;
        case 4:
            SetIndexedSlot(self, 1, Ov211_PickMeleeReaction);
            break;
        case 5:
            SetIndexedSlot(self, 1, Ov211_RiseDecision);
            break;
        case 6:
            SetIndexedSlot(self, 1, Ov211_FlagsKickSubNode);
            break;
        case 7:
            SetIndexedSlot(self, 1, Ov211_EnterLeap);
            break;
        case 8:
            SetIndexedSlot(self, 1, Ov211_AimSetupNotifyArm);
            break;
        case 9:
            SetIndexedSlot(self, 1, Ov211_AiEnterFire);
            break;
        case 10:
            SetIndexedSlot(self, 1, Ov211_AiEnterSteerFire);
            break;
        case 11:
            SetIndexedSlot(self, 1, Ov211_AiEnterAim);
            break;
        case 12:
            SetIndexedSlot(self, 1, Ov211_AcquireOrTimedRecover);
            break;
        case 13:
            SetIndexedSlot(self, 1, Ov211_AcquireOrTimedRecoverB);
            break;
        case 14:
            SetIndexedSlot(self, 1, Ov211_AiEnterRise);
            break;
        case 15:
            SetIndexedSlot(self, 1, Ov211_BeginPounce);
            break;
        case 16:
            SetIndexedSlot(self, 1, Ov211_EnterRiseStrike);
            break;
        case 3:
            SetIndexedSlot(self, 1, Ov211_SpawnEffect4dReconfigureFlags);
            break;
        case 17:
            SetIndexedSlot(self, 1, Ov211_EnterRise);
            break;
        case 18:
            SetIndexedSlot(self, 1, Ov211_AiEnterDefeat);
            break;
        }
    }

    *(signed char *)(ctx[0] + 0x1c7) = -1;
}
