/* Replace the UTF-16 string cached at +0xb4 of the ov002 context: free the old
 * one, and when a new string is given duplicate it into a fresh heap block of
 * (length + 1) * 2 bytes. Either way tell Ov002_AppendEntry to re-run the
 * Ov002_DrawLoadedCaption pass over data_ov002_0207ed58. */
extern int data_ov002_0207f62c;
extern int data_ov002_0207ed58;

extern void NNSi_FndFreeFromDefaultHeap(void *p);
extern void *NNSi_FndAllocFromDefaultExpHeap(unsigned int size);
extern int Wcslen(unsigned short *s);
extern unsigned short *StrCopy16(unsigned short *dst, unsigned short *src);
extern void Ov002_DrawLoadedCaption(void);
extern void Ov002_AppendEntry(void *a, void *b, int c);

void Ov002_SetCachedString(unsigned short *s) {
    char *ctx = (char *)(&data_ov002_0207f62c)[1];
    void *cur = *(void **)(ctx + 0xb4);

    if (cur != 0) {
        if (cur != 0) {
            NNSi_FndFreeFromDefaultHeap(cur);
            *(void **)(ctx + 0xb4) = 0;
        }
    }

    if (s != 0) {
        *(void **)(ctx + 0xb4) =
            NNSi_FndAllocFromDefaultExpHeap((Wcslen(s) + 1) * 2);
        StrCopy16(*(unsigned short **)(ctx + 0xb4), s);
    }

    Ov002_AppendEntry(&data_ov002_0207ed58, (void *)&Ov002_DrawLoadedCaption, 0);
}
