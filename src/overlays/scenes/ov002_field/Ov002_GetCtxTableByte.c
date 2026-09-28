/* Return the signed byte at index `i` of the byte table starting at +0x17 of the ov002 context
 * (data_ov002_0207fa10). */

extern int data_ov002_0207fa10;

int Ov002_GetCtxTableByte(int arg0) {
    return *(signed char *)(*(int *)&data_ov002_0207fa10 + arg0 + 0x17);
}
