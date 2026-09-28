/* Ov008_BuildMenuList -- Ov008_BuildMenuList (144 B, 9 relocs).
 * Gated by data_ov008_02090f20: builds a display list on the stack (NNS_FndInitList, link offset
 * 0x28) and runs the begin/collect/finalize walker over it -- Ov008_BuildMenuGrid seeds it from
 * the game-state id table at data_0204be18+0xee0 into the work buffer, Ov008_RebuildViewAndCountCells and
 * Ov008_ReleaseHandleGridAndList collect, Ov008_RefreshEquipPanel applies the menu step, and
 * func_02053464 finalizes. The iterator (0x100 B), list (NNSFndList) and buffer (0x1e0 B) live in
 * one stack frame so their offsets (0x0/0xc/0x10c) match the original layout. */
typedef unsigned char u8;
typedef unsigned short u16;

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

extern int   data_ov008_02090f20;
extern char *data_0204be18;
extern void  NNS_FndInitList(NNSFndList *list, int offset);
extern void  Ov008_InitRecordContext(void *self, int a);
extern void  Ov008_BuildMenuGrid(void *self, void *entries, NNSFndList *list, u16 *ids);
extern void  Ov008_RebuildViewAndCountCells(void *self, void *entries, NNSFndList *list);
extern void  Ov008_RefreshEquipPanel(void *self);
extern void  Ov008_ReleaseHandleGridAndList(void *self, void *entries, NNSFndList *list);
extern void  func_ov008_02053464(void *self);

void Ov008_BuildMenuList(void)
{
    Ov008IterFrame f;

    if (data_ov008_02090f20 == 0) {
        return;
    }
    NNS_FndInitList(&f.list, 0x28);
    Ov008_InitRecordContext(f.iter, 0);
    Ov008_BuildMenuGrid(f.iter, f.buffer, &f.list, (u16 *)(data_0204be18 + 0xee0));
    Ov008_RebuildViewAndCountCells(f.iter, f.buffer, &f.list);
    Ov008_RefreshEquipPanel(f.iter);
    Ov008_ReleaseHandleGridAndList(f.iter, f.buffer, &f.list);
    func_ov008_02053464(f.iter);
}
