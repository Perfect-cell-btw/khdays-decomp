/* Rebind the two collision items (+0x384 / +0x388) to the resources of this slot: the kinds
 * come from the data_ov273_020d69d4 / data_ov273_020d6a40 tables (27 entries each, copied to
 * the stack), the transform blocks are +0x38c / +0x3b0. Slots 0xb / 0xc / 0xd additionally
 * clear bit 1 on the +0x430 owner's +0x18 item and bind its four channels with (0,0) / (1,1) /
 * (2,0); any other slot raises that bit instead. */
struct Tbl27 { int w[27]; };
extern void *Ov107_PackTextureHandle(int obj, int kind);
extern void Ov273_AppendWorkEntryFinalize(int item, void *res, int arg, int block);
extern void SetSubitemState(int item, int channel, int a, int b);
extern const struct Tbl27 data_ov273_020d69d4;
extern const struct Tbl27 data_ov273_020d6a40;

void Ov273_RebindCollisionSlot(int obj, int slot, int arg) {
    struct Tbl27 kindsA = data_ov273_020d69d4;
    struct Tbl27 kindsB = data_ov273_020d6a40;

    Ov273_AppendWorkEntryFinalize(*(int *)(obj + 0x384), Ov107_PackTextureHandle(obj, kindsA.w[slot]), arg, obj + 0x38c);
    Ov273_AppendWorkEntryFinalize(*(int *)(obj + 0x388), Ov107_PackTextureHandle(obj, kindsB.w[slot]), arg, obj + 0x3b0);
    if (slot == 0xb) {
        int item = *(int *)(*(int *)(obj + 0x430) + 0x18);
        *(int *)(item + 0x5c) &= ~2;
        SetSubitemState(item, 0, 0, 0);
        SetSubitemState(item, 2, 0, 0);
        SetSubitemState(item, 4, 0, 0);
        SetSubitemState(item, 1, 0, 0);
    } else if (slot == 0xc) {
        int item = *(int *)(*(int *)(obj + 0x430) + 0x18);
        *(int *)(item + 0x5c) &= ~2;
        SetSubitemState(item, 0, 1, 1);
        SetSubitemState(item, 2, 1, 1);
        SetSubitemState(item, 4, 1, 1);
        SetSubitemState(item, 1, 1, 1);
    } else if (slot == 0xd) {
        int item = *(int *)(*(int *)(obj + 0x430) + 0x18);
        *(int *)(item + 0x5c) &= ~2;
        SetSubitemState(item, 0, 2, 0);
        SetSubitemState(item, 2, 2, 0);
        SetSubitemState(item, 4, 2, 0);
        SetSubitemState(item, 1, 2, 0);
    } else {
        *(int *)(*(int *)(*(int *)(obj + 0x430) + 0x18) + 0x5c) |= 2;
    }
}
