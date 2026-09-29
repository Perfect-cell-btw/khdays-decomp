/* Ov008_BuildMenuListFrom -- Ov008_BuildMenuListFrom (136 B, 8 relocs).
 * Sibling of Ov008_BuildMenuList (Ov008_BuildMenuList): builds a display list on the stack
 * (NNS_FndInitList, link offset 0x28) and runs the begin/seed/collect/finalize walker over the
 * one-frame iterator (0x100 B), list (NNSFndList) and buffer (0x1e0 B). Here the seed source is
 * the caller's arg0 (Ov008_BuildMenuGrid's 4th argument) rather than the fixed id table. Between
 * collect passes it dispatches on the iterator's result at +0x2c: non-zero runs GameState_SetFlag,
 * zero runs func_020235bc, both with 0x2010. Ends by collecting (Ov008_ReleaseHandleGridAndList) and
 * finalizing (func_02053464). */

#include "nitro/types.h"
#include "game/engine.h"

typedef struct NNSFndList {
    u16   numObjects;
    u16   offset;
    void *head;
    void *tail;
} NNSFndList;

typedef struct Ov008IterFrame {
    NNSFndList list;   /* 0x000 */
    u8 iter[0x100];    /* 0x00c */
    u8 buffer[0x1e0];  /* 0x10c */
} Ov008IterFrame;

extern void NNS_FndInitList(NNSFndList *list, int offset);
extern void Ov008_InitRecordContext(void *self, int a);
extern void Ov008_BuildMenuGrid(void *self, void *entries, NNSFndList *list, void *arg);
extern void Ov008_RebuildViewAndCountCells(void *self, void *entries, NNSFndList *list);
extern void Ov008_ReleaseHandleGridAndList(void *self, void *entries, NNSFndList *list);
extern void func_ov008_02053464(void *self);

void Ov008_BuildMenuListFrom(void *arg0)
{
    Ov008IterFrame f;

    NNS_FndInitList(&f.list, 0x28);
    Ov008_InitRecordContext(f.iter, 0);
    Ov008_BuildMenuGrid(f.iter, f.buffer, &f.list, arg0);
    Ov008_RebuildViewAndCountCells(f.iter, f.buffer, &f.list);
    if (*(int *)(f.iter + 0x2c) != 0) {
        GameState_SetFlag(0x2010);
    } else {
        func_020235bc(0x2010);
    }
    Ov008_ReleaseHandleGridAndList(f.iter, f.buffer, &f.list);
    func_ov008_02053464(f.iter);
}
