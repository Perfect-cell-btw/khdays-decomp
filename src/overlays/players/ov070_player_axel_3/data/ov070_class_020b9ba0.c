#include "game/class_descriptor.h"
/* ov070 class descriptor data_ov070_020b9ba0, 0x020b9ba0-0x020b9bb4 (.data).
 *
 * InstantiateClass (02023930 / 02023960) builds a task object from it: the
 * u16 class / group ids, the constructor whose return is the first state
 * function, the method slot, the size of the zero-filled auxiliary block and
 * the arena reference.  Constructor 020b8114, method 020b813c, 0x2f40-byte state.
 */

extern void Ov070_ClassCtor(void);
extern void Ov070_ClassTeardown(void);

GameClassDescriptor data_ov070_020b9ba0 = {
    10,  /* nClassId */
    6,  /* nGroupId */
    Ov070_ClassCtor,  /* pfnCtor */
    Ov070_ClassTeardown,  /* pfnMethod */
    12096,  /* nAuxSize */
    0,  /* pArena */
};
