extern int Game_PollSceneAlive(void);
int Ov008_IsSceneState4(void)
{
    return Game_PollSceneAlive() == 4;
}
