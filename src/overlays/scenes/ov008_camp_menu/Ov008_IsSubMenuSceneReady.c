/* Tests the scene state returned by Game_PollSceneAlive. */

extern int Game_PollSceneAlive(void);
int Ov008_IsSubMenuSceneReady(void)
{
    return Game_PollSceneAlive() == 1;
}
