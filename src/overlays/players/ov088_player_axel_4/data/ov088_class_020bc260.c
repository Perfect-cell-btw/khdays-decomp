#include "game/class_descriptor.h"
/* ov088 class descriptor data_ov088_020bc260, 0x020bc260-0x020bc274 (.data).
 *
 * InstantiateClass (02023930 / 02023960) builds a task object from it: the
 * u16 class / group ids, the constructor whose return is the first state
 * function, the method slot, the size of the zero-filled auxiliary block and
 * the arena reference.  Constructor 020ba7d4, method 020ba7fc, 0x2f40-byte state.
 */

extern void Ov088_ClassCtor(void);
extern void Ov088_ClassTeardown(void);

GameClassDescriptor data_ov088_020bc260 = {
    10,  /* nClassId */
    6,  /* nGroupId */
    Ov088_ClassCtor,  /* pfnCtor */
    Ov088_ClassTeardown,  /* pfnMethod */
    12096,  /* nAuxSize */
    0,  /* pArena */
};
