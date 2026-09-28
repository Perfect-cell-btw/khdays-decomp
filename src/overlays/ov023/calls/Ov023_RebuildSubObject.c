/* Ov023_RebuildSubObject -- rebuild the ov023 scene's sub-object at +0x87580.
 * Any existing one is torn down first, then a fresh instance of the class at
 * data_ov023_0208a748 is created and stored back into the same slot. */
extern void func_02023ad0(void);
extern int InstantiateClass(void *classDesc, int arg);
extern int data_ov023_0208a784;
extern char data_ov023_0208a748[];

void Ov023_RebuildSubObject(void) {
    if (*(int *)(*(int *)((char *)&data_ov023_0208a784 + 4) + 0x87580) != 0) {
        func_02023ad0();
    }
    *(int *)(*(int *)((char *)&data_ov023_0208a784 + 4) + 0x87580) =
        InstantiateClass(data_ov023_0208a748, 0);
}
