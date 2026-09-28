/* Request link slot 3 for this machine's own player index and, when the link
 * layer hands back anything other than the unassigned marker 0xffff, mark the
 * session dirty (flag 8 in the halfword at +0). Reports 1 unless the request
 * came back unassigned. Sibling of Ov002_RequestLinkSlot2 over slot 2. */
extern int Session_GetLocalPlayerIndex(void);
extern int Ov002_BuildSessionCommand(int slot, void *request);

extern char *data_ov002_0207fa04;

int Ov002_RequestLinkSlot3(void) {
    char *ctx = data_ov002_0207fa04;
    unsigned char request[4];

    request[1] = (unsigned char)Session_GetLocalPlayerIndex();

    if (Ov002_BuildSessionCommand(3, request) == 0xffff) {
        return 0;
    }

    *(unsigned short *)ctx |= 8;
    return 1;
}
