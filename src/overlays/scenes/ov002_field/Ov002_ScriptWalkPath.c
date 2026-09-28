
#include "nitro/types.h"

extern int ScriptVm_ReadOperandInt(void *pCtx, int nArgs);
extern int ScriptVm_ReadOperandFx32(void *pCtx, int nArgs);
extern int Ov002_SendShuffledPathPoints(int nWho, int nKind, int nMode, int nCount,
                               int (*aPath)[3]);

/* Script VM command: send a roster slot along a path.
 *
 * Four leading operands say who moves, in what way, in what mode and how many
 * waypoints follow; each waypoint is then three fixed point operands.  Operand
 * slots are eight bytes each, so the cursor walks 0x20 past the header and
 * 0x18 past every waypoint.  Reports 1 when the walk was accepted.
 */
int Ov002_ScriptWalkPath(void *pCtx, int nArgs)
{
    int aPath[128][3];
    int nWho;
    int nKind;
    int nMode;
    int nCount;
    int nLast;
    int i;

    nWho = ScriptVm_ReadOperandInt(pCtx, nArgs);
    nKind = ScriptVm_ReadOperandInt(pCtx, nArgs + 8);
    nMode = ScriptVm_ReadOperandInt(pCtx, nArgs + 0x10);
    nLast = nArgs + 0x18;
    nArgs += 0x20;
    nCount = ScriptVm_ReadOperandInt(pCtx, nLast);

    for (i = 0; i < nCount; i++) {
        aPath[i][0] = ScriptVm_ReadOperandFx32(pCtx, nArgs);
        aPath[i][1] = ScriptVm_ReadOperandFx32(pCtx, nArgs + 8);
        nLast = nArgs + 0x10;
        nArgs += 0x18;
        aPath[i][2] = ScriptVm_ReadOperandFx32(pCtx, nLast);
    }

    if (Ov002_SendShuffledPathPoints(nWho, (u8)nKind, nMode, nCount, aPath) == 0) {
        return 0;
    }
    return 1;
}
