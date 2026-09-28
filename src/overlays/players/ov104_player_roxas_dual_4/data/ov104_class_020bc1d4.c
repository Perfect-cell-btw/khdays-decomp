#include "game/class_descriptor.h"
/* ov104 class descriptor data_ov104_020bc1d4, 0x020bc1d4-0x020bc1e8 (.data).
 *
 * InstantiateClass (02023930 / 02023960) builds a task object from it: the
 * u16 class / group ids, the constructor whose return is the first state
 * function, the method slot, the size of the zero-filled auxiliary block and
 * the arena reference.  Constructor 020ba7d4, method 020ba83c, 0x2f88-byte state.
 */

extern void Ov104_ClassCtor(void);
extern void Ov104_ClassTeardown(void);

GameClassDescriptor data_ov104_020bc1d4 = {
    10,  /* nClassId */
    6,  /* nGroupId */
    Ov104_ClassCtor,  /* pfnCtor */
    Ov104_ClassTeardown,  /* pfnMethod */
    12168,  /* nAuxSize */
    0,  /* pArena */
};
