/* Ov008_DisableRowBlock -- disable the whole tag-0xc9..0xdc row block of the mission list
 * (when the global gate data_02090f20 is set). */
extern int  Ov008_GetCtxBlock4a80(void);
extern int  Ov008_FindEntryById(int list, int tag);
extern void Ov008_SetEntrySlotsVisible(int list, int row, int enabled);
extern int  data_ov008_02090f20;

void Ov008_DisableRowBlock(void) {
    if (data_ov008_02090f20 == 0) {
        return;
    }
    {
        int list = Ov008_GetCtxBlock4a80();
        int tag = 0xc9;
        do {
            int row = Ov008_FindEntryById(list, tag);
            Ov008_SetEntrySlotsVisible(list, row, 0);
            tag = tag + 1;
        } while (tag <= 0xdc);
    }
}
