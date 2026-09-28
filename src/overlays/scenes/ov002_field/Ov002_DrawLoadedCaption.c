/*
 * Ov002_DrawLoadedCaption - finish a caption load and draw the line.
 *
 * Without a live text context the load node is simply thrown away. Otherwise
 * the character block that was loaded is copied into the context's target and
 * the node is released.
 *
 * The caption text is then measured with the context's own font; anything wider
 * than 0x78 is drawn with the narrow font instead, which is bound just for the
 * one line and put back afterwards. The line is drawn with its shadow, and the
 * scene's pending queue is drained on the way out.
 *
 * THUMB.
 */

typedef struct {
    char pad000[0xc0];
    char textCtx[0xc];
    unsigned int nSize;
    char pad0d0[8];
    void *pTarget;
    char pad0dc[4];
    int nFont;
    int nFontAlt;
} Ov002TextScene;

extern int data_ov002_0207f62c;
extern const char data_ov002_0207ecb4[];

extern void GetResourceSubBlock_CHAR(int nId, void **ppOut);
extern void MI_CpuCopy8(const void *pSrc, void *pDst, unsigned int nSize);
extern void Resource_BindByName(void *pFont, const char *pName);
extern void FreeFieldAt8(void *pFont);
extern int NNSi_G2dFontGetStringWidth(int nFont, int nFontAlt, void *pText, int *pOut);
extern void Text_DrawWithShadow(void *pCtx, int a, int b, int c, void *pText, int d);

extern void Ov002_DestroyOwnedEntry(void *pNode, int nMode);
extern void *Ov002_Field_GetWordB4(void);
extern int Ov002_Hud_GetBlock30(void);
extern void Ov002_DrainSceneQueue(void);

void Ov002_DrawLoadedCaption(void *pNode)
{
    int bWide;
    void *pSub;
    char aFont[0xc];
    void *pText;
    int nFont;
    Ov002TextScene *s;

    s = *(Ov002TextScene **)((char *)&data_ov002_0207f62c + 4);
    if (s == 0) {
        Ov002_DestroyOwnedEntry(pNode, 1);
        return;
    }

    GetResourceSubBlock_CHAR(*(int *)((char *)pNode + 8), &pSub);
    MI_CpuCopy8(*(void **)((char *)pSub + 0x14),
                *(void **)((char *)s->pTarget + 0x20), s->nSize);
    Ov002_DestroyOwnedEntry(pNode, 1);

    pText = Ov002_Field_GetWordB4();
    if (pText != 0) {
        Resource_BindByName(aFont, data_ov002_0207ecb4);
        nFont = Ov002_Hud_GetBlock30();
        bWide = NNSi_G2dFontGetStringWidth(s->nFont, s->nFontAlt, pText, 0) > 0x78;
        if (bWide != 0) {
            s->nFont = (int)aFont;
        }
        Text_DrawWithShadow(s->textCtx, 0, 2, 2, pText, 1);
        if (bWide != 0) {
            s->nFont = nFont;
        }
        FreeFieldAt8(aFont);
    }
    Ov002_DrainSceneQueue();
}
