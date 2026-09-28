/* Ov025_ScrollPageDown -- Ov008_ScrollPageDown (388 B, 19 relocs).
 * Menu scroll-down input step. Bails early unless the input global is set, the mode getter returns
 * 2 (or ctx+0x44 != 1), and ctx+8 (a busy flag) is clear. It samples a viewport metric via
 * Ov025_GetPoint1C (an 8-byte out struct; the second halfword feeds the bound), then combines
 * the field-0x3c offset (minus 8) with that metric through the signed div/mod-16 idioms to get the
 * scroll bound. It counts the visible list objects and, if the list already fits (count <= 8 and
 * bound+row >= count), does nothing. Otherwise it shows entries 0x29/0x51, hides 0x80, applies the
 * control value, drives the scroll (Ov025_ScrollMenuMoveTo), plays a click, hides entry 5, and marks
 * ctx+0x14 dirty. */

#include "nitro/types.h"

extern int  data_ov025_020b575c;

extern int  Ov025_GetPageB(void);
extern int  func_ov025_02085850(void);
extern int  Ov025_GetBlock4a80(void);
extern int  Ov025_GetCtxBlock954c(void);
extern void Ov025_GetPoint1C(int block, void *out);
extern int  NNS_FndGetNextListObject(void *list, int obj);
extern int  Ov025_FindEntryById(int root, int id);
extern void Ov025_SetEntrySlotsVisible(int root, int entry, int vis);
extern void Ov025_ApplyControlValue(int a);
extern void Ov025_ScrollMenuMoveTo(int ctx, int bound, int b, int c);
extern void PlaySound(int a, int b);

void Ov025_ScrollPageDown(void)
{
    u16 pt[4];
    int ctx = Ov025_GetPageB();
    int block1, block2, getter, base, bound, total, entry;
    int count = 0;

    if (data_ov025_020b575c == 0)
        return;
    getter = func_ov025_02085850();
    if (getter == 2 || *(int *)(ctx + 0x44) == 1)
        return;
    if (*(int *)(ctx + 8) != 0)
        return;

    block1 = Ov025_GetBlock4a80();
    block2 = Ov025_GetCtxBlock954c();
    Ov025_GetPoint1C(block2, pt);
    base = *(int *)(ctx + 0x3c) - 8;
    bound = pt[1] + base % 16;
    total = bound / 16 + base / 16;
    for (entry = NNS_FndGetNextListObject((void *)(ctx + 0x1cc), 0); entry != 0;
         entry = NNS_FndGetNextListObject((void *)(ctx + 0x1cc), entry))
        count++;
    if (count <= 8 && total + base / 16 >= count)
        return;

    entry = Ov025_FindEntryById(block1, 0x29);
    Ov025_SetEntrySlotsVisible(block1, entry, 1);
    entry = Ov025_FindEntryById(block1, 0x51);
    Ov025_SetEntrySlotsVisible(block1, entry, 1);
    entry = Ov025_FindEntryById(block1, 0x80);
    Ov025_SetEntrySlotsVisible(block1, entry, 0);
    Ov025_ApplyControlValue(0);
    Ov025_ScrollMenuMoveTo(ctx, total, 1, 0);
    PlaySound(0, 0);
    entry = Ov025_FindEntryById(block1, 5);
    Ov025_SetEntrySlotsVisible(block1, entry, 0);
    *(int *)(ctx + 0x14) = 1;
}
