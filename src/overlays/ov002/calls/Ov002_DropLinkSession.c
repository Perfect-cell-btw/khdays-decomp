extern void StoreGlobalByteAt0(int arg);
extern char *data_ov002_0207fa00;
/* Drop the link session: cancel it, clear the state byte and the id halfword, and mark the slot
 * free (-1). */
void Ov002_DropLinkSession(void) {
    char *e = (char *)((int)data_ov002_0207fa00 + 0x8d0c);
    StoreGlobalByteAt0(-1);
    e[0] = 0;
    *(unsigned short *)(e + 2) = 0;
    e[1] = -1;
}
