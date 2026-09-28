/* Ov025_UpdateScrollArrows -- Ov008_UpdateScrollArrows (128 B, 6 relocs).
 * Enables/disables the menu's prev/next scroll arrows from the current index vs item count.
 * The prev-arrow widget id is chosen by Ov025_GetCtxObject9634() (0x3f when non-zero, else 0x3d);
 * the next-arrow widget is id 0x3e. Both are disabled by default and only enabled when there is
 * something to scroll: with count = state->count > 0, the prev arrow is enabled if
 * state->index > 0 and the next arrow if state->index < count. Widget states are pushed via
 * Ov025_SetEntrySlotsVisible(ctx, Ov025_FindEntryById(ctx, id), enabled). */
typedef unsigned char u8;

typedef struct Ov008ScrollState {
    u8  pad_0000[0x20];
    int index;              /* 0x20 */
    u8  pad_0024[4];
    int count;              /* 0x28 */
} Ov008ScrollState;

extern int   Ov025_GetCtxObject9634(void);
extern void *Ov025_GetBlock4a80(void);
extern void *Ov025_FindEntryById(void *ctx, int id);
extern void  Ov025_SetEntrySlotsVisible(void *ctx, void *widget, int flag);

void Ov025_UpdateScrollArrows(Ov008ScrollState *param_1)
{
    void *ctx;
    int id = Ov025_GetCtxObject9634() != 0 ? 0x3f : 0x3d;
    int prevEnabled = 0;
    int nextEnabled = 0;
    int count = param_1->count;

    if (count > 0) {
        int idx = param_1->index;
        if (idx > 0) prevEnabled = 1;
        if (idx < count) nextEnabled = 1;
    }
    ctx = Ov025_GetBlock4a80();
    Ov025_SetEntrySlotsVisible(ctx, Ov025_FindEntryById(ctx, id), prevEnabled);
    Ov025_SetEntrySlotsVisible(ctx, Ov025_FindEntryById(ctx, 0x3e), nextEnabled);
}
