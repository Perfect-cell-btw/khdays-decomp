/* Ov016_CreateFollowerClass -- Ov016_CreateFollowerClass: allocate the class-0x16 definition (a
 * 0x68-byte table with room for `nCount` 0x1cc-byte pieces, Ov002_CreateEntryPool), copy the
 * descriptor's name into the 0x10-byte field at +0x58 when there is one (the field is emptied
 * first), install the nine handlers of the follower (the object that trails a player) and stamp
 * kind 0x16.
 *
 * Sibling of Ov016_CreateEntry (0207feb8, kind 0x13) and Ov016_CreateEntryClass80 (02081f64);
 * the size is written 0x73 * 4 because that is how the ROM materialises it. */

#include "nitro/types.h"

typedef struct Ov016FollowerDesc {
    char *pszName;            /* 0x00 */
} Ov016FollowerDesc;

typedef struct Ov016FollowerDef {
    int nField00;             /* 0x00 */
    int nField04;             /* 0x04 */
    int nField08;             /* 0x08 */
    void *pfnInit;            /* 0x0c */
    void *pfnSubmit;          /* 0x10 */
    void *pfnRelease;         /* 0x14 */
    void *pfnStart;           /* 0x18 */
    int nField1c;             /* 0x1c */
    int nField20;             /* 0x20 */
    int nField24;             /* 0x24 */
    void *pad28;
    void *pfnQuery;           /* 0x2c */
    void *pfnMoveTo;          /* 0x30 */
    void *pfnGetB;            /* 0x34 */
    int nField38;             /* 0x38 */
    void *pfnStep;            /* 0x3c */
    void *pfnGetA;            /* 0x40 */
    int nField44;             /* 0x44 */
    int nField48;
    u16 nKind;                /* 0x4c */
    char pad4e[0xa];
    char szName[0x10];        /* 0x58 */
} Ov016FollowerDef;

extern void *Ov002_CreateEntryPool(int headerSize, int entrySize, int count);
extern char *strncpy(char *pDst, const char *pSrc, unsigned int nLen);
extern void Ov016_ReleaseEmbeddedNode_3(void);
extern void Ov016_SubmitNodeUnlessHidden(void);
extern void Ov016_Follower_Release(void);
extern void Ov016_FollowerStart(void);
extern void Ov016_AddrOfField0xD0(void);
extern void Ov016_FollowerMoveTo(void);
extern void Ov016_AddrOfField0x1A0(void);
extern void Ov016_AddrOfField0x1C(void);
extern void Ov016_SetNodeEnabled(void);

Ov016FollowerDef *Ov016_CreateFollowerClass(int nCount, Ov016FollowerDesc *pDesc)
{
    Ov016FollowerDef *pDef;

    pDef = Ov002_CreateEntryPool(0x68, 0x73 * 4, nCount);
    pDef->szName[0] = 0;
    if (pDesc->pszName != 0) {
        strncpy(pDef->szName, pDesc->pszName, 0x10);
    }
    pDef->nField00 = 0;
    pDef->nField04 = 0;
    pDef->nField08 = 0;
    pDef->pfnInit = (void *)Ov016_ReleaseEmbeddedNode_3;
    pDef->pfnSubmit = (void *)Ov016_SubmitNodeUnlessHidden;
    pDef->pfnRelease = (void *)Ov016_Follower_Release;
    pDef->pfnStart = (void *)Ov016_FollowerStart;
    pDef->nField1c = 0;
    pDef->nField20 = 0;
    pDef->nField24 = 0;
    pDef->pfnQuery = (void *)Ov016_AddrOfField0xD0;
    pDef->pfnMoveTo = (void *)Ov016_FollowerMoveTo;
    pDef->pfnGetB = (void *)Ov016_AddrOfField0x1A0;
    pDef->nField38 = 0;
    pDef->pfnGetA = (void *)Ov016_AddrOfField0x1C;
    pDef->nField44 = 0;
    pDef->pfnStep = (void *)Ov016_SetNodeEnabled;
    pDef->nKind = 0x16;
    return pDef;
}
