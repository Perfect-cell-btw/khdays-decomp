/* Clear the two 0x1c-byte blocks at +0x200 and +0x240 of request kind 9's
 * object, then close the request. */
extern char *Ov002_GetItemResource(int kind);
extern void MIi_CpuClear16(int value, void *dst, int size);
extern void Ov002_SelectEntry(int kind);

void Ov002_ClearRequest9Blocks(void) {
    char *obj = Ov002_GetItemResource(9);

    MIi_CpuClear16(0, obj + 0x200, 0x1c);
    MIi_CpuClear16(0, obj + 0x240, 0x1c);
    Ov002_SelectEntry(9);
}
