/* Obj_SetTransition -- start or stop an object's interpolated transition.
 *
 * Enabling starts the transition from pObj+0xb4 into pObj+0x168 via EventRecord_Init and sets
 * bit4 of the object's flag byte at pObj+8; disabling just clears that bit and does nothing
 * else. A caller passing a duration of 0 means "use the default": the object's own base
 * duration at pObj+0x154 scaled by 1.5 in 20.12 fixed point. That scale is written as the
 * project's usual widened form, `(s64)v * 0x1800 + 0x800 >> 12`, which is what produces the
 * umull/asr/mla/adc sequence -- the same idiom already matched in
 * src/overlays/ov022/calls/Ov022_BuildSlotSelection.c. */
typedef unsigned char u8;
typedef signed int s32;
typedef signed long long s64;
typedef unsigned int u32;

extern int EventRecord_Init(u32 *pDst, u32 *pSrc, u32 nDuration, int nMode);

void Obj_SetTransition(u8 *pObj, int bEnable, int nDuration)
{
    if (bEnable != 0) {
        if (nDuration == 0) {
            nDuration = (s32)(((s64)*(s32 *)(pObj + 0x154) * 0x1800 + 0x800) >> 12);
        }
        EventRecord_Init((u32 *)(pObj + 0x168), (u32 *)(pObj + 0xb4), nDuration, 0);
        pObj[8] |= 0x10;
        return;
    }
    pObj[8] &= ~0x10;
}
