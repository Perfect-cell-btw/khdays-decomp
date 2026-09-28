/* Shows each summary row's frame for its state and its cells (details only for used slots). */

#include "nitro/types.h"

typedef struct Ov009SummaryRow {
    u8 pad000[0x10];
    int state;
    u8 pad014[4];
    int selectedValue;
} Ov009SummaryRow;

typedef struct Ov009SaveContext {
    u8 pad000[0x10];
    Ov009SummaryRow rows[3];
} Ov009SaveContext;

extern int Ov025_GetContext(void);
extern int Ov025_FindEntryById(int manager, int id);
extern void Ov025_ReleaseTwoSlotsEx_3(int manager, int entry, int slot);
extern void Ov025_ReleaseTwoSlotsEx_2(int manager, int entry, u16 value);
extern void Ov025_SetEntrySlotsVisible(int manager, int entry, int visible);
extern const int data_ov025_020b40e8[3][8];

void Ov025_SaveMenu_RefreshRows(Ov009SaveContext *ctx)
{
    int rowIndex;
    u32 itemIndex;
    int manager;
    int entry;
    int itemEntry;
    Ov009SummaryRow *row;

    manager = Ov025_GetContext();
    rowIndex = 0;
    row = ctx->rows;
    do {
        entry = Ov025_FindEntryById(manager, rowIndex + 1);
        Ov025_ReleaseTwoSlotsEx_3(manager, entry, 3);
        if (row->state == 1) {
            Ov025_ReleaseTwoSlotsEx_2(
                manager,
                entry,
                (u16)(*(int *)((u8 *)ctx + 0x28) + 2)
            );
        } else if (row->state == 2) {
            Ov025_ReleaseTwoSlotsEx_2(manager, entry, 0);
        } else {
            Ov025_ReleaseTwoSlotsEx_2(manager, entry, 1);
        }

        itemIndex = 0;
        do {
            itemEntry = Ov025_FindEntryById(
                manager,
                data_ov025_020b40e8[rowIndex][itemIndex]
            );

            switch (itemIndex) {
            case 2:
            case 3:
            case 4:
            case 5:
            case 6:
            case 7:
                if (row->state == 1) {
                    Ov025_SetEntrySlotsVisible(manager, itemEntry, 1);
                } else {
                    Ov025_SetEntrySlotsVisible(manager, itemEntry, 0);
                }
                break;
            default:
                Ov025_SetEntrySlotsVisible(manager, itemEntry, 1);
                break;
            }
            itemIndex++;
        } while (itemIndex < 8);

        row++;
        ctx = (Ov009SaveContext *)((u8 *)ctx + 0x1c);
        rowIndex++;
    } while (rowIndex < 3);
}
