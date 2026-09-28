#include "game/class_descriptor.h"
/* ov045 class descriptor data_ov045_020b4b80, 0x020b4b80-0x020b4b94 (.data).
 *
 * InstantiateClass (02023930 / 02023960) builds a task object from it: the
 * u16 class / group ids, the constructor whose return is the first state
 * function, the method slot, the size of the zero-filled auxiliary block and
 * the arena reference.  Constructor 020b3234, method 020b325c, 0x3074-byte state.
 */

extern void Ov045_InitAndReturnNextState(void);
extern void Ov045_stateDtorCleanup(void);

GameClassDescriptor data_ov045_020b4b80 = {
    10,  /* nClassId */
    6,  /* nGroupId */
    Ov045_InitAndReturnNextState,  /* pfnCtor */
    Ov045_stateDtorCleanup,  /* pfnMethod */
    12404,  /* nAuxSize */
    0,  /* pArena */
};
