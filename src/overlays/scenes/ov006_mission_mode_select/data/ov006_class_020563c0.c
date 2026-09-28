#include "game/class_descriptor.h"
/* ov006 class descriptor data_ov006_020563c0, 0x020563c0-0x020563d4 (.data).
 *
 * InstantiateClass (02023930 / 02023960) builds a task object from it: the
 * u16 class / group ids, the constructor whose return is the first state
 * function, the method slot, the size of the zero-filled auxiliary block and
 * the arena reference.  Constructor 0204e1ec, method 0204e3a8, 0x4f4-byte state.
 */

extern void Ov006_MissionCreateContext(void);
extern void Ov006_FireExitMessage(void);

GameClassDescriptor data_ov006_020563c0 = {
    8,  /* nClassId */
    14,  /* nGroupId */
    Ov006_MissionCreateContext,  /* pfnCtor */
    Ov006_FireExitMessage,  /* pfnMethod */
    1268,  /* nAuxSize */
    0,  /* pArena */
};
