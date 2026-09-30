/* On a DOWN (0x80) or UP (0x40) press, move the tab/panel cursor *pIndex by
 * +1/-1, clamp it (with wraparound) against the panel count, mark the new slot
 * selected and clear its debounce counter, then refresh every panel via
 * SubObject_NudgeAndRedraw. Bails out immediately if neither key is held. */

typedef struct {
    int debounce;           /* +0x00 */
    int selected;           /* +0x04 */
} PanelSlot;

typedef struct {
    char      pad0000[0xc];
    char      panel[0xa0];  /* +0x0c -- opaque, passed to SubObject_NudgeAndRedraw */
    PanelSlot slots[4];     /* +0xac */
    int       field_cc;
    int       count;        /* +0xd0 */
} TabContext;

typedef struct {
    char        pad0000[4];
    TabContext *pCtx;       /* +0x04 */
} Root0204be08;

extern Root0204be08 data_0204be08;
extern unsigned short gPadPressed;
extern void PlaySound(int a, int b);
extern int LoadGlobalU16At0(void);
extern void SubObject_NudgeAndRedraw(void *panel, int index, int state);

void TabPanel_HandleUpDown(int *pIndex) {
    TabContext *ctx = data_0204be08.pCtx;
    int delta;
    int count;
    int i;

    if ((gPadPressed & 0x80) == 0 && (gPadPressed & 0x40) == 0) {
        return;
    }

    PlaySound(0, 0);

    ctx->slots[*pIndex].selected = 0;

    delta = (gPadPressed & 0x80) ? 1 : -1;
    *pIndex = *pIndex + delta;

    count = ctx->count;
    if (count == 3 && *pIndex == 1 && (LoadGlobalU16At0() & 2) != 0) {
        *pIndex = *pIndex + delta;
    } else {
        count = ctx->count;
        if (*pIndex >= count) {
            *pIndex = 0;
        } else if (*pIndex < 0) {
            *pIndex = count - 1;
        }
    }

    ctx->slots[*pIndex].selected = 1;
    ctx->slots[*pIndex].debounce = 0;

    for (i = 0; i < ctx->count; i++) {
        SubObject_NudgeAndRedraw(ctx->panel, i, ctx->slots[i].selected);
    }
}
