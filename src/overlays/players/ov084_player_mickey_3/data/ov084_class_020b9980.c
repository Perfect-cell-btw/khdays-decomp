#include "game/class_descriptor.h"
/* ov084 class descriptor data_ov084_020b9980, 0x020b9980-0x020b9994 (.data).
 *
 * InstantiateClass (02023930 / 02023960) builds a task object from it: the
 * u16 class / group ids, the constructor whose return is the first state
 * function, the method slot, the size of the zero-filled auxiliary block and
 * the arena reference.  Constructor 020b8114, method 020b813c, 0x34b0-byte state.
 */

extern void Ov084_stateCtorReturnHandler(void);
extern void Ov084_stateDtorCleanup(void);

GameClassDescriptor data_ov084_020b9980 = {
    10,  /* nClassId */
    6,  /* nGroupId */
    Ov084_stateCtorReturnHandler,  /* pfnCtor */
    Ov084_stateDtorCleanup,  /* pfnMethod */
    13488,  /* nAuxSize */
    0,  /* pArena */
};
