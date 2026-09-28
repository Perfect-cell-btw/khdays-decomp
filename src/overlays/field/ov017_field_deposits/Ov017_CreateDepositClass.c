/* Ov017_CreateDepositClass -- Ov017_CreateDepositClass: allocates the class-0x15 definition (a
 * 0x94-byte table with room for `nCount` 0x4e4-byte pieces, Ov002_CreateEntryPool), copies the
 * descriptor's three sequence names into +0x58 (idle), +0x68 (hit effect) and +0x78 (cracks)
 * -- each field emptied first and only copied when the descriptor names one -- and carries its
 * parameter word (+0x88), node kind (+0x8c) and three placement shorts (+0x8e..+0x92) across;
 * installs the nine deposit handlers (message 0207fb94, init 0207fc08, refresh 0207fd88,
 * release 0207fba8, start 0207fc18, hit 0207fdb4, node 0207fe10, owner 0207fe18, 0207fe24) and
 * stamps kind 0x15.  The deposit is ov017's multi-hit prize object. */

#include "nitro/types.h"

typedef struct Ov017DepositDesc {
    const char *pszSeqA;      /* 0x00: idle */
    const char *pszSeqB;      /* 0x04: hit effect */
    const char *pszSeqC;      /* 0x08: cracks */
    int   nParam;             /* 0x0c */
    char  nNodeKind;          /* 0x10 */
    u8    pad_11;
    short nPlaceA;            /* 0x12 */
    short nPlaceB;            /* 0x14 */
    short nPlaceC;            /* 0x16 */
} Ov017DepositDesc;

typedef struct Ov017DepositDef {
    int nField00;             /* 0x00 */
    int nField04;             /* 0x04 */
    void *pfnMessage;         /* 0x08 */
    void *pfnInit;            /* 0x0c */
    void *pfnRefresh;         /* 0x10 */
    void *pfnRelease;         /* 0x14 */
    void *pfnStart;           /* 0x18 */
    void *pfnHit;             /* 0x1c */
    int nField20;             /* 0x20 */
    void *pfnGetNode;         /* 0x24 */
    void *pfnGetOwner;        /* 0x28 */
    void *pfnGetA;            /* 0x2c */
    void *pad30;
    void *pad34;
    int nField38;             /* 0x38 */
    int nField3c;             /* 0x3c */
    void *pad40;
    int nField44;             /* 0x44 */
    int nField48;
    u16 nKind;                /* 0x4c */
    char pad4e[0xa];
    char szSeqA[0x10];        /* 0x58 */
    char szSeqB[0x10];        /* 0x68 */
    char szSeqC[0x10];        /* 0x78 */
    int  nParam;              /* 0x88 */
    char nNodeKind;           /* 0x8c */
    u8   pad_8d;
    short nPlaceA;            /* 0x8e */
    short nPlaceB;            /* 0x90 */
    short nPlaceC;            /* 0x92 */
} Ov017DepositDef;

extern void *Ov002_CreateEntryPool(int headerSize, int entrySize, int count);
extern char *strncpy(char *pDst, const char *pSrc, unsigned int nLen);
extern void Ov017_Deposit_OnMessage(void);
extern void Ov017_tailDispatch(void);
extern void Ov017_SetupSubActionWithClampedArg(void);
extern void Ov017_DepositRelease(void);
extern void Ov017_DepositStart(void);
extern void Ov017_DepositHit(void);
extern void Ov017_AddrOfField0x1C(void);
extern void Ov017_Deposit_GetOwner(void);
extern void Ov017_AddrOfField0xE0(void);

Ov017DepositDef *Ov017_CreateDepositClass(int nCount, Ov017DepositDesc *pDesc)
{
    Ov017DepositDef *pDef;

    pDef = Ov002_CreateEntryPool(0x94, 0x4e4, nCount);
    pDef->szSeqA[0] = 0;
    if (pDesc->pszSeqA != 0) {
        strncpy(pDef->szSeqA, pDesc->pszSeqA, 0x10);
    }
    pDef->szSeqB[0] = 0;
    if (pDesc->pszSeqB != 0) {
        strncpy(pDef->szSeqB, pDesc->pszSeqB, 0x10);
    }
    pDef->szSeqC[0] = 0;
    if (pDesc->pszSeqC != 0) {
        strncpy(pDef->szSeqC, pDesc->pszSeqC, 0x10);
    }
    pDef->nParam = pDesc->nParam;
    pDef->nNodeKind = pDesc->nNodeKind;
    pDef->nPlaceA = pDesc->nPlaceA;
    pDef->nPlaceB = pDesc->nPlaceB;
    pDef->nPlaceC = pDesc->nPlaceC;
    pDef->nField00 = 0;
    pDef->nField04 = 0;
    pDef->pfnMessage = (void *)Ov017_Deposit_OnMessage;
    pDef->pfnInit = (void *)Ov017_tailDispatch;
    pDef->pfnRefresh = (void *)Ov017_SetupSubActionWithClampedArg;
    pDef->pfnRelease = (void *)Ov017_DepositRelease;
    pDef->pfnStart = (void *)Ov017_DepositStart;
    pDef->pfnHit = (void *)Ov017_DepositHit;
    pDef->nField20 = 0;
    pDef->pfnGetNode = (void *)Ov017_AddrOfField0x1C;
    pDef->pfnGetOwner = (void *)Ov017_Deposit_GetOwner;
    pDef->pfnGetA = (void *)Ov017_AddrOfField0xE0;
    pDef->nField38 = 0;
    pDef->nField44 = 0;
    pDef->nField3c = 0;
    pDef->nKind = 0x15;
    return pDef;
}
