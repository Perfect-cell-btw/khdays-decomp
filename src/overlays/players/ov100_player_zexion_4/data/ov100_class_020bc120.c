#include "game/class_descriptor.h"
/* ov100 class descriptor data_ov100_020bc120, 0x020bc120-0x020bc134 (.data).
 *
 * InstantiateClass (02023930 / 02023960) builds a task object from it: the
 * u16 class / group ids, the constructor whose return is the first state
 * function, the method slot, the size of the zero-filled auxiliary block and
 * the arena reference.  Constructor 020ba7d4, method 020ba7fc, 0x3074-byte state.
 */

extern void Ov100_InitAndReturnNextState(void);
extern void Ov100_stateDtorCleanup(void);

GameClassDescriptor data_ov100_020bc120 = {
    10,  /* nClassId */
    6,  /* nGroupId */
    Ov100_InitAndReturnNextState,  /* pfnCtor */
    Ov100_stateDtorCleanup,  /* pfnMethod */
    12404,  /* nAuxSize */
    0,  /* pArena */
};
