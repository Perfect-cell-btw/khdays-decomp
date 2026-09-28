extern int NNS_FndGetNextListObject();
extern void Ov025_RemoveAndFreeItem();

void Ov025_ProcessAllAtField1cc(int arg0) {
    int e = NNS_FndGetNextListObject((void *)(arg0 + 0x1cc), 0);
    if (e == 0) return;
    do {
        int next = NNS_FndGetNextListObject((void *)(arg0 + 0x1cc), e);
        Ov025_RemoveAndFreeItem(arg0, e);
        e = next;
    } while (e != 0);
}
