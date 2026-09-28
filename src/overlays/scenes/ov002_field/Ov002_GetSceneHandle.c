/* Returns a word of the field state (the object data_ov002_0207f62c points to). */

extern int data_ov002_0207fa20;

int Ov002_GetSceneHandle(void) {
    return *(int *)(*(int *)((char *)&data_ov002_0207fa20 + 4) + 0x60);
}
