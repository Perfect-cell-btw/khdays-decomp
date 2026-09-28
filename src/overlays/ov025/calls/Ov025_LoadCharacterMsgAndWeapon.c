/* Builds the resource path into a 0x80-byte stack buffer, opens it (mode 0xe), stores the
 * handle at +0x1b4 and hands the sub-object at +0x4d4 to Ov002_LoadCharacterWeapon. */
extern void OS_SPrintf(char *dst, const char *fmt, const char *arg);
extern int Msg_OpenContainerAndReadHeader(char *path, int a);
extern void Ov002_LoadCharacterWeapon(char *p, int a, int b);
extern char data_ov025_020b4c50[];
extern char data_ov025_020b4c60[];

void Ov025_LoadCharacterMsgAndWeapon(char *self, int a, int b) {
    char buf[0x80];
    OS_SPrintf(buf, data_ov025_020b4c50, data_ov025_020b4c60);
    *(int *)(self + 0x1b4) = Msg_OpenContainerAndReadHeader(buf, 0xe);
    Ov002_LoadCharacterWeapon(self + 0xd4 + 0x400, a, b);
}
