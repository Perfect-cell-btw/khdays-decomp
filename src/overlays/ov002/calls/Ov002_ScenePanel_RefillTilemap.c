extern int Ov002_Tilemap_RefillIfReady();
extern int data_ov002_0207f624;

void Ov002_ScenePanel_RefillTilemap(void) {
    int p = *(int *)&data_ov002_0207f624;
    if (*(int *)(p + 0x660) == 0) {
        return;
    }
    Ov002_Tilemap_RefillIfReady(p + 0xc);
}
