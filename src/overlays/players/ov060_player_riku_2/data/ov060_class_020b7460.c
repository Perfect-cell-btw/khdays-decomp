#include "game/class_descriptor.h"
/* ov060 class descriptor data_ov060_020b7460, 0x020b7460-0x020b7474 (.data).
 *
 * InstantiateClass (02023930 / 02023960) builds a task object from it: the
 * u16 class / group ids, the constructor whose return is the first state
 * function, the method slot, the size of the zero-filled auxiliary block and
 * the arena reference.  Constructor 020b5a34, method 020b5a5c, 0x32ec-byte state.
 */

extern void Ov060_stateCtorReturnHandler(void);
extern void Ov060_stateDtorCleanup(void);

GameClassDescriptor data_ov060_020b7460 = {
    10,  /* nClassId */
    6,  /* nGroupId */
    Ov060_stateCtorReturnHandler,  /* pfnCtor */
    Ov060_stateDtorCleanup,  /* pfnMethod */
    13036,  /* nAuxSize */
    0,  /* pArena */
};
