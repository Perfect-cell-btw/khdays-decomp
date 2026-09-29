/* Ov006_CanAdvancePastIntro -- test whether the Mission Mode may advance past the intro, ov006.
 * Returns true immediately if the global gate Session_IsSceneInterruptible is engaged; otherwise returns
 * whether the Mission Mode's ready check Ov006_ShouldEnterConfirmState is non-zero. */

#include "game/engine.h"

extern int Ov006_ShouldEnterConfirmState(void);

int Ov006_CanAdvancePastIntro(void) {
    if (Session_IsSceneInterruptible() != 0) {
        return 1;
    }
    return Ov006_ShouldEnterConfirmState() != 0;
}
