#pragma thumb on

/* Ov022_CreateReactionSlot -- create a reaction slot and load its template.
 *
 * Asks the channel pool for a slot of the reaction kind, marks it live, binds
 * the sequence it will play, then copies the whole nine-word template into the
 * slot's template block. Four of those words are also unpacked into the live
 * fields the driver reads each frame, so the slot is usable before its first
 * step; the spread value is written once and carried across the other two
 * words.
 *
 * The slot starts in state 0, which is the state the driver reports as
 * finished, so it stays inert until an entry arms it.
 */

#include "nitro/types.h"

#define REACTION_KIND 0xb
#define REACTION_TAG 0xc0
#define SLOT_SIZE 0x15c
#define SEQ_TRACKS 5

struct ReactionTemplate {
    int aWord[9];
};

/* Ov022ActorSlot */
struct ActorSlot {
    u8 pad000;
    u8 nParts;                   /* 0x001, how many parts the slot owns */
    u8 pad002[6];
    u16 nSlotFlags;              /* 0x008 */
    u8 pad00a[0xae];
    int aEntryFlags[3];          /* 0x0b8 */
    u8 pad0c4[0x54];
    u8 nState;                   /* 0x118 */
    u8 pad119[0x13];
    int nInterval;               /* 0x12c */
    int nPowerInit;              /* 0x130 */
    int nEntryFlags;             /* 0x134 */
    struct ReactionTemplate tpl; /* 0x138 */
};

/* Ov022ReactionCtx */
struct ReactionCtx {
    u8 pad00[4];
};

extern struct ActorSlot *Ov022_CreateChannel(struct ReactionCtx *pCtx, int nKind,
                                             int nTag, int nSubKind, int nSize);
extern void RegisterSeqAndInit(u16 *pFlags, void *pSeq, int nMode, int nTracks);

void Ov022_CreateReactionSlot(struct ReactionCtx *pCtx, void *pSeq, int nSubKind,
                         const struct ReactionTemplate *pTpl)
{
    struct ActorSlot *pSlot;

    pSlot = Ov022_CreateChannel(pCtx, REACTION_KIND, REACTION_TAG, nSubKind,
                                SLOT_SIZE);
    pSlot->nParts = 1;
    RegisterSeqAndInit(&pSlot->nSlotFlags, pSeq, 1, SEQ_TRACKS);
    pSlot->tpl = *pTpl;
    pSlot->nState = 0;
    pSlot->nInterval = pTpl->aWord[2];
    pSlot->nPowerInit = pTpl->aWord[3];
    pSlot->nEntryFlags = pTpl->aWord[4];
    pSlot->aEntryFlags[2] = pTpl->aWord[5];
    pSlot->aEntryFlags[1] = pSlot->aEntryFlags[2];
    pSlot->aEntryFlags[0] = pSlot->aEntryFlags[1];
}
