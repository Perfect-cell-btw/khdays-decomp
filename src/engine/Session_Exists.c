/* True when the GameSession singleton pointer (data_0204c228) is non-null. Session_Destroy clears
 * that pointer. */

extern int data_0204c228;

int Session_Exists(void) {
    return *(int *)&data_0204c228 != 0;
}
