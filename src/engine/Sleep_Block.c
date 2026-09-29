/* Takes a hold on sleep mode (data_0204bda0) so that closing the lid does not put the console to
 * sleep; returns the new count. The save code holds it around save-card access and releases it with
 * Sleep_Unblock. */

extern int data_0204bda0;

int Sleep_Block(void) {
    int v = *(short *)&data_0204bda0 + 1;
    *(short *)&data_0204bda0 = v;
    return v;
}
