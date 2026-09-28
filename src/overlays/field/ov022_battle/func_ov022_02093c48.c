/* Queues a command in a free or cancelled slot: records its kind, id and value, resets its
 * animation group, and marks it pending. */

extern int Ov022_KindToGroup(int arg0);
extern void Ov022_ResetSlotTracks(int arg0, int arg1);

void func_ov022_02093c48(int arg0, int arg1, int arg2, int arg3) {
    if (*(unsigned char *)(arg0 + 1) != 0 && *(unsigned char *)(arg0 + 1) != 4) return;
    *(short *)(arg0 + 0x10) = (short)arg1;
    *(int *)(arg0 + 0x14) = arg2;
    *(int *)(arg0 + 0x18) = arg3;
    *(int *)(arg0 + 0x4d0) = 0;
    if (*(int *)(arg0 + 0x14) != 0xd && 2 <= arg1 && arg1 < 0xc) {
        Ov022_ResetSlotTracks(arg0, Ov022_KindToGroup((int)*(short *)(arg0 + 0x10)));
    }
    *(unsigned char *)(arg0 + 1) = 1;
}
