extern int data_ov002_0207f60c;
extern int Ov002_SetHalfword20();

int Ov002_World_SetElementListHalf20(void) {
    return Ov002_SetHalfword20(*(int *)&data_ov002_0207f60c + 0xdc);
}
