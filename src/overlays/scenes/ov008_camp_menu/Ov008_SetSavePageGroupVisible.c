/* Shows or hides the whole save-page object group: the ten ids in the table
 * plus the fixed id 7, either all visible (mode 1) or all hidden (mode 0).
 * Any other mode leaves the page alone. The first parameter is the caller's
 * own object and is dead here: the list comes from the shared context. */
typedef unsigned short u16;

typedef struct {
    int ids[10];
} EntryIdGroup10;

extern EntryIdGroup10 data_ov008_0208f2c0;
extern int Ov008_GetCtxBlock9500(void);
extern int Ov008_FindEntryByTag(int list, int id);
extern void Ov008_SetField20Bit0(int list, int entry, int visible);

void Ov008_SetSavePageGroupVisible(int self, int mode) {
    int list = Ov008_GetCtxBlock9500();
    EntryIdGroup10 group = data_ov008_0208f2c0;
    unsigned int i;
    int entry;

    switch (mode) {
    case 0:
        for (i = 0; i < 10; i++) {
            entry = Ov008_FindEntryByTag(list, (u16)group.ids[i]);
            Ov008_SetField20Bit0(list, entry, 0);
        }
        entry = Ov008_FindEntryByTag(list, 7);
        Ov008_SetField20Bit0(list, entry, 0);
        break;
    case 1:
        for (i = 0; i < 10; i++) {
            entry = Ov008_FindEntryByTag(list, (u16)group.ids[i]);
            Ov008_SetField20Bit0(list, entry, 1);
        }
        entry = Ov008_FindEntryByTag(list, 7);
        Ov008_SetField20Bit0(list, entry, 1);
        break;
    }
}
