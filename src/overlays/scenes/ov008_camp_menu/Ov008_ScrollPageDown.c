/* Ov008_ScrollPageDown -- Ov008_ScrollPageDown (388 B, 19 relocs).
 * Menu scroll-down input step. Bails early unless the input global is set, the mode getter returns
 * 2 (or ctx+0x44 != 1), and ctx+8 (a busy flag) is clear. It samples a viewport metric via
 * Ov008_GetPoint1C (an 8-byte out struct; the second halfword feeds the bound), then combines
 * the field-0x3c offset (minus 8) with that metric through the signed div/mod-16 idioms to get the
 * scroll bound. It counts the visible list objects and, if the list already fits (count <= 8 and
 * bound+row >= count), does nothing. Otherwise it shows entries 0x29/0x51, hides 0x80, applies the
 * control value, drives the scroll (Ov008_ScrollMenuMoveTo), plays a click, hides entry 5, and marks
 * ctx+0x14 dirty. */

#include "nitro/types.h"
#include "game/engine.h"

extern int  data_ov008_02090f20;

extern int  Ov008_GetPageB(void);
extern int  func_ov008_02051aa0(void);
extern int  Ov008_GetCtxBlock4a80(void);
extern int  Ov008_GetCtxBlock954c(void);
extern void Ov008_GetPoint1C(int block, void *out);
extern int  NNS_FndGetNextListObject(void *list, int obj);
extern int  Ov008_FindEntryById(int root, int id);
extern void Ov008_SetEntrySlotsVisible(int root, int entry, int vis);
extern void Ov008_ApplyControlValue(int a);
extern void Ov008_ScrollMenuMoveTo(int ctx, int bound, int b, int c);

void Ov008_ScrollPageDown(void)
{
    u16 pt[4];
    int ctx = Ov008_GetPageB();
    int block1, block2, getter, base, bound, total, entry;
    int count = 0;

    if (data_ov008_02090f20 == 0)
        return;
    getter = func_ov008_02051aa0();
    if (getter == 2 || *(int *)(ctx + 0x44) == 1)
        return;
    if (*(int *)(ctx + 8) != 0)
        return;

    block1 = Ov008_GetCtxBlock4a80();
    block2 = Ov008_GetCtxBlock954c();
    Ov008_GetPoint1C(block2, pt);
    base = *(int *)(ctx + 0x3c) - 8;
    bound = pt[1] + base % 16;
    total = bound / 16 + base / 16;
    for (entry = NNS_FndGetNextListObject((void *)(ctx + 0x1cc), 0); entry != 0;
         entry = NNS_FndGetNextListObject((void *)(ctx + 0x1cc), entry))
        count++;
    if (count <= 8 && total + base / 16 >= count)
        return;

    entry = Ov008_FindEntryById(block1, 0x29);
    Ov008_SetEntrySlotsVisible(block1, entry, 1);
    entry = Ov008_FindEntryById(block1, 0x51);
    Ov008_SetEntrySlotsVisible(block1, entry, 1);
    entry = Ov008_FindEntryById(block1, 0x80);
    Ov008_SetEntrySlotsVisible(block1, entry, 0);
    Ov008_ApplyControlValue(0);
    Ov008_ScrollMenuMoveTo(ctx, total, 1, 0);
    PlaySound(0, 0);
    entry = Ov008_FindEntryById(block1, 5);
    Ov008_SetEntrySlotsVisible(block1, entry, 0);
    *(int *)(ctx + 0x14) = 1;
}
