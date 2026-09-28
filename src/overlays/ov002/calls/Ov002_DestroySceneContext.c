extern void Ov002_FreeFieldAt8(int ctx);
extern int NNSi_FndFreeFromDefaultHeap(int block);
extern char *data_ov002_0207f62c;
/* Tear down the scene context: release its inner field, then free the context itself and null the
 * global slot. */
void Ov002_DestroySceneContext(void) {
    if (data_ov002_0207f62c != 0) {
        Ov002_FreeFieldAt8((int)data_ov002_0207f62c);
        if (data_ov002_0207f62c != 0) {
            NNSi_FndFreeFromDefaultHeap((int)data_ov002_0207f62c);
            data_ov002_0207f62c = 0;
        }
    }
}
