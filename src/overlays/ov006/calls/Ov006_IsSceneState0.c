extern int Game_PollSceneAlive(void);
int Ov006_IsSceneState0(void)
{
    return Game_PollSceneAlive() == 0;
}
