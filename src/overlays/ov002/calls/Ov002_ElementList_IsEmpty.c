/* Whether the global element list is empty. */

extern int NNS_FndGetNextListObject();
extern int data_ov002_0207f608;

int Ov002_ElementList_IsEmpty(void) {
    int p = *(int *)&data_ov002_0207f608;
    if (p == 0) {
        return 0;
    }
    return NNS_FndGetNextListObject(p, 0) == 0;
}
