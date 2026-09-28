/* Heap copy of a wide string; optionally reports the source end. */

extern int Wcslen();
extern int StrCopy16();
extern int NNSi_FndAllocFromDefaultExpHeap();

int Ov026_DupWideString(int *a, char *b) {
    char *p;
    int n;

    n = (Wcslen(b) + 1) * 2;
    p = (char *)NNSi_FndAllocFromDefaultExpHeap(n);
    StrCopy16(p, b);
    if (a) {
        *a = (int)(b + n);
    }
    return (int)p;
}
