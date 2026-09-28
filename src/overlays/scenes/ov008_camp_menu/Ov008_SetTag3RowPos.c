/* Ov008_SetTag3RowPos -- push the tag-3 row's position: x = 0x78000 (Q12), y = the entry's own
 * y (Ov008_GetEntryPos(list, param_1) +4) biased by 0x8000. */
extern int  Ov008_GetContext(void);
extern int  Ov008_GetEntryPos(int list, int key);
extern int  Ov008_FindEntryById(int list, int tag);
extern void Ov008_SetEntryPos(int list, int row, int *pos);

void Ov008_SetTag3RowPos(int param_1) {
    int pos[2];
    int list = Ov008_GetContext();
    int entry = Ov008_GetEntryPos(list, param_1);
    pos[0] = 0x78000;
    pos[1] = *(int *)(entry + 4) + 0x8000;
    {
        int row = Ov008_FindEntryById(list, 3);
        Ov008_SetEntryPos(list, row, pos);
    }
}
