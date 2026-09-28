/* Post a link message: build it from the result context's leading halfword at
 * root+0x8ba8 with kind 3, stamp the caller's two bytes into the record at
 * root+0x8d6c, send it, and mark the result slot free again (-1). */
extern void Ov002_UpdateHudRecord(int value, int arg, int kind);
extern void strcpy(void *record, void *payload);

extern char *data_ov002_0207fa00;

void Ov002_PostResultLinkMessage(int slot, void *payload, int arg, int flag) {
    char *root = data_ov002_0207fa00;
    char *result = root + 0x8ba8;
    char *record = root + 0x8d6c;

    Ov002_UpdateHudRecord(*(short *)result, arg, 3);
    record[0xc] = (char)slot;
    record[0xd] = (char)flag;
    strcpy(record, payload);
    *(int *)(result + 0xc) = -1;
}
