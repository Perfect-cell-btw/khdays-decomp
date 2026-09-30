#include "game/class_descriptor.h"
/* ov041 class descriptor gOv041RikuClass, 0x020b4c60-0x020b4c74 (.data).
 *
 * InstantiateClass (02023930 / 02023960) builds a task object from it: the
 * u16 class / group ids, the constructor whose return is the first state
 * function, the method slot, the size of the zero-filled auxiliary block and
 * the arena reference.  Constructor 020b3234, method 020b325c, 0x32ec-byte state.
 */

extern void Ov041_stateCtorReturnHandler(void);
extern void Ov041_stateDtorCleanup(void);

GameClassDescriptor gOv041RikuClass = {
    10,  /* nClassId */
    6,  /* nGroupId */
    Ov041_stateCtorReturnHandler,  /* pfnCtor */
    Ov041_stateDtorCleanup,  /* pfnMethod */
    13036,  /* nAuxSize */
    0,  /* pArena */
};
