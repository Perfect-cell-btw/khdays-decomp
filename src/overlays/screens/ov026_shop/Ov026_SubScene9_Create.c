extern char *NNSi_FndGetCurrentRootHeap(void);
extern int InstantiateClass(void *desc, int arg);
extern char *data_ov026_02091360;
extern char data_ov026_02091230;
extern void Ov026_ConsumeHeapFlag3Handler(void);

/* Allocates the sub-scene block off the root heap, builds its resource set and enters state 9. */
void *Ov026_SubScene9_Create(void) {
    char *st = NNSi_FndGetCurrentRootHeap();
    *(char **)&data_ov026_02091360 = st;
    *(int *)(st + 4) = InstantiateClass(&data_ov026_02091230, 0);
    *(int *)st = 9;
    return (void *)&Ov026_ConsumeHeapFlag3Handler;
}
