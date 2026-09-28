/* Clears a grid slot and the block under it, then uploads the grid. */

extern void Ov025_ClearGridSlot();
extern int Ov025_FindGridHit();
extern void Ov025_ClearNodeCells();
extern void Ov025_RemoveAndFreeBlock();
extern void EnqueueObjGfxCommand();

void Ov025_ProcessAndCleanup(int arg0, unsigned int arg1, unsigned int arg2, unsigned int arg3) {
    Ov025_ClearGridSlot(arg0, arg1, arg2, arg3);
    int r = Ov025_FindGridHit(arg0, arg1, arg2, arg3);
    if (r != 0) {
        Ov025_ClearNodeCells(arg0, r);
        Ov025_RemoveAndFreeBlock(arg0, r);
    }
    EnqueueObjGfxCommand(arg0 + 0xac);
}
