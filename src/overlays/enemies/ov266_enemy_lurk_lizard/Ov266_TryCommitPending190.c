/* Hit reaction: when the model has no pending source yet and the hit flags have bits 0 and 4 set,
 * records the source and its position on the model; returns 1 either way unless a source was
 * already pending. */

struct blk3 { int a, b, c; };
int Ov266_TryCommitPending190(char *obj, char *src, int *flags) {
    char *ptrA = *(char **)(obj + 0x214);
    char *ptrB = *(char **)(*(char **)ptrA + 0x384);
    if (*(int *)(ptrB + 0x5b0) != 0) return 0;
    unsigned short f = (unsigned short)*flags;
    if ((f & 1) && (f & 0x10)) {
        char *ptrB2;
        *(int *)(ptrB + 0x5b0) = (int)src;
        ptrB2 = *(char **)(*(char **)ptrA + 0x384);
        *(struct blk3 *)(ptrB2 + 0x5c0) = *(struct blk3 *)(src + 0x190);
        return 1;
    }
    return 1;
}
