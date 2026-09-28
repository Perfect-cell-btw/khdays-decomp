extern int Slot_UnlinkIfLinked();
extern int NNS_FndRemoveListObject();
extern int NNSi_FndFreeFromDefaultHeap();

void Ov000_DestroyObject(char *a, int *b)
{
    int i;
    int *p;
    int v;

    if (*(int *)(a + 0x4a70) == (int)b) {
        *(int *)(a + 0x4a70) = 0;
    }

    p = b;
    for (i = 0; i < 2; i++) {
        v = p[5];
        if (v != -1) {
            Slot_UnlinkIfLinked(a, v);
        }
        p++;
    }

    NNS_FndRemoveListObject(a + 0x4a38, b);

    if (b != 0) {
        NNSi_FndFreeFromDefaultHeap();
    }
}
