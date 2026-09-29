/* SND_GetFirstInstDataPos: the position before a bank's first instrument (program 0, index 0).
 * The NitroSDK's own form: the struct comes back through the pointer the caller passes in r0. */

#include "nitro/snd.h"

SNDInstPos SND_GetFirstInstDataPos(const SNDBankData *bank)
{
    SNDInstPos pos;
    (void)bank;
    pos.prgNo = 0;
    pos.index = 0;
    return pos;
}
