#include "game/class_descriptor.h"
/* ov062 class descriptor data_ov062_020b8000, 0x020b8000-0x020b8014 (.data).
 *
 * InstantiateClass (02023930 / 02023960) builds a task object from it: the
 * u16 class / group ids, the constructor whose return is the first state
 * function, the method slot, the size of the zero-filled auxiliary block and
 * the arena reference.  Constructor 020b5a34, method 020b5a64, 0x332c-byte state.
 */

extern void Ov062_ClassCtor(void);
extern void Ov062_ClassTeardown(void);

GameClassDescriptor data_ov062_020b8000 = {
    10,  /* nClassId */
    6,  /* nGroupId */
    Ov062_ClassCtor,  /* pfnCtor */
    Ov062_ClassTeardown,  /* pfnMethod */
    13100,  /* nAuxSize */
    0,  /* pArena */
};
