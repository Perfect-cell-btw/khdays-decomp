/* True when the GameSession singleton (data_0204c228) exists and its dwState is not 1. Used as the
 * outer guard of the periodic session work in Session_CheckSceneLoop, ANDed with Session_IsReady.
 */

extern int *data_0204c228;

int Session_IsActive(void) {
    int *p = data_0204c228;
    if (p != 0 && *p != 1) {
        return 1;
    }
    return 0;
}
