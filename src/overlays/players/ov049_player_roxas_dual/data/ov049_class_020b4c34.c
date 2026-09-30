#include "game/class_descriptor.h"
/* ov049 class descriptor gOv049RoxasDualClass, 0x020b4c34-0x020b4c48 (.data).
 *
 * InstantiateClass (02023930 / 02023960) builds a task object from it: the
 * u16 class / group ids, the constructor whose return is the first state
 * function, the method slot, the size of the zero-filled auxiliary block and
 * the arena reference.  Constructor 020b3234, method 020b329c, 0x2f88-byte state.
 */

extern void Ov049_ClassCtor(void);
extern void Ov049_ClassTeardown(void);

GameClassDescriptor gOv049RoxasDualClass = {
    10,  /* nClassId */
    6,  /* nGroupId */
    Ov049_ClassCtor,  /* pfnCtor */
    Ov049_ClassTeardown,  /* pfnMethod */
    12168,  /* nAuxSize */
    0,  /* pArena */
};
