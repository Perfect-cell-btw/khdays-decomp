/* True while a session is open: the root pointer is set and the handle in seat row zero is not -1.
 * Twelve callers across ov002 use it as the gate on anything session-shaped. Note what that means
 * for the roster: row zero's pInstance is the session handle, not a per-seat object.
 * Ov002_GetLocalPlayerGroup reads the same word for the same purpose. */

extern int data_ov002_0207fa00;

int Ov002_IsSessionOpen(void) {
    int p = *(int *)&data_ov002_0207fa00;
    if (p == 0) {
        return 0;
    }
    return *(int *)(p + 0x8bcc) != -1;
}
