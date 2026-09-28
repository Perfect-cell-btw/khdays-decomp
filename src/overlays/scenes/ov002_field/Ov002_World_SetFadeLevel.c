/* Sets the field's fade level (capped at 16) and its fade state (1 when fading, 2 when clear). */

extern int data_ov002_0207f60c;

void Ov002_World_SetFadeLevel(int arg0) {
    int p = *(int *)&data_ov002_0207f60c;
    if ((unsigned int)arg0 > 0x10) {
        arg0 = 0x10;
    }
    *(char *)(p + 0x11) = arg0;
    *(char *)(p + 0x10) = (arg0 & 0xff) != 0 ? 1 : 2;
}
