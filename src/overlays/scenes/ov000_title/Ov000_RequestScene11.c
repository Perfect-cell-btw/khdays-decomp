/* Tail-call Scene_RequestPending with fixed args (0xb, 0). */

#include "game/scene.h"
extern int Scene_RequestPending(int a, int b);
int Ov000_RequestScene11(void) {
    return Scene_RequestPending(SCENE_OPENING, 0);
}
