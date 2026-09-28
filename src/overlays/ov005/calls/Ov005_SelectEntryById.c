/* Ov005_SelectEntryById -- select the list entry whose id the caller names: resolve it with
 * Ov005_FindEntryByTag and hand the result to Ov005_TagTracker_InvokeCallback, both on the widget at +8 of the
 * ov005 context. The id is an `int` parameter narrowed with `(unsigned short)` at the call -- a
 * `unsigned short` PARAMETER would emit no extension at all (the ABI assumes the caller did it),
 * and the ROM's `lsl #0x10 ; lsr #0x10` says it does extend here. */
extern int Ov005_FindEntryByTag(int obj, int id);
extern void Ov005_TagTracker_InvokeCallback(int obj, int v);
extern int data_ov005_0205b810;

void Ov005_SelectEntryById(int id) {
    int ctx = *(int *)&data_ov005_0205b810;
    Ov005_TagTracker_InvokeCallback(ctx + 8, Ov005_FindEntryByTag(ctx + 8, (unsigned short)id));
}
