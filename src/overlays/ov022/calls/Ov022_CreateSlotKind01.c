#pragma thumb on

/* Ov022_CreateSlotKind01 -- create a slot of pool kind 1 from a template.
 *
 * The same shape and the same tail as the other four kinds that use it, with
 * this kind's own constants: it starts in state 1 and parks one field at the
 * largest positive value there is, so whatever compares against it never trips.
 *
 * It is also the kind that reaches furthest into the tail, taking the
 * template's ninth word into the word at the end of it.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

#define SLOT_KIND 1
#define SLOT_TAG 0xb6
#define SLOT_SIZE 0x174
#define START_STATE 1
#define SPAWN_SCALE 0x59a
#define SPAWN_BIAS 0x266
#define NEVER 0x7fffffff

struct SlotTemplate {
    int nWord0;                  /* 0x00 */
    int nWord1;                  /* 0x04 */
    int nWord2;                  /* 0x08 */
    int nWord3;                  /* 0x0c */
    int nWord4;                  /* 0x10 */
    int nWord5;                  /* 0x14 */
    int nWord6;                  /* 0x18 */
    int nWord7;                  /* 0x1c */
    int nWord8;                  /* 0x20 */
};

/* the part of the slot from 0x118 on, shared with pool kinds 0, 2, 3 and 4 */
struct SlotTail {
    u8 nState;                   /* 0x00 */
    u8 pad01;
    u16 nField02;                /* 0x02 */
    int nSpawn;                  /* 0x04 */
    int nField08;                /* 0x08 */
    int nField0c;                /* 0x0c */
    u16 nField10;                /* 0x10 */
    u8 pad12[2];
    int nField14;                /* 0x14 */
    int nField18;                /* 0x18 */
    int nField1c;                /* 0x1c */
    int nField20;                /* 0x20 */
    int nField24;                /* 0x24 */
    int nField28;                /* 0x28 */
    int nField2c;                /* 0x2c */
    int nField30;                /* 0x30 */
    int nField34;                /* 0x34 */
    int nField38;                /* 0x38 */
    int nField3c;                /* 0x3c */
    int nField40;                /* 0x40 */
    u8 nLevel;                   /* 0x44 */
    u8 pad45[3];
    int nField48;                /* 0x48 */
    int nField4c;                /* 0x4c */
};

/* Ov022ActorSlot */
struct ActorSlot {
    u8 pad000;
    u8 nParts;                   /* 0x001, how many parts the slot owns */
    u8 pad002[0x116];
    struct SlotTail tail;        /* 0x118 */
    u8 pad168[8];
    int nField170;               /* 0x170 */
};

/* Ov022ReactionCtx */
struct ReactionCtx {
    u8 pad00[4];
};

extern struct ActorSlot *Ov022_CreateChannel(struct ReactionCtx *pCtx, int nKind,
                                             int nTag, int nSubKind, int nSize);
extern void Ov022_BindSlotParts(struct ActorSlot *pSlot, void *pSeq, int nFirst,
                                int nSecond);
extern int FX_Mul(int nScale, int nValue);

void Ov022_CreateSlotKind01(struct ReactionCtx *pCtx, void *pSeq, int nSubKind,
                         const struct SlotTemplate *pTpl)
{
    struct ActorSlot *pSlot;
    struct SlotTail *pTail;

    pSlot = Ov022_CreateChannel(pCtx, SLOT_KIND, SLOT_TAG, nSubKind, SLOT_SIZE);
    pSlot->nField170 = 0;
    pSlot->nParts = 1;
    Ov022_BindSlotParts(pSlot, pSeq, pTpl->nWord5, pTpl->nWord6);
    pTail = &pSlot->tail;
    pTail->nState = START_STATE;
    pTail->nField02 = 0;
    pTail->nSpawn = FX_Mul(SPAWN_SCALE, pTpl->nWord5) + SPAWN_BIAS;
    pTail->nField08 = 0x900;
    pTail->nField10 = 0;
    pTail->nField1c = 0;
    pTail->nField18 = NEVER;
    pTail->nField20 = pTpl->nWord7;
    pTail->nField24 = 0x1000;
    pTail->nField28 = 0x7000;
    pTail->nField2c = pTpl->nWord0;
    pTail->nLevel = (u8)(pTpl->nWord1 >> 12);
    pTail->nField30 = 8;
    pTail->nField34 = 7;
    pTail->nField48 = 1;
    pTail->nField38 = 0x100;
    pTail->nField3c = 0;
    pTail->nField40 = 0x100;
    pTail->nField0c = pTpl->nWord2;
    pTail->nField14 = pTpl->nWord3;
    pTail->nField4c = pTpl->nWord8;
}
