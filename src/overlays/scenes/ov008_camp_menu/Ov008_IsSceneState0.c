/* Whether the game scene state is 0. */

#include "game/engine.h"

int Ov008_IsSceneState0(void)
{
    return Game_PollSceneAlive() == 0;
}
