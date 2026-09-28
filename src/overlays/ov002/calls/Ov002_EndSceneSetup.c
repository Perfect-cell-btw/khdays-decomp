extern int data_ov002_0207f600;
extern int Ov002_FreeBufferAndClearStatus();

int Ov002_EndSceneSetup(void) {
    return Ov002_FreeBufferAndClearStatus(*(int *)&data_ov002_0207f600 + 0x10);
}
