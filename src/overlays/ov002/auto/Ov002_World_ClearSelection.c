/* Clears the world's selection byte (0xff). */

extern int data_ov002_0207f60c;

void Ov002_World_ClearSelection(void) {
    *(unsigned char *)(*(int *)&data_ov002_0207f60c + 0x52) = 0xff;
}
