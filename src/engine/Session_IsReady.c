/* Whether the session's link mode (the first word of the session object, see Session_GetLinkMode)
 * is not 3. Alone the game runs in mode 1, so this holds in single player. It is the inner guard in
 * Session_CheckSceneLoop alongside Session_IsActive. */

extern int *data_0204c228;

int Session_IsReady(void) {
    return *data_0204c228 != 3;
}
