/* Whether the game scene state is 4. */

extern int Game_PollSceneAlive(void);
int Ov008_IsSceneState4(void)
{
    return Game_PollSceneAlive() == 4;
}
