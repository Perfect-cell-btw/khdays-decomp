/* Post the message, unless the link layer says there is nobody to post to -- in
 * which case it reports success anyway, because a solo session has nothing to
 * wait for. The tag is resolved through the id table before being handed on.
 *
 * The id parameter is an INT even though the resolver takes an unsigned short:
 * the ROM narrows it at the call site (lsl #16 / lsr #16). Declaring the
 * parameter unsigned short makes the narrowing redundant and drops the pair. */

#include "game/engine.h"

extern int Ov002_PublishStateChange(void *a, void *b, int tag);

int Ov002_PostMessage(void *a, void *b, int id) {
    if (Session_IsReady() != 0) {
        return Ov002_PublishStateChange(a, b, (short)Rand16NextScaled((unsigned short)id));
    }

    return 1;
}
