/* Returns a byte of the object a global points to. */

extern int data_ov002_0207f620;

int Ov002_Panel_GetCursor(void) {
    return *(unsigned char *)(*(int *)&data_ov002_0207f620 + 1);
}
