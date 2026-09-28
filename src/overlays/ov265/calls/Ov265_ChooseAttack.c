/* Attack choice of the ov265 enemy (variant of ov231/ov232's): a d100 is drawn and the target
 * re-acquired (Ov265_AcquireTarget); by the +0x20 distance the owner requests sub-state 5/6/8 with
 * thresholds 35/85 (closer than 3.0), 50/85 (closer than 5.0) or 35/50 (farther). When a
 * sub-state was requested the +0x24 delay is re-rolled in [+0x224, +0x228] and 1 is returned. */
extern int RandNextScaled(int n);
extern void Ov265_AcquireTarget(int *node);

static inline int RandRange(int low, int high)
{
    int span = high - low;
    if (span < 0) span = -span;
    return low + RandNextScaled(span + 1);
}

int Ov265_ChooseAttack(int *node)
{
    int *state = (int *)node[1];
    unsigned short roll = RandNextScaled(100);

    Ov265_AcquireTarget(node);
    if (state[8] < 0x3000) {
        *(unsigned char *)(*state + 0x1c7) = roll < 0x23 ? 5 : (roll < 0x55 ? 6 : 8);
    } else if (state[8] < 0x5000) {
        *(unsigned char *)(*state + 0x1c7) = roll < 0x32 ? 5 : (roll < 0x55 ? 6 : 8);
    } else {
        *(unsigned char *)(*state + 0x1c7) = roll < 0x23 ? 5 : (roll < 0x32 ? 6 : 8);
    }
    if (*(signed char *)(*state + 0x100 + 0xc7) != -1) {
        state[9] = RandRange(*(int *)(*state + 0x224), *(int *)(*state + 0x228));
        return 1;
    }
    return 0;
}
