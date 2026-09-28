/* ov022: decide whether the actor may start the move this owner is asking for.
 *
 * It is one long refusal chain: every check that fails answers yes-refuse, and
 * only a run through all of them answers no. The order is the cheap questions
 * first -- is there a session at all, is a mission ending, is a global flag up,
 * is this one particular scene running -- then the per-actor ones.
 *
 * The local player's own actor asks two extra questions; anyone else's only has
 * to have its action lock clear.
 *
 * After that it is mostly flag words. Two of them are sixty-four bits wide, so
 * each test reads both halves and masks the one its constant reaches. One mask
 * is not constant: a bit of the first word drops a single bit out of the mask
 * applied to the second, which is why the ROM builds it with subtractions off a
 * register that already holds 0x10 rather than loading two literals.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef unsigned long long u64;

#define SCENE_TAG 0x6c
#define SCENE_BIT 4
#define GAME_FLAG 0x20e0
#define CHARGE_DONE 3

#define FLAGS_BIT44 0x100000000000ULL
#define FLAGS_BIT36 0x1000000000ULL
#define FLAGS_REFUSE 0x2100a2904ULL
#define FLAGS2_BIT15 0x8000ULL
#define FLAGS2_BIT8 0x100ULL
#define FLAGS2_REFUSE 0x1020013690ULL
#define FLAGS2_RELAXED 0x80ULL

/* Ov022AnimRequest */
struct AnimRequest {
    u8 pad00[0x10];
};

/* Ov022ReactionCtx */
struct ReactionCtx {
    u8 pad00[0x5c];
};

/* Ov022Actor */
struct Actor {
    u64 nFlags;                  /* 0x0000 */
    u8 nOwner;                   /* 0x0008 */
    u8 pad0009[9];
    u16 nHp;                     /* 0x0012 */
    u8 pad0014[6];
    u16 nButtons2;               /* 0x001a */
    u8 pad001c[0x448];
    u64 nFlags2;                 /* 0x0464 */
    u8 pad046c[0x7c];
    u8 nInputLow : 4;            /* 0x04e8 bits 0..3 */
    u8 bInputBit4 : 1;           /* bit 4 */
    u8 nInputHigh : 3;
    u8 pad04e9[0x1a3];
    int nActionCount;            /* 0x068c */
    u8 pad0690[4];
    u8 nFlags694Low : 3;         /* 0x0694 bits 0..2 */
    u8 bActionLocked : 1;        /* bit 3 */
    u8 nFlags694High : 4;
    u8 pad0695[0x6fb];
    struct AnimRequest animReq;  /* 0x0d90 */
    u8 pad0da0[0x1008];
    u8 reactionBlk;              /* 0x1da8 */
    u8 pad1da9[0x4df];
    struct ReactionCtx ctx;      /* 0x2288 */
    u8 pad22e4[0x48c];
    u8 nChargeKind;              /* 0x2770 */
};

/* Ov022ActionOwner; only the actor pointer is proven so far */
struct MoveOwner {
    u8 pad000[0x328];
    struct Actor *pActor;        /* 0x328 */
};

extern u8 data_0204c240;

extern int Session_IsReady(void);
extern int Session_GetLocalPlayerIndex(void);
extern int GameState_IsFlagSet(u32 nFlag);
extern int Ov002_IsMissionClearFinished(int nArg);
extern int Ov002_GetStateWord(void);
extern int Ov002_RunShutdownHook(void);
extern int Ov022_IsByte8ZeroOr3(struct AnimRequest *pReq);
extern int func_ov022_020ab350(struct Actor *pActor);
extern int func_ov022_0209fc78(struct Actor *pActor, int nSlot);
extern int func_ov022_02095618(struct MoveOwner *pOwner);
extern int func_ov022_02094bec(struct MoveOwner *pOwner);
extern int Ov022_IsByte2Zero(struct ReactionCtx *pCtx);
extern int Ov022_IsByte1Zero(u8 *pBlk);

int Ov022_IsActionBlocked(struct MoveOwner *pOwner)
{
    struct Actor *pActor;
    u64 nMask;

    pActor = pOwner->pActor;
    if (Session_IsReady() == 0) {
        return 0;
    }
    if (Ov022_IsByte8ZeroOr3(&pActor->animReq) == 0) {
        return 1;
    }
    if (Ov002_IsMissionClearFinished(0) != 0) {
        return 1;
    }
    if (GameState_IsFlagSet(GAME_FLAG) != 0) {
        return 1;
    }
    if (Ov002_GetStateWord() == SCENE_TAG) {
        if ((data_0204c240 & SCENE_BIT) == 0) {
            return 1;
        }
    }
    if (pActor->nOwner == Session_GetLocalPlayerIndex()) {
        if (Ov002_RunShutdownHook() != 0 || func_ov022_020ab350(pActor) != 0) {
            return 1;
        }
    } else {
        if (pActor->bActionLocked != 0) {
            return 1;
        }
    }
    if (func_ov022_0209fc78(pActor, -1) == 0) {
        return 1;
    }
    if (func_ov022_02095618(pOwner) == 0) {
        return 1;
    }
    if ((pActor->nFlags & FLAGS_BIT44) == 0) {
        if ((pActor->nButtons2 & 1) == 0) {
            return 1;
        }
        if (pActor->bInputBit4 == 0) {
            return 1;
        }
    }
    if (func_ov022_02094bec(pOwner) == 0) {
        return 1;
    }
    if (Ov022_IsByte2Zero(&pActor->ctx) == 0
        || Ov022_IsByte1Zero(&pActor->reactionBlk) == 0) {
        return 1;
    }
    if ((pActor->nFlags2 & FLAGS2_BIT15) != 0
        || (pActor->nFlags2 & FLAGS2_BIT8) != 0) {
        return 1;
    }
    if (pActor->nChargeKind == CHARGE_DONE) {
        return 1;
    }
    nMask = FLAGS2_REFUSE;
    if ((pActor->nFlags & FLAGS_BIT36) != 0) {
        nMask = nMask & ~FLAGS2_RELAXED;
    }
    if ((pActor->nFlags2 & nMask) != 0) {
        return 1;
    }
    if ((pActor->nFlags & FLAGS_REFUSE) != 0) {
        return 1;
    }
    if (pActor->nHp == 0) {
        return 1;
    }
    if (pActor->nActionCount == 0) {
        return 1;
    }
    return 0;
}
