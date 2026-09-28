#include "game/class_descriptor.h"
/* ov046 class descriptor data_ov046_020b4aa0, 0x020b4aa0-0x020b4ab4 (.data).
 *
 * InstantiateClass (02023930 / 02023960) builds a task object from it: the
 * u16 class / group ids, the constructor whose return is the first state
 * function, the method slot, the size of the zero-filled auxiliary block and
 * the arena reference.  Constructor 020b3234, method 020b325c, 0x34b0-byte state.
 */

extern void Ov046_stateCtorReturnHandler(void);
extern void Ov046_stateDtorCleanup(void);

GameClassDescriptor data_ov046_020b4aa0 = {
    10,  /* nClassId */
    6,  /* nGroupId */
    Ov046_stateCtorReturnHandler,  /* pfnCtor */
    Ov046_stateDtorCleanup,  /* pfnMethod */
    13488,  /* nAuxSize */
    0,  /* pArena */
};
