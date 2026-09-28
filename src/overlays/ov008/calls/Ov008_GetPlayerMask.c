extern int Ov008_Link_IsLocal(void);
extern int Session_PackConnectedPlayerMask(void);
int Ov008_GetPlayerMask(void)
{
    if (Ov008_Link_IsLocal() != 0) {
        return 1;
    }
    return Session_PackConnectedPlayerMask();
}
