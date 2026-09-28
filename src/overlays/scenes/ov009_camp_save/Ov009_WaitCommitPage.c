/* Ov009_WaitCommitPage -- probe slot 0 readiness, ov009. Returns -2 if Ov009_CommitPage
 * reports the slot busy, else 0. */
extern int Ov009_CommitPage(int slot);
int Ov009_WaitCommitPage(void) {
    int r = 0;
    if (Ov009_CommitPage(0) != 0) {
        r = -2;
    }
    return r;
}
