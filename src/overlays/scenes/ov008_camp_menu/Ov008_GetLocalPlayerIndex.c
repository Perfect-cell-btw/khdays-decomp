/* Returns the local player's index in the session. */

extern int Session_GetLocalPlayerIndex(void);

int Ov008_GetLocalPlayerIndex(void)
{
    return (unsigned short)Session_GetLocalPlayerIndex();
}
