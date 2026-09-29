/* Ov008_ReleaseMenuUi -- release the loaded menu UI container, ov008.
 * If the UI container is loaded (heap+0x608), detaches its root cell from the object manager
 * (Obj_Release on heap+0x60c), frees the container (ZeroHalfThenFree), and clears both the
 * container slot (heap+0x608) and the root-cell handle (heap+0x5044). */

#include "game/engine.h"

extern char *data_ov008_02090f00;

void Ov008_ReleaseMenuUi(void) {
    if (*(int *)(data_ov008_02090f00 + 0x608) == 0) {
        return;
    }
    Obj_Release((int *)(data_ov008_02090f00 + 0x60c));
    ZeroHalfThenFree(*(void **)(data_ov008_02090f00 + 0x608));
    *(int *)(data_ov008_02090f00 + 0x608) = 0;
    *(int *)(data_ov008_02090f00 + 0x5044) = 0;
}
