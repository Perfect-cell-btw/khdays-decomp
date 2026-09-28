#include "game/class_descriptor.h"
/* ov094 class descriptor data_ov094_020bc174, 0x020bc174-0x020bc188 (.data).
 *
 * InstantiateClass (02023930 / 02023960) builds a task object from it: the
 * u16 class / group ids, the constructor whose return is the first state
 * function, the method slot, the size of the zero-filled auxiliary block and
 * the arena reference.  Constructor 020ba7d4, method 020ba7fc, 0x3180-byte state.
 */

extern void Ov094_InitAndReturnNextState(void);
extern void Ov094_setupTriple(void);

GameClassDescriptor data_ov094_020bc174 = {
    10,  /* nClassId */
    6,  /* nGroupId */
    Ov094_InitAndReturnNextState,  /* pfnCtor */
    Ov094_setupTriple,  /* pfnMethod */
    12672,  /* nAuxSize */
    0,  /* pArena */
};
