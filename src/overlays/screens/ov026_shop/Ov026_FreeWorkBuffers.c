/* Frees and clears the four buffers at +0x3c..+0x48. */

extern void NNSi_FndFreeFromDefaultHeap(void *block);

struct S {
    char pad[0x3c];
    int f3c;
    int f40;
    int f44;
    int f48;
};

void Ov026_FreeWorkBuffers(struct S *p)
{
    if (p->f3c) {
        NNSi_FndFreeFromDefaultHeap((void *)p->f3c);
        p->f3c = 0;
    }
    if (p->f40) {
        NNSi_FndFreeFromDefaultHeap((void *)p->f40);
        p->f40 = 0;
    }
    if (p->f44) {
        NNSi_FndFreeFromDefaultHeap((void *)p->f44);
        p->f44 = 0;
    }
    if (p->f48) {
        NNSi_FndFreeFromDefaultHeap((void *)p->f48);
        p->f48 = 0;
    }
}
