#include "game/class_descriptor.h"
/* ov075 class descriptor data_ov075_020b9d20, 0x020b9d20-0x020b9d34 (.data).
 *
 * InstantiateClass (02023930 / 02023960) builds a task object from it: the
 * u16 class / group ids, the constructor whose return is the first state
 * function, the method slot, the size of the zero-filled auxiliary block and
 * the arena reference.  Constructor 020b8114, method 020b8148, 0x30c0-byte state.
 */

extern void Ov075_stateCtorMultiInitReturnHandler(void);
extern void Ov075_stateDtorCleanupMulti(void);

GameClassDescriptor data_ov075_020b9d20 = {
    10,  /* nClassId */
    6,  /* nGroupId */
    Ov075_stateCtorMultiInitReturnHandler,  /* pfnCtor */
    Ov075_stateDtorCleanupMulti,  /* pfnMethod */
    12480,  /* nAuxSize */
    0,  /* pArena */
};
