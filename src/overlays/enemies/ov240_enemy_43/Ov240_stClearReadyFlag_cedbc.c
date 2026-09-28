extern void SetIndexedSlot();
void Ov240_stClearReadyFlag_cedbc(int node) {
    int *s = *(int **)(node + 4);
    if (*(unsigned char *)(s[1] + 0xad) != 0) return;
    *(unsigned short *)(*s + 0x1ae) &= ~1;
    *(signed char *)(*s + 0x1c7) = 2;
    SetIndexedSlot(node, *(signed char *)(node + 0x20), 0);
}
