#include "game/class_descriptor.h"
/* ov033 class descriptor data_ov033_020b4b00, 0x020b4b00-0x020b4b14 (.data).
 *
 * InstantiateClass (02023930 / 02023960) builds a task object from it: the
 * u16 class / group ids, the constructor whose return is the first state
 * function, the method slot, the size of the zero-filled auxiliary block and
 * the arena reference.  Constructor 020b3234, method 020b325c, 0x33a4-byte state.
 */

extern void Ov033_ClassCtor(void);
extern void Ov033_ClassTeardown(void);

GameClassDescriptor data_ov033_020b4b00 = {
    10,  /* nClassId */
    6,  /* nGroupId */
    Ov033_ClassCtor,  /* pfnCtor */
    Ov033_ClassTeardown,  /* pfnMethod */
    13220,  /* nAuxSize */
    0,  /* pArena */
};
