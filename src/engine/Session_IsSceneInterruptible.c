/* True when Session_IsActive reports ready and the mode Game_PollSceneAlive returns is one of
 * 0, 1, 9 or 10.  The membership test is a switch -- an if-chain gives a different
 * compare tree. */

#include "game/engine.h"

int Session_IsSceneInterruptible(void) {
    int r = 0;
    if (Session_IsActive() == 0) {
        return r;
    }
    switch (Game_PollSceneAlive()) {
    case 0:
    case 1:
    case 9:
    case 10:
        r = 1;
        break;
    }
    return r;
}
