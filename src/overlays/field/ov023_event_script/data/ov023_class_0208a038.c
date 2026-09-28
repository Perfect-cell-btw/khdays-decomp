#include "game/class_descriptor.h"
/* ov023 class descriptor data_ov023_0208a038, 0x0208a038-0x0208a04c (.data).
 *
 * InstantiateClass (02023930 / 02023960) builds a task object from it: the
 * u16 class / group ids, the constructor whose return is the first state
 * function, the method slot, the size of the zero-filled auxiliary block and
 * the arena reference.  Constructor 02082d20, method 02082ff8, 0x875ec-byte state.
 */

extern void Ov023_SceneInit(void);
extern void Ov023_SceneDestroy(void);

GameClassDescriptor data_ov023_0208a038 = {
    0,  /* nClassId */
    13,  /* nGroupId */
    Ov023_SceneInit,  /* pfnCtor */
    Ov023_SceneDestroy,  /* pfnMethod */
    554476,  /* nAuxSize */
    0,  /* pArena */
};
