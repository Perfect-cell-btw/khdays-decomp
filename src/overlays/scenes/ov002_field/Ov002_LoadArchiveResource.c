extern unsigned int *data_ov002_0207f61c;
extern unsigned int Archive_LoadFile(char *name, int type, int c, int d);
extern void GetResourceSubBlock_CHAR2(unsigned int handle, unsigned int *out);
/* Load archive file `name` as type 0xe, store the handle into the global slot, and resolve its
 * CHAR2 sub-block into slot+8. */
void Ov002_LoadArchiveResource(char *name, int b, int c, int d) {
    unsigned int *dst = data_ov002_0207f61c;
    unsigned int handle = Archive_LoadFile(name, 0xe, c, d);
    *dst = handle;
    GetResourceSubBlock_CHAR2(handle, dst + 2);
}
