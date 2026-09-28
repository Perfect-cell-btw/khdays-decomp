/* Repaint one text row: blit the staged glyph buffer into the animator's own
 * surface, then draw the string at row `row` (14 pixels apart, offset by 4) in
 * palette 0xf1, and commit. A null string skips the draw but still commits. */
extern void *Obj_GetWord18(void *animator);
extern void MIi_CpuCopyFast(const void *src, void *dest, unsigned int size);
extern void TextCanvas_DrawShadowedAt(void *animator, int x, int y, int style,
                          int palette, const void *text);
extern void EnqueueObjGfxCommand(void *animator);

typedef struct {
    char pad0000[0x20];
    void *pSurface;         /* +0x20 */
} Ov008Animator;

typedef struct {
    char pad0000[0xe8];
    char animator[0x204];   /* +0xe8 */
    unsigned int nStageSize;/* +0x2ec */
    char pad02f0[4];
    void *pStage;           /* +0x2f4 */
} Ov008TextPanel;

void Ov025_RepaintTextRow(Ov008TextPanel *self, int row, const void *text,
                         int style) {
    void *surface;

    surface = ((Ov008Animator *)Obj_GetWord18(self->animator))->pSurface;

    MIi_CpuCopyFast(self->pStage, surface, self->nStageSize);

    if (text != 0) {
        TextCanvas_DrawShadowedAt(self->animator, 8, row * 0xe + 4, style, 0xf1, text);
    }

    EnqueueObjGfxCommand(self->animator);
}
