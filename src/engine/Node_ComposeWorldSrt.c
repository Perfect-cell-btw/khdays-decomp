/* Composes the node's world transform: the parent's world SRT combined with the node's local SRT,
 * or the local SRT for a root node; skipped when the node is frozen. */

extern void Srt_Concat(void *dst, void *src, void *arg);

typedef struct {
    int word0;
    int word4;
    int word8;
    int wordc;
    int word10;
    int word14;
    int word18;
    int word1c;
    int word20;
    int word24;
    int word28;
} func_0203c904_block;

void Node_ComposeWorldSrt(int *ptr) {
    if ((ptr[0x5c / 4] << 31) >> 31) {
        return;
    }

    if (ptr[0] != 0) {
        Srt_Concat(ptr + 0x30 / 4, (char *)ptr[0] + 0x30, ptr + 1);
        return;
    }

    *(func_0203c904_block *)(ptr + 0x30 / 4) = *(func_0203c904_block *)(ptr + 1);
}
