extern int Ov008_IsSceneState0(void);
int Ov008_WaitSceneState0(void)
{
    return Ov008_IsSceneState0() ? -2 : 0;
}
