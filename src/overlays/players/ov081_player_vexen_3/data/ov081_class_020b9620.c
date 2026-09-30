#include "game/class_descriptor.h"
/* ov081 class descriptor gOv081VexenClass, 0x020b9620-0x020b9634 (.data).
 *
 * InstantiateClass (02023930 / 02023960) builds a task object from it: the
 * u16 class / group ids, the constructor whose return is the first state
 * function, the method slot, the size of the zero-filled auxiliary block and
 * the arena reference.  Constructor 020b8114, method 020b813c, 0x3490-byte state.
 */

extern void Ov081_stateCtorReturnHandler(void);
extern void Ov081_setupTriple(void);

GameClassDescriptor gOv081VexenClass = {
    10,  /* nClassId */
    6,  /* nGroupId */
    Ov081_stateCtorReturnHandler,  /* pfnCtor */
    Ov081_setupTriple,  /* pfnMethod */
    13456,  /* nAuxSize */
    0,  /* pArena */
};
