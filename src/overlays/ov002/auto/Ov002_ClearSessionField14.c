/* Clears the session block's +0x14 word. */

extern int data_ov002_0207f99c;

void Ov002_ClearSessionField14(void) {
    int p = *(int *)&data_ov002_0207f99c;
    if (p != 0) {
        *(int *)(p + 0x14) = 0;
    }
}
