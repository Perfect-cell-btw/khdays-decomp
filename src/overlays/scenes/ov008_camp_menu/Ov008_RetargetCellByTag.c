/* Retarget then re-anchor a mission cell by tag: look the cell up in the active record's list,
 * move it to (x, y), then look it up again and re-anchor it.
 *
 * Parked as a CSE tie -- the original recomputes `(tag << 16) >> 16` before each lookup while
 * mwcc caches it. Nothing is being cached: the truncation belongs to the CALL, not to the
 * source expression. Ov008_FindEntryByTag's tag parameter is an `unsigned short`, so the caller
 * has to narrow at every call site, and writing `tag & 0xffff` in C instead puts one value in
 * the caller's own dataflow where mwcc is free to reuse it.
 *
 * Same for x and y: the mover takes `short`, which is where the pair of lsl/asr comes from. */
extern int  Ov008_GetCtxBlock9500(void);
extern int  Ov008_FindEntryByTag(int list, unsigned short tag);
extern void Ov008_Elem_SetPos(int list, int cell, short x, short y);
extern void Ov008_TagTracker_InvokeCallback(int list, int cell);

void Ov008_RetargetCellByTag(unsigned int tag, int x, int y) {
    int list = Ov008_GetCtxBlock9500();
    Ov008_Elem_SetPos(list, Ov008_FindEntryByTag(list, tag), x, y);
    Ov008_TagTracker_InvokeCallback(list, Ov008_FindEntryByTag(list, tag));
}
