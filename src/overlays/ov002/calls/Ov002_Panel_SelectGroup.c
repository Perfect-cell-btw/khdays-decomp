/* Latch param_1 as the current byte at (*global)+4, then resolve the object at
 * (*global)+0x498 for that byte via NNS_FndGetNthListObject and cache the result at +0x4a4. */
extern int NNS_FndGetNthListObject(int obj, int key);
extern int data_ov002_0207f620;

void Ov002_Panel_SelectGroup(int param_1) {
    int base = *(int *)&data_ov002_0207f620;
    *(unsigned char *)(base + 4) = param_1;
    *(int *)(base + 0x4a4) = NNS_FndGetNthListObject(base + 0x498, *(unsigned char *)(base + 4));
}
