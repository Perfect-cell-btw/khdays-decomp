/* Registers the texture data of the model's resource (+0x74). */

extern int ForwardType7RecordSpan();

int func_0202a684(int arg0) {
    int p = *(int *)(arg0 + 0x74);
    return ForwardType7RecordSpan(*(int *)(p + 0xc), *(int *)(p + 8), *(unsigned short *)(p + 6));
}
