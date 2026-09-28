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

extern int Ov008_GetContext(void);
extern int Ov008_FindEntryById(int manager, int id);
extern void Ov008_ReleaseTwoSlotsEx_2(int manager, int entry, int slot);
extern void Ov008_ReleaseTwoSlotsEx(int manager, int entry, int value);
extern void Ov008_SetEntrySlotsVisible(int manager, int entry, int visible);
extern const int data_ov008_0208f588[3][8];

void Ov008_SaveMenu_RefreshRows(Ov009SaveContext *ctx)
{
    int rowIndex;
    u32 itemIndex;
    int manager;
    int entry;
    int itemEntry;
    Ov009SummaryRow *row;

    manager = Ov008_GetContext();
    rowIndex = 0;
    row = ctx->rows;
    do {
        entry = Ov008_FindEntryById(manager, rowIndex + 1);
        Ov008_ReleaseTwoSlotsEx_2(manager, entry, 3);
        if (row->state == 1) {
            Ov008_ReleaseTwoSlotsEx(manager, entry, (u16)(*(int *)((u8 *)ctx + 0x28) + 2));
        } else if (row->state == 2) {
            Ov008_ReleaseTwoSlotsEx(manager, entry, 0);
        } else {
            Ov008_ReleaseTwoSlotsEx(manager, entry, 1);
        }

        itemIndex = 0;
        do {
            itemEntry = Ov008_FindEntryById(
                manager,
                data_ov008_0208f588[rowIndex][itemIndex]
            );

            switch (itemIndex) {
            case 2:
            case 3:
            case 4:
            case 5:
            case 6:
            case 7:
                if (row->state == 1) {
                    Ov008_SetEntrySlotsVisible(manager, itemEntry, 1);
                } else {
                    Ov008_SetEntrySlotsVisible(manager, itemEntry, 0);
                }
                break;
            default:
                Ov008_SetEntrySlotsVisible(manager, itemEntry, 1);
                break;
            }
            itemIndex++;
        } while (itemIndex < 8);

        row++;
        ctx = (Ov009SaveContext *)((u8 *)ctx + 0x1c);
        rowIndex++;
    } while (rowIndex < 3);
}
