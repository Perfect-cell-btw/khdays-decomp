extern int func_ov022_02091228();
extern int NNSi_FndFreeFromDefaultHeap();

struct S {
    char pad[0x2644];
    void *p;
};

void Ov036_ReleaseAndFreeField2644(struct S *a) {
    func_ov022_02091228(a->p);
    NNSi_FndFreeFromDefaultHeap(a->p);
}
