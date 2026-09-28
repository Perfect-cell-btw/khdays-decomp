#include "game/class_descriptor.h"
/* ov040 class descriptor data_ov040_020b4a74, 0x020b4a74-0x020b4a88 (.data).
 *
 * InstantiateClass (02023930 / 02023960) builds a task object from it: the
 * u16 class / group ids, the constructor whose return is the first state
 * function, the method slot, the size of the zero-filled auxiliary block and
 * the arena reference.  Constructor 020b3234, method 020b325c, 0x2f90-byte state.
 */

extern void Ov040_stateCtorReturnHandler(void);
extern void Ov040_setupTriple(void);

GameClassDescriptor data_ov040_020b4a74 = {
    10,  /* nClassId */
    6,  /* nGroupId */
    Ov040_stateCtorReturnHandler,  /* pfnCtor */
    Ov040_setupTriple,  /* pfnMethod */
    12176,  /* nAuxSize */
    0,  /* pArena */
};
