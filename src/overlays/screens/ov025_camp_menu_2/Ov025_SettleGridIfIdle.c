/* Query a status word; if it reports idle (0), the object mode at +0x10 is 1 and
 * the flag at +0x19b4 is clear, advance the object via Ov025_SettleGridNodes. */
extern void Ov025_CopySourceBlock(void *out);
extern void Ov025_SettleGridNodes(int obj);

void Ov025_SettleGridIfIdle(int param_1) {
    char local[8];
    Ov025_CopySourceBlock(local);
    if (*(unsigned short *)(local + 4) == 0
        && *(int *)(param_1 + 0x10) == 1
        && *(int *)(param_1 + 0x19b4) == 0) {
        Ov025_SettleGridNodes(param_1);
    }
}
