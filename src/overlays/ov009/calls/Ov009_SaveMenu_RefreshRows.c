typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct Ov009SummaryRow {
    u8 pad000[0x10];
    int state;
    u8 pad014[4];
    int selectedValue;
} Ov009SummaryRow;

typedef struct Ov009SaveContext {
    u8 pad000[0x14];
    Ov009SummaryRow rows[3];
} Ov009SaveContext;

extern int Ov009_GetContext(void);
extern int Ov009_FindEntryById(int manager, int id);
extern void Ov009_ReleaseTwoSlotsEx_3(int manager, int entry, int slot);
extern void Ov009_ReleaseTwoSlotsEx_2(int manager, int entry, u16 value);
extern void Ov009_SetEntrySlotsVisible(int manager, int entry, int visible);
extern const int data_ov009_020560a8[3][8];

void Ov009_SaveMenu_RefreshRows(Ov009SaveContext *ctx)
{
    int rowIndex;
    u32 itemIndex;
    int manager;
    int entry;
    int itemEntry;
    Ov009SummaryRow *row;

    manager = Ov009_GetContext();
    rowIndex = 0;
    row = ctx->rows;
    do {
        entry = Ov009_FindEntryById(manager, rowIndex + 1);
        Ov009_ReleaseTwoSlotsEx_3(manager, entry, 3);
        if (row->state == 1) {
            Ov009_ReleaseTwoSlotsEx_2(
                manager,
                entry,
                (u16)(*(int *)((u8 *)ctx + 0x2c) + 2)
            );
        } else if (row->state == 2) {
            Ov009_ReleaseTwoSlotsEx_2(manager, entry, 0);
        } else {
            Ov009_ReleaseTwoSlotsEx_2(manager, entry, 1);
        }

        itemIndex = 0;
        do {
            itemEntry = Ov009_FindEntryById(
                manager,
                data_ov009_020560a8[rowIndex][itemIndex]
            );

            switch (itemIndex) {
            case 2:
            case 3:
            case 4:
            case 5:
            case 6:
            case 7:
                if (row->state == 1) {
                    Ov009_SetEntrySlotsVisible(manager, itemEntry, 1);
                } else {
                    Ov009_SetEntrySlotsVisible(manager, itemEntry, 0);
                }
                break;
            default:
                Ov009_SetEntrySlotsVisible(manager, itemEntry, 1);
                break;
            }
            itemIndex++;
        } while (itemIndex < 8);

        row++;
        ctx = (Ov009SaveContext *)((u8 *)ctx + 0x1c);
        rowIndex++;
    } while (rowIndex < 3);
}
