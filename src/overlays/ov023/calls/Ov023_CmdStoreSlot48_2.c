/* Script command: stores the operand at the current slot-48 index; returns 0. */

/* Forward to Slot48_StoreAtCurrentIndex and return 0. */
extern void Slot48_StoreAtCurrentIndex(int arg);
int Ov023_CmdStoreSlot48_2(int param_1) {
    Slot48_StoreAtCurrentIndex(param_1);
    return 0;
}
