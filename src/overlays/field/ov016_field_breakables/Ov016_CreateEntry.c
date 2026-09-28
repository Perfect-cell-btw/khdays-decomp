/* Construct an ov016 list-entry class: allocate its 0x70-byte table with room for
 * `nCount` 0x2f4-byte entries (Ov002_CreateEntryPool), copy the caller's name into the
 * 0x10-byte field at +0x58, install the nine handlers, stamp kind 0x13, and carry the
 * descriptor's two parameters across.
 *
 * The size is written 0xbd * 4 because that is how the ROM materialises it --
 * movs #0xbd + lsls #2, the THUMB idiom for a constant that will not fit in an
 * immediate.  Spelling it 0x2f4 gives the same bytes; spelling it as a literal
 * that needs a pool entry does not.
 *
 * The handler stores are written in field order even though the ROM emits +0x34
 * before +0x2c and +0x44 before +0x3c -- that reordering is the scheduler's, and
 * mwcc reproduces it from the natural order. */
typedef struct {
    char *pszName;          /* +0x00 */
    int nParamA;            /* +0x04 */
    int nParamB;            /* +0x08 */
} Ov016EntryDesc;

typedef struct {
    int nField00;           /* +0x00 */
    int nField04;           /* +0x04 */
    void *pfnA;             /* +0x08 */
    void *pfnB;             /* +0x0c */
    void *pfnC;             /* +0x10 */
    void *pfnD;             /* +0x14 */
    void *pfnE;             /* +0x18 */
    void *pfnF;             /* +0x1c */
    int nField20;
    int nField24;
    int nField28;
    void *pfnG;             /* +0x2c */
    char pad30[4];
    void *pfnH;             /* +0x34 */
    int nField38;
    void *pfnI;             /* +0x3c */
    char pad40[4];
    int nField44;
    char pad48[4];
    unsigned short wKind;   /* +0x4c */
    char pad4e[0xa];
    char szName[0x10];      /* +0x58 */
    int nParamA;            /* +0x68 */
    int nParamB;            /* +0x6c */
} Ov016Entry;

extern void *Ov002_CreateEntryPool(int headerSize, int entrySize, int count);
extern char *strncpy(char *dst, const char *src, unsigned int n);
extern void Ov016_StoreByteAt0x2b8FromByte(void);
extern void Ov016_ReleaseEmbeddedNode(void);
extern void Ov016_RebindActorModelAndIdle(void);
extern void Ov016_Entry_ReleaseBoundObject(void);
extern void Ov016_LiftBindSequence(void);
extern void Ov016_Entry_QueryStateReturn8(void);
extern void Ov016_AddrOfField0x2C4(void);
extern void Ov016_AddrOfField0xE0(void);
extern void Ov016_SetEmbeddedSceneNodeEnabled(void);

Ov016Entry *Ov016_CreateEntry(int nCount, Ov016EntryDesc *desc) {
    Ov016Entry *self = Ov002_CreateEntryPool(0x70, 0xbd * 4, nCount);

    strncpy(self->szName, desc->pszName, 0x10);
    self->nField00 = 0;
    self->nField04 = 0;
    self->pfnA = (void *)&Ov016_StoreByteAt0x2b8FromByte;
    self->pfnB = (void *)&Ov016_ReleaseEmbeddedNode;
    self->pfnC = (void *)&Ov016_RebindActorModelAndIdle;
    self->pfnD = (void *)&Ov016_Entry_ReleaseBoundObject;
    self->pfnE = (void *)&Ov016_LiftBindSequence;
    self->pfnF = (void *)&Ov016_Entry_QueryStateReturn8;
    self->nField20 = 0;
    self->nField24 = 0;
    self->nField28 = 0;
    self->pfnH = (void *)&Ov016_AddrOfField0x2C4;
    self->pfnG = (void *)&Ov016_AddrOfField0xE0;
    self->nField38 = 0;
    self->nField44 = 0;
    self->pfnI = (void *)&Ov016_SetEmbeddedSceneNodeEnabled;
    self->wKind = 0x13;
    self->nParamA = desc->nParamA;
    self->nParamB = desc->nParamB;
    return self;
}
