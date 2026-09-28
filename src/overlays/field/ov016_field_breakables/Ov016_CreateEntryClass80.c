/* Construct an ov016 list-entry class: allocate its 0x80-byte table with room for
 * `nCount` 0x658-byte entries (Ov002_CreateEntryPool), copy the descriptor's name into
 * the 0x10-byte field at +0x58, carry its five parameters across, install thirteen
 * handlers and stamp kind 2.
 *
 * Sibling of Ov016_CreateEntry, which is the same shape with a 0x70-byte table:
 * 0x2f4-byte entries, nine handlers, kind 0x13. The two differ in table and entry
 * size, handler set and kind stamp, so they are distinct object kinds rather than
 * one routine called twice; the 80 in the name is the table size.
 *
 * This closes a pair: its parameter block is exactly the Ov016EmitParams that
 * the script-VM handler Ov016_VmCmdCreateEntryClass80 assembles, which is what confirms
 * that handler's stack block is an entry descriptor and not an ad-hoc argument
 * bundle.
 */
typedef struct {
    char *pszName;           /* +0x00 */
    int nParamA;             /* +0x04 */
    signed char cKind;       /* +0x08 */
    char pad09[3];
    int nParamB;             /* +0x0c */
    int nParamC;             /* +0x10 */
    int nParamD;             /* +0x14 */
    unsigned char bParamE;   /* +0x18 */
    char pad19[3];
} Ov016EmitParams;           /* 0x1c */

typedef struct {
    int nField00;            /* +0x00 */
    int nField04;            /* +0x04 */
    void *pfn08;             /* +0x08 */
    void *pfn0c;             /* +0x0c */
    void *pfn10;             /* +0x10 */
    void *pfn14;             /* +0x14 */
    void *pfn18;             /* +0x18 */
    void *pfn1c;             /* +0x1c */
    int nField20;            /* +0x20 */
    void *pfn24;             /* +0x24 */
    void *pfn28;             /* +0x28 */
    void *pfn2c;             /* +0x2c */
    char pad30[4];
    void *pfn34;             /* +0x34 */
    void *pfn38;             /* +0x38 */
    void *pfn3c;             /* +0x3c */
    char pad40[4];
    void *pfn44;             /* +0x44 */
    char pad48[4];
    unsigned short wKind;    /* +0x4c */
    char pad4e[0xa];
    char szName[0x10];       /* +0x58 */
    int nParamA;             /* +0x68 */
    signed char cKind;       /* +0x6c */
    char pad6d[3];
    int nParamB;             /* +0x70 */
    int nParamC;             /* +0x74 */
    int nParamD;             /* +0x78 */
    unsigned char bParamE;   /* +0x7c */
    char pad7d[3];
} Ov016Entry;

extern void *Ov002_CreateEntryPool(int headerSize, int entrySize, int count);
extern char *strncpy(char *dst, const char *src, unsigned int n);
extern void Ov016_KickableHandleMessage(void);
extern void Ov016_ReleaseNodeAndInvalidate(void);
extern void Ov016_RebindActorAndApplyStatePalette(void);
extern void Ov016_ReleaseNode(void);
extern void Ov016_KickableStart(void);
extern void Ov016_KickableHit(void);
extern void Ov016_KickableTargetPosition(void);
extern void Ov016_KickableQueryParamA(void);
extern void Ov016_GetField54cPtr(void);
extern void Ov016_KickableReturnHome(void);
extern void Ov016_KickableReceiveHit(void);
extern void Ov016_Entry80_SetNodeEnabled(void);
extern void Ov016_AddrOfField0x64c(void);

Ov016Entry *Ov016_CreateEntryClass80(int nCount, Ov016EmitParams *desc) {
    Ov016Entry *self = Ov002_CreateEntryPool(0x80, 0x658, nCount);

    strncpy(self->szName, desc->pszName, 0x10);
    self->nParamA = desc->nParamA;
    self->cKind = desc->cKind;
    self->nParamB = desc->nParamB;
    self->nParamC = desc->nParamC;
    self->nParamD = desc->nParamD;
    self->bParamE = desc->bParamE;
    self->nField00 = 0;
    self->nField04 = 0;
    self->pfn08 = (void *)&Ov016_KickableHandleMessage;
    self->pfn0c = (void *)&Ov016_ReleaseNodeAndInvalidate;
    self->pfn10 = (void *)&Ov016_RebindActorAndApplyStatePalette;
    self->pfn14 = (void *)&Ov016_ReleaseNode;
    self->pfn18 = (void *)&Ov016_KickableStart;
    self->pfn1c = (void *)&Ov016_KickableHit;
    self->nField20 = 0;
    self->pfn24 = (void *)&Ov016_KickableTargetPosition;
    self->pfn28 = (void *)&Ov016_KickableQueryParamA;
    self->pfn2c = (void *)&Ov016_GetField54cPtr;
    self->pfn38 = (void *)&Ov016_KickableReturnHome;
    self->pfn44 = (void *)&Ov016_KickableReceiveHit;
    self->pfn3c = (void *)&Ov016_Entry80_SetNodeEnabled;
    self->pfn34 = (void *)&Ov016_AddrOfField0x64c;
    self->wKind = 2;
    return self;
}
