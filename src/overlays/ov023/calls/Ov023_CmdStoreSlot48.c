/* Forward to Slot48_StoreAtCurrentIndex and return 0. */
extern void Slot48_StoreAtCurrentIndex(int arg);
int Ov023_CmdStoreSlot48(int param_1) {
    Slot48_StoreAtCurrentIndex(param_1);
    return 0;
}
