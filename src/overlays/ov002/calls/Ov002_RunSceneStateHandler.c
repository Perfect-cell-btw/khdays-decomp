/* When the scene has work pending (+0x20), call the handler its state (+0x28) selects from the
 * dispatch table, if that slot is filled. Always reports 0. */

extern int data_ov002_0207f9fc;
extern void (*data_ov002_0207eed8[])(void);

int Ov002_RunSceneStateHandler(void) {
    int ctx = *(int *)&data_ov002_0207f9fc;
    void (*handler)(void);

    if (*(int *)(ctx + 0x20) != 0) {
        handler = data_ov002_0207eed8[*(int *)(ctx + 0x28)];
        if (handler != 0) {
            handler();
        }
    }
    return 0;
}
