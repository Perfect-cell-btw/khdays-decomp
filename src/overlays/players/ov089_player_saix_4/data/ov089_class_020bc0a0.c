#include "game/class_descriptor.h"
/* ov089 class descriptor data_ov089_020bc0a0, 0x020bc0a0-0x020bc0b4 (.data).
 *
 * InstantiateClass (02023930 / 02023960) builds a task object from it: the
 * u16 class / group ids, the constructor whose return is the first state
 * function, the method slot, the size of the zero-filled auxiliary block and
 * the arena reference.  Constructor 020ba7d4, method 020ba7fc, 0x33a4-byte state.
 */

extern void Ov089_ClassCtor(void);
extern void Ov089_ClassTeardown(void);

GameClassDescriptor data_ov089_020bc0a0 = {
    10,  /* nClassId */
    6,  /* nGroupId */
    Ov089_ClassCtor,  /* pfnCtor */
    Ov089_ClassTeardown,  /* pfnMethod */
    13220,  /* nAuxSize */
    0,  /* pArena */
};
