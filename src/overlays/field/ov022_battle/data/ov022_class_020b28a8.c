#include "game/class_descriptor.h"
/* ov022 class descriptor data_ov022_020b28a8, 0x020b28a8-0x020b28bc (.data).
 *
 * InstantiateClass (02023930 / 02023960) builds a task object from it: the
 * u16 class / group ids, the constructor whose return is the first state
 * function, the method slot, the size of the zero-filled auxiliary block and
 * the arena reference.  Constructor 02082acc, method 02082bb0, 0x40-byte state.
 */

extern void Ov022_BeginSceneWithRoster(void);
extern void Ov022_ShutDownLink(void);

GameClassDescriptor data_ov022_020b28a8 = {
    8,  /* nClassId */
    15,  /* nGroupId */
    Ov022_BeginSceneWithRoster,  /* pfnCtor */
    Ov022_ShutDownLink,  /* pfnMethod */
    64,  /* nAuxSize */
    0,  /* pArena */
};
