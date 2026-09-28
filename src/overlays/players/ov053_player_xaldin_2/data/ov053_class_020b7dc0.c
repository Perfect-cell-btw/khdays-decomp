#include "game/class_descriptor.h"
/* ov053 class descriptor data_ov053_020b7dc0, 0x020b7dc0-0x020b7dd4 (.data).
 *
 * InstantiateClass (02023930 / 02023960) builds a task object from it: the
 * u16 class / group ids, the constructor whose return is the first state
 * function, the method slot, the size of the zero-filled auxiliary block and
 * the arena reference.  Constructor 020b5a34, method 020b5a68, 0x2e20-byte state.
 */

extern void Ov053_stateCtorConfigReturnHandler(void);
extern void Ov053_initTwoRegionsClearGlobal(void);

GameClassDescriptor data_ov053_020b7dc0 = {
    10,  /* nClassId */
    6,  /* nGroupId */
    Ov053_stateCtorConfigReturnHandler,  /* pfnCtor */
    Ov053_initTwoRegionsClearGlobal,  /* pfnMethod */
    11808,  /* nAuxSize */
    0,  /* pArena */
};
