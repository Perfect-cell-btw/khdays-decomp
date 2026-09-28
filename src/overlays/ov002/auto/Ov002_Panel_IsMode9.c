/* True when the panel session mode (+1) is 9. */

extern int data_ov002_0207f620;

int Ov002_Panel_IsMode9(void) {
    return *(unsigned char *)(*(int *)&data_ov002_0207f620 + 1) == 9;
}
