/* Run the Ov026_DestroyAllListObjects sweep; if the +0x4a7c bit 2 is set, notify 02032428 and clear it. */
extern void Ov026_DestroyAllListObjects(int);
extern void Obj_Release(int);
struct clr_bf { unsigned int b0:1, b1:1, b2:1; };
void Ov026_DestroyObjectsAndRelease(int param_1) {
    Ov026_DestroyAllListObjects(param_1);
    if (((struct clr_bf *)(param_1 + 0x4a7c))->b2 == 1) {
        Obj_Release(param_1);
        *(int *)(param_1 + 0x4a7c) &= ~4;
    }
}
