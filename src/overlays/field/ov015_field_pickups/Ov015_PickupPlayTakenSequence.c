/* Ov015_PickupPlayTakenSequence -- Ov015_PickupPlayTakenSequence: while the pickup's "taken"
 * sequence is running (bit 0 of +0x14d), advance its tracks by nDelta; once it ends the
 * bit is cleared and 1 returned, otherwise the sequence node (+0x30) is drawn.  0 when
 * nothing was running or the sequence is still going. */

#include "nitro/types.h"

extern unsigned short  Sequence_UpdateTracks(void *pNode, int nDelta);   /* Sequence_UpdateTracks */
extern void Scene_DrawNode(void *pNode);               /* Scene_DrawNode */

typedef struct Ov015Pickup {
    u8  pad_000[0x30];
    u8  sequence[0x14d - 0x30];  /* 0x030: scene node + sequence */
    u8  nStateBits;              /* 0x14d: bit 0 = the taken sequence is playing */
} Ov015Pickup;

int Ov015_PickupPlayTakenSequence(Ov015Pickup *pPickup, int nDelta)
{
    if (pPickup->nStateBits & 1) {
        if (Sequence_UpdateTracks(pPickup->sequence, nDelta) != 0) {
            pPickup->nStateBits &= ~1;
            return 1;
        }
        Scene_DrawNode(pPickup->sequence);
    }
    return 0;
}
