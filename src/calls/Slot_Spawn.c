/*
 * Slot_Spawn - allocate, populate and activate an object slot, returning its handle.
 *
 * Bails out (0) when the subsystem's enable byte at base+0xb47b5 is clear (base =
 * *data_0204c234). A zero `src` defaults to the current owner at base+0x9c. Unless
 * flags bit 1 forces it, the spawn is skipped when RecentRing_Record(src, arg2) fails.
 * On a successful slot allocation (ScriptPool_AllocSlot) it copies the 3-word posBlock to
 * slot+8, sets/clears status bit 2 by flags bit 0, initialises the slot's node at
 * +0x1c (NNS_SndArcPlayerStartSeqArcEx with the s16 at +0x16 and src/arg2), links it in
 * (Sound_UpdateSpatial), and returns slot->field_18 OR'd with the slot index (slot minus
 * the pool base at base+0xb44e4, /32) in the top byte.
 *
 * The `|` operands are ordered (index<<24) | field so mwcc keeps the reloaded base
 * in the same register the index chain uses; the base is read fresh for the handle
 * (its early register is reused for the slot pointer after the allocation).
 */

extern unsigned char *data_0204c234;
extern int RecentRing_Record(unsigned int a, unsigned int b);
extern int ScriptPool_AllocSlot(void);
extern void NNS_SndArcPlayerStartSeqArcEx(int *dst, int a, int b, int c, unsigned int p1, unsigned int p2);
extern void Sound_UpdateSpatial(int slot);

typedef struct { unsigned int w[3]; } Blk3;

unsigned int Slot_Spawn(unsigned int param_1, unsigned int param_2, unsigned int *param_3, unsigned int param_4)
{
    unsigned char *base = data_0204c234;
    int slot;
    int idx;

    if (base[0xb47b5] == 0)
        return 0;
    if (param_1 == 0)
        param_1 = *(unsigned int *)(base + 0x9c);
    if ((param_4 & 2) == 0 && RecentRing_Record(param_1, param_2) == 0)
        return 0;
    slot = ScriptPool_AllocSlot();
    if (slot == 0)
        return 0;
    *(Blk3 *)(slot + 8) = *(Blk3 *)param_3;
    if (param_4 & 1)
        *(unsigned short *)(slot + 0x14) |= 2;
    else
        *(unsigned short *)(slot + 0x14) &= ~2;
    NNS_SndArcPlayerStartSeqArcEx((int *)(slot + 0x1c), *(short *)(slot + 0x16), -1, -1, param_1, param_2);
    Sound_UpdateSpatial(slot);
    idx = slot - (int)(data_0204c234 + 0xb44e4);
    return ((idx / 32) << 24) | *(unsigned int *)(slot + 0x18);
}
