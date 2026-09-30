#include "game/class_descriptor.h"
/* ov042 class descriptor gOv042VexenClass, 0x020b4740-0x020b4754 (.data).
 *
 * InstantiateClass (02023930 / 02023960) builds a task object from it: the
 * u16 class / group ids, the constructor whose return is the first state
 * function, the method slot, the size of the zero-filled auxiliary block and
 * the arena reference.  Constructor 020b3234, method 020b325c, 0x3490-byte state.
 */

extern void Ov042_stateCtorReturnHandler(void);
extern void Ov042_setupTriple(void);

GameClassDescriptor gOv042VexenClass = {
    10,  /* nClassId */
    6,  /* nGroupId */
    Ov042_stateCtorReturnHandler,  /* pfnCtor */
    Ov042_setupTriple,  /* pfnMethod */
    13456,  /* nAuxSize */
    0,  /* pArena */
};
