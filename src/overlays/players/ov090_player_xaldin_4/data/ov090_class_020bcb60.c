#include "game/class_descriptor.h"
/* ov090 class descriptor data_ov090_020bcb60, 0x020bcb60-0x020bcb74 (.data).
 *
 * InstantiateClass (02023930 / 02023960) builds a task object from it: the
 * u16 class / group ids, the constructor whose return is the first state
 * function, the method slot, the size of the zero-filled auxiliary block and
 * the arena reference.  Constructor 020ba7d4, method 020ba808, 0x2e20-byte state.
 */

extern void Ov090_stateCtorConfigReturnHandler(void);
extern void Ov090_initTwoRegionsClearGlobal(void);

GameClassDescriptor data_ov090_020bcb60 = {
    10,  /* nClassId */
    6,  /* nGroupId */
    Ov090_stateCtorConfigReturnHandler,  /* pfnCtor */
    Ov090_initTwoRegionsClearGlobal,  /* pfnMethod */
    11808,  /* nAuxSize */
    0,  /* pArena */
};
