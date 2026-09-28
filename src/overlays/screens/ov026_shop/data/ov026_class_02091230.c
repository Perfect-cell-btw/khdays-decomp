#include "game/class_descriptor.h"
/* ov026 class descriptor data_ov026_02091230, 0x02091230-0x02091244 (.data).
 *
 * InstantiateClass (02023930 / 02023960) builds a task object from it: the
 * u16 class / group ids, the constructor whose return is the first state
 * function, the method slot, the size of the zero-filled auxiliary block and
 * the arena reference.  Constructor 0208a848, method 0208aa48, 0xc608-byte state.
 */

extern void Ov026_ShopCreate(void);
extern void Ov026_ClosePanel(void);

GameClassDescriptor data_ov026_02091230 = {
    8,  /* nClassId */
    15,  /* nGroupId */
    Ov026_ShopCreate,  /* pfnCtor */
    Ov026_ClosePanel,  /* pfnMethod */
    50696,  /* nAuxSize */
    0,  /* pArena */
};
