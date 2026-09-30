#include "game/class_descriptor.h"
/* ov080 class descriptor gOv080RikuClass, 0x020b9b40-0x020b9b54 (.data).
 *
 * InstantiateClass (02023930 / 02023960) builds a task object from it: the
 * u16 class / group ids, the constructor whose return is the first state
 * function, the method slot, the size of the zero-filled auxiliary block and
 * the arena reference.  Constructor 020b8114, method 020b813c, 0x32ec-byte state.
 */

extern void Ov080_stateCtorReturnHandler(void);
extern void Ov080_stateDtorCleanup(void);

GameClassDescriptor gOv080RikuClass = {
    10,  /* nClassId */
    6,  /* nGroupId */
    Ov080_stateCtorReturnHandler,  /* pfnCtor */
    Ov080_stateDtorCleanup,  /* pfnMethod */
    13036,  /* nAuxSize */
    0,  /* pArena */
};
