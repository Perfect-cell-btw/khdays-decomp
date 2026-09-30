/* ov022: bind a reaction request's four animations.
 *
 * Each of the four animations is registered against the shared reaction
 * descriptor, then bound to its own slot under that slot's own name, and the
 * request is marked active. The four names are copied to the stack first
 * because they are read one per pass.
 */

#include "nitro/types.h"
#include "game/engine.h"

struct Anim {
    u8 pad0000[0x108];
};

struct Bind {
    u8 pad0000[0x24];
};

struct Request {
    u8 nFlags;                   /* 0x0000 */
    u8 pad0001[0x1f];
    struct Anim aAnims[4];       /* 0x0020 */
    struct Bind aBinds[4];       /* 0x0440 */
};

/* One name per animation slot. */
struct SlotNames {
    char *apNames[4];
};

extern struct SlotNames data_ov022_020b2510;
extern char gOv022BaEfIPackPath[];

void Ov022_BindReactionAnims(struct Request *pReq)
{
    struct SlotNames names;
    int i;

    names = data_ov022_020b2510;
    for (i = 0; i < 4; i++) {
        RegisterSeqAndInit(&pReq->aAnims[i], gOv022BaEfIPackPath, 1, 5);
    }
    for (i = 0; i < 4; i++) {
        Snd_RegisterSeqAndBind(&pReq->aBinds[i], &pReq->aAnims[i], names.apNames[i], 5);
    }
    pReq->nFlags |= 1;
}
