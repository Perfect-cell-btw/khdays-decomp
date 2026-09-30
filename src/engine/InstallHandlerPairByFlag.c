/* Installs a pair of function pointers into the struct at gFileLoader: if arg0 is nonzero stores
 * EnqueueGfxCmd0 at +0xc and EnqueueGfxCmd1 at +0x10, otherwise stores Gfd_LoadTexB and
 * Gfd_LoadTexPlttB. */

#include "game/engine.h"

extern char gFileLoader[];

void InstallHandlerPairByFlag(int arg0) {
    if (arg0 == 0) {
        *(void **)(gFileLoader + 0xc) = (void *)Gfd_LoadTexB;
        *(void **)(gFileLoader + 0x10) = (void *)Gfd_LoadTexPlttB;
    } else {
        *(void **)(gFileLoader + 0xc) = (void *)EnqueueGfxCmd0;
        *(void **)(gFileLoader + 0x10) = (void *)EnqueueGfxCmd1;
    }
}
