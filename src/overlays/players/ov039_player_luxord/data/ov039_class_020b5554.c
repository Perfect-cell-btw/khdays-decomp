#include "game/class_descriptor.h"
/* ov039 class descriptor gOv039LuxordClass, 0x020b5554-0x020b5568 (.data).
 *
 * InstantiateClass (02023930 / 02023960) builds a task object from it: the
 * u16 class / group ids, the constructor whose return is the first state
 * function, the method slot, the size of the zero-filled auxiliary block and
 * the arena reference.  Constructor 020b3234, method 020b325c, 0x3010-byte state.
 */

extern void Ov039_stateCtorReturnHandler(void);
extern void Ov039_stateDtorCleanup(void);

GameClassDescriptor gOv039LuxordClass = {
    10,  /* nClassId */
    6,  /* nGroupId */
    Ov039_stateCtorReturnHandler,  /* pfnCtor */
    Ov039_stateDtorCleanup,  /* pfnMethod */
    12304,  /* nAuxSize */
    0,  /* pArena */
};
