/* Scene callback: returns the idle callback when the session is alive, finalises the wireless
 * session on an error state, and returns nothing otherwise. */

#include "game/engine.h"

typedef void (*SceneCallback)(void);

extern void Ov105_WH_Finalize(void);
extern void Ov008_MissionSceneIdleCallback(void);

SceneCallback Ov008_MissionSelectSceneCallback(void) {
    SceneCallback callback = 0;

    switch (Game_PollSceneAlive()) {
    case 0:
    case 3:
        break;
    case 1:
        callback = Ov008_MissionSceneIdleCallback;
        break;
    default:
        Ov105_WH_Finalize();
        break;
    }

    return callback;
}
