/* Ov107_TaskRestartWith5f0 -- restart the task: reset it (Ov107_TaskReset), install
 * Ov107_DefaultStepDone as its step function and re-arm it. */

#include "game/enemy_common.h"

void Ov107_TaskRestartWith5f0(int obj) {
    Ov107_TaskReset(obj);
    *(void **)(obj + 4) = (void *)Ov107_DefaultStepDone;
    Ov107_OrLowFlags(obj, 1);
}
