/* Checks whether a tutorial topic's unlock flag is set. Returns whether the topic's flag is set. */

#include "game/engine.h"

extern int Ov025_GetSlideTableValue();

int Ov025_Tutorial_IsTopicUnlocked(int arg0) {
    return GameState_IsFlagSet(Ov025_GetSlideTableValue(arg0) + 0x3c2b);
}
