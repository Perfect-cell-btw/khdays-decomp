/* Whether the session was ready when the main menu was built: Ov008_MainMenuInit stores
 * Session_IsReady in the menu context's first word. 0 without a menu context. */

extern int *data_ov008_02090f00;
int Ov008_IsSessionReady(void)
{
    if (data_ov008_02090f00 != 0) {
        return data_ov008_02090f00[0];
    }
    return 0;
}
