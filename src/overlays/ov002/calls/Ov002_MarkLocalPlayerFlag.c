/* Sets the flag of the local player's record. */

extern int Session_GetLocalPlayerIndex();
extern int data_ov002_0207f9b0;

void Ov002_MarkLocalPlayerFlag(int arg0) {
    int r = Session_GetLocalPlayerIndex(arg0);
    *(unsigned short *)((char *)&data_ov002_0207f9b0 + r * 0x14) = 1;
}
