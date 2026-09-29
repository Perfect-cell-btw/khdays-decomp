/* Whether the game scene state is 4. */

#include "game/engine.h"

int Ov006_IsSceneState4(void)
{
    return Game_PollSceneAlive() == 4;
}
