/* Initialises the context entry of the current root heap owner; returns 0. */

extern int *NNSi_FndGetCurrentRootHeap(void);
extern void InitContextEntryOnce(int);

int ContextEntry_InitForRootHeap(void) {
    InitContextEntryOnce(*NNSi_FndGetCurrentRootHeap());
    return 0;
}
