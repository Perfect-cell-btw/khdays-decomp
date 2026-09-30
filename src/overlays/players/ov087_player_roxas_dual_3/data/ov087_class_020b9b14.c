#include "game/class_descriptor.h"
/* ov087 class descriptor gOv087RoxasDualClass, 0x020b9b14-0x020b9b28 (.data).
 *
 * InstantiateClass (02023930 / 02023960) builds a task object from it: the
 * u16 class / group ids, the constructor whose return is the first state
 * function, the method slot, the size of the zero-filled auxiliary block and
 * the arena reference.  Constructor 020b8114, method 020b817c, 0x2f88-byte state.
 */

extern void Ov087_ClassCtor(void);
extern void Ov087_ClassTeardown(void);

GameClassDescriptor gOv087RoxasDualClass = {
    10,  /* nClassId */
    6,  /* nGroupId */
    Ov087_ClassCtor,  /* pfnCtor */
    Ov087_ClassTeardown,  /* pfnMethod */
    12168,  /* nAuxSize */
    0,  /* pArena */
};
