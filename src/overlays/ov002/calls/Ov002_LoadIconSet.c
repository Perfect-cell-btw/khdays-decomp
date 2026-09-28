typedef struct {
    char pad0000[0x5f4];
    int aPrimary[11];               /* +0x5f4 */
    int aSecondary[6];              /* +0x620 */
} Ov002IconSet;

extern Ov002IconSet *data_ov002_0207f620;
extern unsigned short data_ov002_0207de38[];    /* 11 primary ids */
extern unsigned short data_ov002_0207de2c[];    /* 6 secondary ids */

extern int Ov002_ForwardToSubDc(int nId);
extern void Ov002_Ctx_SetTagTrackerNodeArmed(int nFirst, int nSecond);

/* Resolve every icon the panel uses and install the pair the header shows. */
void Ov002_LoadIconSet(void)
{
    Ov002IconSet *pSet;
    int i;

    pSet = data_ov002_0207f620;

    for (i = 0; i < 11; i++) {
        pSet->aPrimary[i] = Ov002_ForwardToSubDc(data_ov002_0207de38[i]);
    }

    for (i = 0; i < 6; i++) {
        pSet->aSecondary[i] = Ov002_ForwardToSubDc(data_ov002_0207de2c[i]);
    }

    Ov002_Ctx_SetTagTrackerNodeArmed(pSet->aSecondary[2], pSet->aPrimary[0]);
}
