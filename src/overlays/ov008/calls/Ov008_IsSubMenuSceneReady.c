extern int Game_PollSceneAlive(void);
int Ov008_IsSubMenuSceneReady(void)
{
    return Game_PollSceneAlive() == 1;
}
