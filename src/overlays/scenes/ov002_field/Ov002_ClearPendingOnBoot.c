/* Clear the scene's pending word at +0xfc, and when the boot request is kind
 * 0x2a in the mode where data_0204be04 is clear, also clear the ov022 entry's
 * own +0xfc through its object at +0x20. -1 means no entry. */
extern void *NNSi_FndGetCurrentRootHeap(void);
extern int LoadGlobalU16At0(void *ctx);
extern int func_ov022_02083f40(void);

extern unsigned char data_0204be04;

void Ov002_ClearPendingOnBoot(void) {
    char *ctx = NNSi_FndGetCurrentRootHeap();

    if (LoadGlobalU16At0(ctx) == 0x2a && data_0204be04 == 0) {
        int entry = func_ov022_02083f40();

        if (entry != -1) {
            *(int *)(*(int *)(entry + 0x20) + 0xfc) = 1;
        }
    }

    *(int *)(ctx + 0xfc) = 0;
}
