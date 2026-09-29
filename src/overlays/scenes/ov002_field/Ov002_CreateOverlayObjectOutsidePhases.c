/* Build the overlay object at +0x8d10 and silence input, but only outside the
 * link phases 7 and 8..13 -- the ROM tests 7 on its own and folds the 8..13 span
 * into one unsigned range check. +0x8b58 is the phase word Ov002_GetPhaseWord
 * reads. */

#include "game/engine.h"

typedef struct {
    char pad0000[0x8b58];
    int nPhase;                 /* +0x8b58 */
    char pad8b5c[0x1b4];
    int nOverlayObject;         /* +0x8d10 */
} Ov002RootContext;

extern int InstantiateClass(const void *cls, int params);

extern Ov002RootContext *data_ov002_0207fa00;
extern char data_02042734[];

void Ov002_CreateOverlayObjectOutsidePhases(void) {
    Ov002RootContext *root = data_ov002_0207fa00;
    int *slot = &root->nOverlayObject;
    int phase = root->nPhase;

    if (phase != 7 && (unsigned int)(phase - 8) > 5) {
        *slot = InstantiateClass(data_02042734, 0);
        func_02020878(0);
    }
}
