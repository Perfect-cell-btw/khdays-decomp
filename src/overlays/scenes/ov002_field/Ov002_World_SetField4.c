/* Stores the value into a field of the world object when it exists. */

extern int data_ov002_0207f60c;

void Ov002_World_SetField4(int arg0) {
    int p = *(int *)&data_ov002_0207f60c;
    if (p != 0) {
        *(int *)(p + 4) = arg0;
    }
}
