/* When the object's sync id is free, resets its counter, clears its state and builds its resource
 * node set; returns whether it did. */

extern int Obj_IsIdFree(int arg0);
extern void func_ov022_020b1264(int arg0, int arg1);
extern void Ov022_BuildResNodeSet(int arg0, unsigned int *arg1);
int Ov022_ActivateSyncRequest(int arg0) {
    if (Obj_IsIdFree(*(int *)(arg0 + 0x2c))) {
        *(short *)(arg0 + 0x34) = 0;
        func_ov022_020b1264(arg0, 0);
        Ov022_BuildResNodeSet(arg0, (unsigned int *)(arg0 + 4));
        return 1;
    }
    return 0;
}
