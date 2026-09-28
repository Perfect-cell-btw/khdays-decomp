extern int Game_PollSceneAlive(void);
int Ov006_IsSceneState4(void)
{
    return Game_PollSceneAlive() == 4;
}
