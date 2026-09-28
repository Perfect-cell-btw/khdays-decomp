extern int RandNextScaled(int);
extern void SetIndexedSlot(int, int, void *);
extern void Ov164_stateSetFlagsClearBit(void);
extern void Ov164_stDispatchByStateByte(void);
extern void Ov164_UpdateHeadingAndVelocity(void);

struct flagword { unsigned f8 : 8; };

void Ov164_EnterRandomDwellState(int param_1) {
    int *obj = *(int **)(param_1 + 4);
    unsigned short h;
    int lo, range;

    *(char *)(*obj + 0x1c6) = 0;
    *(char *)(*obj + 0x1c7) = -1;
    ((struct flagword *)(*(int *)(*obj + 0x388) + 8))->f8 &= ~1;
    obj[0x14] = *obj + 0xb0;
    obj[0x15] = *obj + 0x74;
    obj[0x16] = *(int *)(*obj + 900) + 0xad;
    h = *(unsigned short *)(*obj + 0x60);
    *(unsigned short *)(*obj + 0x60) =
        h & ~0xff00 | (((((unsigned int)h << 0x10) >> 0x18 | 6) << 0x18) >> 0x10);
    lo = *(int *)(*obj + 0x224);
    range = *(int *)(*obj + 0x228) - lo;
    if (range < 0) {
        range = -range;
    }
    obj[0xd] = lo + RandNextScaled(range + 1);
    SetIndexedSlot(param_1, 1, Ov164_stateSetFlagsClearBit);
    SetIndexedSlot(param_1, 0, Ov164_stDispatchByStateByte);
    SetIndexedSlot(param_1, 2, Ov164_UpdateHeadingAndVelocity);
}
