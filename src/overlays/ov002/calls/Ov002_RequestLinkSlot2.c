/* Request link slot 2 for the given id and, when the link layer hands back
 * anything other than the unassigned marker 0xffff, mark the session dirty
 * (flag 8 in the halfword at +0, bit 0 of the byte at +0xa). Reports 1 unless
 * the request came back unassigned. A session that is not ready reports 1
 * without asking. */
extern int Session_IsReady(void);
extern int Ov002_BuildSessionCommand(int slot, void *request);

extern char *data_ov002_0207fa04;

int Ov002_RequestLinkSlot2(int id) {
    char *ctx = data_ov002_0207fa04;
    int request[2];

    if (Session_IsReady() != 0) {
        request[1] = id;

        if (Ov002_BuildSessionCommand(2, request) == 0xffff) {
            return 0;
        }

        *(unsigned short *)ctx |= 8;
        *(unsigned char *)(ctx + 0xa) |= 1;
    }

    return 1;
}
