#include "game/class_descriptor.h"
/* ov023 class descriptor data_ov023_0208a004, 0x0208a004-0x0208a018 (.data).
 *
 * InstantiateClass (02023930 / 02023960) builds a task object from it: the
 * u16 class / group ids, the constructor whose return is the first state
 * function, the method slot, the size of the zero-filled auxiliary block and
 * the arena reference.  Constructor 02082960, method 020829c4, 0x8-byte state.
 */

extern void Ov023_SceneEnter(void);
extern void Ov023_SceneLeave(void);

GameClassDescriptor data_ov023_0208a004 = {
    8,  /* nClassId */
    13,  /* nGroupId */
    Ov023_SceneEnter,  /* pfnCtor */
    Ov023_SceneLeave,  /* pfnMethod */
    8,  /* nAuxSize */
    0,  /* pArena */
};
