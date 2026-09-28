extern void EnqueueObjGfxCommand(int list);
extern void Ov002_SelectEntry(int id);
extern char data_ov002_0207f62c[];
/* If the scene has a pending queue (+0x8c), drain it (+0xc0) and raise event 0x1a. */
void Ov002_DrainSceneQueue(void) {
    int ctx = *(int *)(data_ov002_0207f62c + 4);
    if (*(int *)(ctx + 0x8c) != 0) {
        EnqueueObjGfxCommand(ctx + 0xc0);
        Ov002_SelectEntry(0x1a);
    }
}
