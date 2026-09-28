/* Ov016_KickableAckPeer -- Ov016_KickableAckPeer: record peer nPeer's acknowledgement in the ack
 * mask (+0x61d); once every connected peer (01fff974 = the session's peer mask) has
 * answered, drop the "waiting" bit (bit 4 of +0x61c), clear the mask and report 1. */
#include "nitro/types.h"

typedef struct Ov016Kickable {
    u8 pad_000[0x61c];
    u8 nSyncFlags;            /* 0x61c: bit 4 = waiting for the peers */
    u8 nAckMask;              /* 0x61d: one bit per peer */
} Ov016Kickable;

extern int GetGlobalU16At6(void);   /* Session_GetPeerMask */

int Ov016_KickableAckPeer(Ov016Kickable *pSelf, int nPeer)
{
    pSelf->nAckMask |= 1 << nPeer;
    if ((pSelf->nAckMask & 0xf) == GetGlobalU16At6()) {
        pSelf->nSyncFlags &= ~0x10;
        pSelf->nAckMask = 0;
        return 1;
    }
    return 0;
}
