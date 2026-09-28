/* Return the signed byte at +0xc of the ov002 context (data_ov002_0207fa10). */

extern int data_ov002_0207fa10;

signed char Ov002_GetCtxModeByte(void) {
    return *(signed char *)(*(int *)&data_ov002_0207fa10 + 0xc);
}
