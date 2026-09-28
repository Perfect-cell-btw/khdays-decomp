#include "game/class_descriptor.h"
/* ov065 class descriptor data_ov065_020b72a0, 0x020b72a0-0x020b72b4 (.data).
 *
 * InstantiateClass (02023930 / 02023960) builds a task object from it: the
 * u16 class / group ids, the constructor whose return is the first state
 * function, the method slot, the size of the zero-filled auxiliary block and
 * the arena reference.  Constructor 020b5a34, method 020b5a5c, 0x34b0-byte state.
 */

extern void Ov065_stateCtorReturnHandler(void);
extern void Ov065_stateDtorCleanup(void);

GameClassDescriptor data_ov065_020b72a0 = {
    10,  /* nClassId */
    6,  /* nGroupId */
    Ov065_stateCtorReturnHandler,  /* pfnCtor */
    Ov065_stateDtorCleanup,  /* pfnMethod */
    13488,  /* nAuxSize */
    0,  /* pArena */
};
