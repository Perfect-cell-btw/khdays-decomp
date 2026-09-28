/* Advance a pending request: a live request (+0) is dropped once the owner's +0x6bc counter
 * reaches 0x30; while it reads exactly 1 both halves (+4 and +0x10c) are stepped. */
extern unsigned short Sequence_UpdateTracks(void *arg0, int arg1);
void Ov043_AdvanceRequest(char *owner, int *req, int arg) {
    if (*req != 0 && *(int *)(owner + 0x6bc) != 0x30) {
        *req = 0;
    }
    if (*req != 1) return;
    Sequence_UpdateTracks((char *)req + 4, arg);
    Sequence_UpdateTracks((char *)req + 0x10c, arg);
}
