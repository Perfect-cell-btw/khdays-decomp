extern int Ov002_EnqueueBothSurfaces();
extern int data_ov002_0207f624;

void Ov002_ScenePanel_UploadSurfaces(void) {
    int p = *(int *)&data_ov002_0207f624;
    if (*(int *)(p + 0x660) == 0) {
        return;
    }
    Ov002_EnqueueBothSurfaces(p + 0xc);
}
