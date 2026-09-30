#include "game/class_descriptor.h"
/* ov096 class descriptor gOv096MarluxiaClass, 0x020bc014-0x020bc028 (.data).
 *
 * InstantiateClass (02023930 / 02023960) builds a task object from it: the
 * u16 class / group ids, the constructor whose return is the first state
 * function, the method slot, the size of the zero-filled auxiliary block and
 * the arena reference.  Constructor 020ba7d4, method 020ba7fc, 0x2f90-byte state.
 */

extern void Ov096_stateCtorReturnHandler(void);
extern void Ov096_setupTriple(void);

GameClassDescriptor gOv096MarluxiaClass = {
    10,  /* nClassId */
    6,  /* nGroupId */
    Ov096_stateCtorReturnHandler,  /* pfnCtor */
    Ov096_setupTriple,  /* pfnMethod */
    12176,  /* nAuxSize */
    0,  /* pArena */
};
