/* Whether the game scene state is 0. */

extern int Game_PollSceneAlive(void);
int Ov008_IsSceneState0(void)
{
    return Game_PollSceneAlive() == 0;
}
