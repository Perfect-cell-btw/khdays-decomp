/* Clears the world's element list (+0xdc). */

extern int data_ov002_0207f60c;
extern int Ov002_ClearElementList();

int Ov002_ClearWorldElements(void) {
    return Ov002_ClearElementList(*(int *)&data_ov002_0207f60c + 0xdc);
}
