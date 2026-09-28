/* Ov008_ProcessAndCleanup -- per-frame update of an ov008 grid cell: runs the base tick
 * (Ov008_ClearGridSlot), then if a hit entry is resolved (Ov008_FindGridHit) applies its two
 * effects (Ov008_ClearNodeCells/020609e4); finally advances the cell's animator (obj+0xac). */
extern void Ov008_ClearGridSlot(int obj, unsigned int a, unsigned int b, unsigned int c);
extern int  Ov008_FindGridHit(int obj, unsigned int a, unsigned int b, unsigned int c);
extern void Ov008_ClearNodeCells(int obj, int entry);
extern void Ov008_RemoveAndFreeBlock(int obj, int entry);
extern void EnqueueObjGfxCommand(int animator);

void Ov008_ProcessAndCleanup(int param_1, unsigned int param_2, unsigned int param_3, unsigned int param_4) {
    int entry;
    Ov008_ClearGridSlot(param_1, param_2, param_3, param_4);
    entry = Ov008_FindGridHit(param_1, param_2, param_3, param_4);
    if (entry != 0) {
        Ov008_ClearNodeCells(param_1, entry);
        Ov008_RemoveAndFreeBlock(param_1, entry);
    }
    EnqueueObjGfxCommand(param_1 + 0xac);
}
