/* Ov221_AiChaseTick -- the strafe tick: re-acquire the target, then either correct the distance
 * or settle on a facing.
 *
 * Ov221_MeasureTargetGap hands back the range and fills a direction vector; negative means give up,
 * and Ov221_ChooseMove gets a veto too. Both bail through a plain c634 re-entry.
 *
 * With bit 1 of the flags byte at ctx[0]+0x17a clear, the range drives a correction along that
 * direction, folded onto the position at ctx+0x38:
 *   beyond 0xf000 -> push out by (range - 0x5000)
 *   inside 0x3800 -> pull in by -(range + 0x5000)
 * Either one hands off to Ov221_GuardedAimOrHandoff. In the band between, or with the flag set, it
 * falls through to the facing instead.
 *
 * The facing is `ctx[0x16] + 0x1922`, i.e. the stored angle plus a QUARTER TURN -- 0x1922 in Q12
 * radians is pi/2. It is then compared against the current heading (+0x50) by dotting the two
 * unit vectors out of data_0203d210: sinA*sinB + cosA*cosB is the cosine of the angle between
 * them, so a negative result means they point more than 90 degrees apart and the facing is
 * flipped by 0x3244 -- pi in Q12. (mwcc splits both constants; neither is an encodable
 * immediate.)
 *
 * See codegen-cracks.md for the Q12-radians -> sin/cos-table conversion, which runs twice here. */

typedef struct {
    int x;
    int y;
    int z;
} VecFx32;

typedef struct {
    unsigned char b0 : 1;
    unsigned char b1 : 1;
} Flags17a;

extern int Ov107_FindNearestObject(int owner, int a);
extern int Ov221_MeasureTargetGap(int self, VecFx32 *dir);
extern void SetIndexedSlot(int self, int action, void *cb);
extern int Ov221_ChooseMove(int self, int range);
extern void Ov221_GuardedAimOrHandoff(void);
extern void Ov221_Steer(int self, int angle);
extern short data_0203d210[];

static inline int FX_Mul(int a, int b) {
    return (int)(((long long)a * b + 0x800) >> 12);
}

void Ov221_AiChaseTick(int self) {
    int *ctx;
    VecFx32 dir;
    int range;
    int facing;
    int idxA;
    int idxB;

    ctx = *(int **)(self + 4);
    *(int *)(ctx[0] + 0x3e8) = Ov107_FindNearestObject(ctx[0], 0);

    range = Ov221_MeasureTargetGap(self, &dir);
    if (range < 0) {
        SetIndexedSlot(self, *(signed char *)(self + 0x20), 0);
        return;
    }
    if (Ov221_ChooseMove(self, range) != 0) {
        SetIndexedSlot(self, *(signed char *)(self + 0x20), 0);
        return;
    }

    *(VecFx32 *)((char *)ctx + 0x38) = *(VecFx32 *)ctx[2];

    if (((Flags17a *)(ctx[0] + 0x17a))->b1 == 0) {
        if (range > 0xf000) {
            *(int *)((char *)ctx + 0x38) += dir.x * (range - 0x5000) / 0x1000;
            ctx[0x10] += dir.z * (range - 0x5000) / 0x1000;
            SetIndexedSlot(self, *(signed char *)(self + 0x20), Ov221_GuardedAimOrHandoff);
            return;
        }
        if (range < 0x3800) {
            *(int *)((char *)ctx + 0x38) += -dir.x * (range + 0x5000) / 0x1000;
            ctx[0x10] += -dir.z * (range + 0x5000) / 0x1000;
            SetIndexedSlot(self, *(signed char *)(self + 0x20), Ov221_GuardedAimOrHandoff);
            return;
        }
    }

    facing = ctx[0x16] + 0x1922;
    idxA = (unsigned short)(((long long)ctx[0x14] * 0x28be60db9391LL + 0x80000000000LL) >> 44)
           >> 4;
    idxB = (unsigned short)(((long long)facing * 0x28be60db9391LL + 0x80000000000LL) >> 44) >> 4;

    if (FX_Mul(data_0203d210[idxB * 2], data_0203d210[idxA * 2])
            + FX_Mul(data_0203d210[idxB * 2 + 1], data_0203d210[idxA * 2 + 1])
        < 0) {
        facing -= 0x3244;
    }
    Ov221_Steer(self, facing);
}
