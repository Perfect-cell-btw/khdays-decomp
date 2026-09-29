/* Copy the u16 id at obj+2 into *out, then tail-call MsgQueue_SendGate(1, out, (u16)arg). */

#include "game/engine.h"

void Ov107_EmitIdEvent(int obj, unsigned short *out, int arg) {
    *out = *(unsigned short *)(obj + 2);
    MsgQueue_SendGate(1, out, (unsigned short)arg);
}
