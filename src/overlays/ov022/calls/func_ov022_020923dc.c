extern int Ov022_GetHi6BitsOfByteVia0x20(int arg0);
extern int Ov022_IsIndexedRecordByteZero(unsigned int arg0, int arg1);

int func_ov022_020923dc(int arg0, int arg1) {
    int ret = 1;
    int e = *(int *)(arg0 + arg1 * 4);
    int i;
    int n;
    if (e != 0) {
        n = Ov022_GetHi6BitsOfByteVia0x20(e);
        i = 0;
        if (0 < n) {
            do {
                if (Ov022_IsIndexedRecordByteZero(*(unsigned int *)(arg0 + arg1 * 4), i) == 0) {
                    ret = 0;
                    break;
                }
                i = i + 1;
            } while (i < n);
        }
    }
    return ret;
}
