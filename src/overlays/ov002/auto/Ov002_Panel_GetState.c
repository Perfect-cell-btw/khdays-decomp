extern int data_ov002_0207f620;

int Ov002_Panel_GetState(void) {
    return *(unsigned char *)*(int *)&data_ov002_0207f620;
}
