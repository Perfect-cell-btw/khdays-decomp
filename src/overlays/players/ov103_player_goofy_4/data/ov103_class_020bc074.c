#include "game/class_descriptor.h"
/* ov103 class descriptor gOv103GoofyClass, 0x020bc074-0x020bc088 (.data).
 *
 * InstantiateClass (02023930 / 02023960) builds a task object from it: the
 * u16 class / group ids, the constructor whose return is the first state
 * function, the method slot, the size of the zero-filled auxiliary block and
 * the arena reference.  Constructor 020ba7d4, method 020ba7fc, 0x2fa0-byte state.
 */

extern void Ov103_stateCtorReturnHandler(void);
extern void Ov103_setupTriple(void);

GameClassDescriptor gOv103GoofyClass = {
    10,  /* nClassId */
    6,  /* nGroupId */
    Ov103_stateCtorReturnHandler,  /* pfnCtor */
    Ov103_setupTriple,  /* pfnMethod */
    12192,  /* nAuxSize */
    0,  /* pArena */
};
