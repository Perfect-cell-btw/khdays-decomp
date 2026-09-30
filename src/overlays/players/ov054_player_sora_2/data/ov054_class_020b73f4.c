#include "game/class_descriptor.h"
/* ov054 class descriptor gOv054SoraClass, 0x020b73f4-0x020b7408 (.data).
 *
 * InstantiateClass (02023930 / 02023960) builds a task object from it: the
 * u16 class / group ids, the constructor whose return is the first state
 * function, the method slot, the size of the zero-filled auxiliary block and
 * the arena reference.  Constructor 020b5a34, method 020b5a64, 0x2e1c-byte state.
 */

extern void Ov054_stateCtorCondConfigReturnHandler(void);
extern void Ov054_initRegionCondClearGlobal(void);

GameClassDescriptor gOv054SoraClass = {
    10,  /* nClassId */
    6,  /* nGroupId */
    Ov054_stateCtorCondConfigReturnHandler,  /* pfnCtor */
    Ov054_initRegionCondClearGlobal,  /* pfnMethod */
    11804,  /* nAuxSize */
    0,  /* pArena */
};
