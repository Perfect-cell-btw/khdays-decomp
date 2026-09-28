/* Play the panel's cancel feedback, but only once the transition has finished
 * AND the panel has a target at +0x1a8 -- the ROM folds both guards into one
 * predicated chain. Ov002_PanelStepCursor has the final say. Sibling of
 * Ov002_PlayPanelConfirm, which is the same shape against Ov002_PanelAdvanceCursor. */
typedef struct {
    char pad00[0x1a8];
    int pTarget;            /* +0x1a8 */
} Ov002PanelContext;

extern int Ov002_GetPanelField018c(void);
extern int Ov002_PanelStepCursor(void);
extern void PlaySound(int a, int b);

extern Ov002PanelContext *data_ov002_0207f614;

void Ov002_PlayPanelCancel(void) {
    Ov002PanelContext *ctx = data_ov002_0207f614;

    if (Ov002_GetPanelField018c() != 0 && ctx->pTarget != 0) {
        if (Ov002_PanelStepCursor() != 0) {
            PlaySound(0, 0);
        }
    }
}
