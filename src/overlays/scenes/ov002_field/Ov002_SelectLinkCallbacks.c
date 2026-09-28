/* Select the link callbacks stored for one roster entry. The switch form is
 * load-bearing because it reproduces the original THUMB branch tree. */
typedef void (*Ov002LinkCallback)(void);

typedef struct Ov002LinkCtx {
    char gap0000[0x0c];
    signed char nLinkMode;
} Ov002LinkCtx;

extern Ov002LinkCtx *data_ov002_0207fa10;

extern int Ov002_GetStateWord(void);
extern void func_ov002_02072ba4(void);
extern void Ov013_ClearActiveRecordFlag(void);
extern void Ov020_OpenWallView(void);
extern void Ov020_StepWallView(void);

void Ov002_SelectLinkCallbacks(int nIndex, Ov002LinkCallback *pPrimary,
                         Ov002LinkCallback *pSecondary)
{
    Ov002LinkCallback pFirst = func_ov002_02072ba4;
    Ov002LinkCallback pSecond = 0;
    int nMode = data_ov002_0207fa10->nLinkMode;

    switch (nMode) {
    case 1:
        if (nIndex == 1 && Ov002_GetStateWord() == 0x72) {
            pFirst = Ov013_ClearActiveRecordFlag;
        }
        break;
    case 4:
        if ((unsigned int)(nIndex - 9) <= 1) {
            pFirst = Ov020_OpenWallView;
            pSecond = Ov020_StepWallView;
        }
        break;
    }
    if (pPrimary != 0) {
        *pPrimary = pFirst;
    }
    if (pSecondary != 0) {
        *pSecondary = pSecond;
    }
}
