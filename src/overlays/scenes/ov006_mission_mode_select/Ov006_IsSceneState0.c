/* Whether the game scene state is 0. */

#include "game/engine.h"

int Ov006_IsSceneState0(void)
{
    return Game_PollSceneAlive() == 0;
}
