/* Clear bit 1 of the flag word at +0x7c of entry `index` of the stride-0x8c slot array; negative
 * indices are ignored. Same array as Slot_SetMode2Bit (+0x74) and Slot_ForwardToEntry. */

struct S { char pad[0x7c]; int flags; char pad2[0x8c - 0x80]; };

void Slot_ClearFlagBit1(struct S *base, int index)
{
    if (index < 0) return;
    base[index].flags &= ~2;
}
