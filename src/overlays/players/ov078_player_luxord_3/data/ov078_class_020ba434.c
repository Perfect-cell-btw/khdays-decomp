#include "game/class_descriptor.h"
/* ov078 class descriptor data_ov078_020ba434, 0x020ba434-0x020ba448 (.data).
 *
 * InstantiateClass (02023930 / 02023960) builds a task object from it: the
 * u16 class / group ids, the constructor whose return is the first state
 * function, the method slot, the size of the zero-filled auxiliary block and
 * the arena reference.  Constructor 020b8114, method 020b813c, 0x3010-byte state.
 */

extern void Ov078_stateCtorReturnHandler(void);
extern void Ov078_stateDtorCleanup(void);

GameClassDescriptor data_ov078_020ba434 = {
    10,  /* nClassId */
    6,  /* nGroupId */
    Ov078_stateCtorReturnHandler,  /* pfnCtor */
    Ov078_stateDtorCleanup,  /* pfnMethod */
    12304,  /* nAuxSize */
    0,  /* pArena */
};
