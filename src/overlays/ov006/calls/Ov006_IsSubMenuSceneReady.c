extern int Game_PollSceneAlive(void);
int Ov006_IsSubMenuSceneReady(void)
{
    return Game_PollSceneAlive() == 1;
}
