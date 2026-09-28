#include "game/class_descriptor.h"
/* ov077 class descriptor data_ov077_020b9ab4, 0x020b9ab4-0x020b9ac8 (.data).
 *
 * InstantiateClass (02023930 / 02023960) builds a task object from it: the
 * u16 class / group ids, the constructor whose return is the first state
 * function, the method slot, the size of the zero-filled auxiliary block and
 * the arena reference.  Constructor 020b8114, method 020b813c, 0x3180-byte state.
 */

extern void Ov077_InitAndReturnNextState(void);
extern void Ov077_setupTriple(void);

GameClassDescriptor data_ov077_020b9ab4 = {
    10,  /* nClassId */
    6,  /* nGroupId */
    Ov077_InitAndReturnNextState,  /* pfnCtor */
    Ov077_setupTriple,  /* pfnMethod */
    12672,  /* nAuxSize */
    0,  /* pArena */
};
