/* Tests the scene state returned by Game_PollSceneAlive. */

#include "game/engine.h"

int Ov008_IsSubMenuSceneReady(void)
{
    return Game_PollSceneAlive() == 1;
}
