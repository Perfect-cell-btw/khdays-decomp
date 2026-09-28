/* Ov025_BuildMenuList -- Ov008_BuildMenuList (144 B, 9 relocs).
 * Gated by data_ov025_020b575c: builds a display list on the stack (NNS_FndInitList, link offset
 * 0x28) and runs the begin/collect/finalize walker over it -- Ov025_BuildMenuGrid seeds it from
 * the game-state id table at data_0204be18+0xee0 into the work buffer, Ov025_RebuildViewAndCountCells and
 * Ov025_ReleaseHandleGridAndList collect, Ov025_RefreshStatusPage applies the menu step, and
 * func_02053464 finalizes. The iterator (0x100 B), list (NNSFndList) and buffer (0x1e0 B) live in
 * one stack frame so their offsets (0x0/0xc/0x10c) match the original layout. */
#include "nitro/types.h"

typedef struct NNSFndList {
    u16 numObjects;
    u16 offset;
    void *head;
    void *tail;
} NNSFndList;

typedef struct Ov008IterFrame {
    NNSFndList list;   /* 0x000 */
    u8 iter[0x100];    /* 0x00c */
    u8 buffer[0x1e0];  /* 0x10c */
} Ov008IterFrame;

extern int   data_ov025_020b575c;
extern char *data_0204be18;
extern void  NNS_FndInitList(NNSFndList *list, int offset);
extern void  Ov025_InitRecordContext(void *self, int a);
extern void  Ov025_BuildMenuGrid(void *self, void *entries, NNSFndList *list, u16 *ids);
extern void  Ov025_RebuildViewAndCountCells(void *self, void *entries, NNSFndList *list);
extern void  Ov025_RefreshStatusPage(void *self);
extern void  Ov025_ReleaseHandleGridAndList(void *self, void *entries, NNSFndList *list);
extern void  func_ov025_02087254(void *self);

void Ov025_BuildMenuList(void)
{
    Ov008IterFrame f;

    if (data_ov025_020b575c == 0) {
        return;
    }
    NNS_FndInitList(&f.list, 0x28);
    Ov025_InitRecordContext(f.iter, 0);
    Ov025_BuildMenuGrid(f.iter, f.buffer, &f.list, (u16 *)(data_0204be18 + 0xee0));
    Ov025_RebuildViewAndCountCells(f.iter, f.buffer, &f.list);
    Ov025_RefreshStatusPage(f.iter);
    Ov025_ReleaseHandleGridAndList(f.iter, f.buffer, &f.list);
    func_ov025_02087254(f.iter);
}
