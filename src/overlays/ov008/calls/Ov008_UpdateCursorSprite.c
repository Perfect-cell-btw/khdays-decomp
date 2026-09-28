/* Ov008_UpdateCursorSprite -- update the menu cursor sprite, ov008. Reads the cursor's target
 * cell (Ov008_GetMissionMenuSelection; <0 = hidden, skip), then drives the cursor object
 * (*(heap+0x5044)) in the scene object manager (heap+0x60c): set frame to the cell
 * (Slot_ForwardToEntry), refresh (Slot_ClearFlagBit1), reset scale to 1.0 (Slot_SetPosition), re-add
 * (Obj_CommitAlphaBlend) and commit (Obj_CommitAllSlots). */
extern char *data_ov008_02090f00;
extern int  Ov008_GetMissionMenuSelection(void);
extern void Slot_ForwardToEntry(void *mgr, void *obj, int frame);
extern void Slot_ClearFlagBit1(void *mgr, void *obj);
extern void Slot_SetPosition(void *mgr, void *obj, int *scale);
extern void Obj_CommitAlphaBlend(void *mgr, void *obj);
extern void Obj_CommitAllSlots(void *mgr);
void Ov008_UpdateCursorSprite(void) {
    int cell = Ov008_GetMissionMenuSelection();
    if (cell < 0) {
        return;
    }
    Slot_ForwardToEntry(data_ov008_02090f00 + 0x60c, *(void **)(data_ov008_02090f00 + 0x5044),
                  (unsigned short)cell);
    Slot_ClearFlagBit1(data_ov008_02090f00 + 0x60c, *(void **)(data_ov008_02090f00 + 0x5044));
    {
        int scale[2];
        scale[0] = 0x8000;
        scale[1] = 0x8000;
        Slot_SetPosition(data_ov008_02090f00 + 0x60c, *(void **)(data_ov008_02090f00 + 0x5044), scale);
    }
    Obj_CommitAlphaBlend(data_ov008_02090f00 + 0x60c, *(void **)(data_ov008_02090f00 + 0x5044));
    Obj_CommitAllSlots(data_ov008_02090f00 + 0x60c);
}
