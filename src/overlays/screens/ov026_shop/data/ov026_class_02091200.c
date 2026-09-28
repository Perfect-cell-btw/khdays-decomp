#include "game/class_descriptor.h"
/* ov026 class descriptor data_ov026_02091200, 0x02091200-0x02091214 (.data).
 *
 * InstantiateClass (02023930 / 02023960) builds a task object from it: the
 * u16 class / group ids, the constructor whose return is the first state
 * function, the method slot, the size of the zero-filled auxiliary block and
 * the arena reference.  Constructor 02082960, method 020829a0, 0xc-byte state.
 */

extern void Ov026_SubScene9_Create(void);
extern void Ov026_ClassTeardown(void);

GameClassDescriptor data_ov026_02091200 = {
    8,  /* nClassId */
    13,  /* nGroupId */
    Ov026_SubScene9_Create,  /* pfnCtor */
    Ov026_ClassTeardown,  /* pfnMethod */
    12,  /* nAuxSize */
    0,  /* pArena */
};
