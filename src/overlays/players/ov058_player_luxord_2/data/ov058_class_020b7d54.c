#include "game/class_descriptor.h"
/* ov058 class descriptor gOv058LuxordClass, 0x020b7d54-0x020b7d68 (.data).
 *
 * InstantiateClass (02023930 / 02023960) builds a task object from it: the
 * u16 class / group ids, the constructor whose return is the first state
 * function, the method slot, the size of the zero-filled auxiliary block and
 * the arena reference.  Constructor 020b5a34, method 020b5a5c, 0x3010-byte state.
 */

extern void Ov058_stateCtorReturnHandler(void);
extern void Ov058_stateDtorCleanup(void);

GameClassDescriptor gOv058LuxordClass = {
    10,  /* nClassId */
    6,  /* nGroupId */
    Ov058_stateCtorReturnHandler,  /* pfnCtor */
    Ov058_stateDtorCleanup,  /* pfnMethod */
    12304,  /* nAuxSize */
    0,  /* pArena */
};
