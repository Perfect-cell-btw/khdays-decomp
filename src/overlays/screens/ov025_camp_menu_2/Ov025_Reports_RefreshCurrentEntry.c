/* Refreshes the reports page: scrollbar, markers, row texts and entries, and selects the current
 * report (or its read version). */

#include "nitro/types.h"

typedef struct Entry {
    u16 id:9;
    u16 flag9:1;
    u16 pending:6;
    u8 pad_02[0xa];
    struct Entry *pRead;
    u8 pad_10[0x30];
} Entry;
typedef struct Page {
    s16 top;
    s16 cursor;
    u8 pad_004[0xbc];
    int gate;
    u8 pad_0c4[0x124];
    Entry *entries;
    Entry current;
    u8 pad_22c[0x30];
    void *held;
} Page;
extern Page *Ov025_GetPageA(void);
extern void Ov025_Reports_UpdateScrollBar(void);
extern void Ov025_Reports_PlaceMarkers(void);
extern void Ov025_Reports_DrawRowTexts(void);
extern void Ov025_Reports_RefreshRowEntries(void);
extern void Ov025_ScrollPanelToRow(int row);
void Ov025_Reports_RefreshCurrentEntry(void)
{
    Page *page = Ov025_GetPageA();
    Entry copy;
    Entry *read;
    int chosen;
    int canRead;
    Ov025_Reports_UpdateScrollBar();
    Ov025_Reports_PlaceMarkers();
    Ov025_Reports_DrawRowTexts();
    Ov025_Reports_RefreshRowEntries();
    Ov025_ScrollPanelToRow(page->top);
    read = page->entries[page->cursor].pRead;
    chosen = 0;
    canRead = 0;
    if (read != 0 && page->entries[page->cursor].pending == 0) {
        canRead = 1;
    }
    if (canRead) {
        if (page->gate != 0 || page->held != 0) chosen = 1;
    }
    if (chosen) copy = *page->entries[page->cursor].pRead;
    else copy = page->entries[page->cursor];
    page->current = copy;
}
