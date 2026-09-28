/* Suspend the panel or bring it back. Suspending saves the current mode, tears
 * the sub-panels down and marks the panel modeless; restoring just puts the
 * saved mode back. */
extern void Ov002_RefreshSettledPanels(void);

typedef struct {
    char pad0000[0xd58];
    int nMode;          /* +0xd58, -1 = suspended */
    int nSavedMode;     /* +0xd5c */
} Ov002PanelContext;

extern Ov002PanelContext *data_ov002_0207f628;

void Ov002_SuspendOrRestorePanel(int restore) {
    Ov002PanelContext *ctx = data_ov002_0207f628;

    if (ctx == 0) {
        return;
    }

    if (restore != 0) {
        ctx->nMode = ctx->nSavedMode;
        return;
    }

    ctx->nSavedMode = ctx->nMode;
    Ov002_RefreshSettledPanels();
    ctx->nMode = -1;
}
