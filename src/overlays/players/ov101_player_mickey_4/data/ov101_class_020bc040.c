#include "game/class_descriptor.h"
/* ov101 class descriptor data_ov101_020bc040, 0x020bc040-0x020bc054 (.data).
 *
 * InstantiateClass (02023930 / 02023960) builds a task object from it: the
 * u16 class / group ids, the constructor whose return is the first state
 * function, the method slot, the size of the zero-filled auxiliary block and
 * the arena reference.  Constructor 020ba7d4, method 020ba7fc, 0x34b0-byte state.
 */

extern void Ov101_stateCtorReturnHandler(void);
extern void Ov101_stateDtorCleanup(void);

GameClassDescriptor data_ov101_020bc040 = {
    10,  /* nClassId */
    6,  /* nGroupId */
    Ov101_stateCtorReturnHandler,  /* pfnCtor */
    Ov101_stateDtorCleanup,  /* pfnMethod */
    13488,  /* nAuxSize */
    0,  /* pArena */
};
