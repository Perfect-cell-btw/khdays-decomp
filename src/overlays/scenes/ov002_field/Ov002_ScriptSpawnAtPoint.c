
/* The place request as it goes out over the link.  The leading halfword is
   left alone; the sender fills only what follows. */

#include "nitro/types.h"

typedef struct Ov002PlaceMsg {
    s16 hUnused;                /* 0x00 */
    s16 nWho;                   /* 0x02 */
    s16 nWhat;                  /* 0x04 */
    s16 nX;                     /* 0x06 */
    s16 nY;                     /* 0x08 */
    s16 nZ;                     /* 0x0a */
} Ov002PlaceMsg;

extern int ScriptVm_ReadOperandInt(void *pCtx, int nArgs);
extern int ScriptVm_ReadOperandFx32(void *pCtx, int nArgs);
/* Non-zero once the link is up and the spawn has to go out over it. */
extern int Session_IsActive(void);
/* Index of the local player; zero for the one running the session. */
extern int Session_GetLocalPlayerIndex(void);
extern void Slot_Spawn(int nWho, int nWhat, int *pPos, int nFlags);
extern int Ov002_BuildSessionCommand(int nOp, Ov002PlaceMsg *pMsg);

/* Script VM command: spawn something at a point.
 *
 * Operand slots are eight bytes each.  Two say what to spawn, three carry the
 * point, and a last one asks for the spawn to be shared with the other
 * players.  A local spawn goes straight through; a shared one is sent instead,
 * with the point coarsened to sixteenths so it fits in halfwords, under a
 * different op depending on whether this machine is running the session.
 *
 * Reports 0 only when the send was refused.
 */
int Ov002_ScriptSpawnAtPoint(void *pCtx, int nArgs)
{
    int aPos[3];
    Ov002PlaceMsg msg;
    int nWho;
    int nWhat;
    int nOp;

    nWho = ScriptVm_ReadOperandInt(pCtx, nArgs);
    nWhat = ScriptVm_ReadOperandInt(pCtx, nArgs + 8);
    aPos[0] = ScriptVm_ReadOperandFx32(pCtx, nArgs + 0x10);
    aPos[1] = ScriptVm_ReadOperandFx32(pCtx, nArgs + 0x18);
    aPos[2] = ScriptVm_ReadOperandFx32(pCtx, nArgs + 0x20);
    nArgs += 0x28;

    if (ScriptVm_ReadOperandInt(pCtx, nArgs) == 0 || Session_IsActive() == 0) {
        Slot_Spawn(nWho, nWhat, aPos, 0);
    } else {
        msg.nWho = (s16)nWho;
        msg.nWhat = (s16)nWhat;
        msg.nX = (s16)(aPos[0] >> 4);
        msg.nY = (s16)(aPos[1] >> 4);
        msg.nZ = (s16)(aPos[2] >> 4);

        if (Session_GetLocalPlayerIndex() == 0) {
            nOp = 0x17;
        } else {
            nOp = 0x18;
        }

        if (Ov002_BuildSessionCommand(nOp, &msg) == 0xffff) {
            return 0;
        }
    }

    return 1;
}
