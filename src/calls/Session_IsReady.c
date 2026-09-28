/* True when the GameSession singleton's dwState is not 3. Proven content is the comparison against
 * 3; the "ready" reading comes from its role as the inner guard in Session_CheckSceneLoop alongside
 * Session_IsActive. */

extern int *data_0204c228;

int Session_IsReady(void) {
    return *data_0204c228 != 3;
}
