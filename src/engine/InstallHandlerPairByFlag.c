/* Installs a pair of function pointers into the struct at data_0204bbfc: if arg0 is nonzero stores
 * EnqueueGfxCmd0 at +0xc and EnqueueGfxCmd1 at +0x10, otherwise stores Gfd_LoadTexB and
 * Gfd_LoadTexPlttB. */

#include "game/engine.h"

extern char data_0204bbfc[];

void InstallHandlerPairByFlag(int arg0) {
    if (arg0 == 0) {
        *(void **)(data_0204bbfc + 0xc) = (void *)Gfd_LoadTexB;
        *(void **)(data_0204bbfc + 0x10) = (void *)Gfd_LoadTexPlttB;
    } else {
        *(void **)(data_0204bbfc + 0xc) = (void *)EnqueueGfxCmd0;
        *(void **)(data_0204bbfc + 0x10) = (void *)EnqueueGfxCmd1;
    }
}
