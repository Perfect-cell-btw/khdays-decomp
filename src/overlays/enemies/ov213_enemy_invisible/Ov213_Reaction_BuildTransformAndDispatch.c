/* c634 handler: query Ov107_FindNearestObject; if 0, latch owner->+0x1c7 = 2 and
 * dispatch null cb. Otherwise build a transform (Mtx33_LookAt into a stack buffer,
 * then Quat_FromMtx33 into obj+0x38), set obj->f10 = -0x200, and if either owner bit
 * (+0x17a / +0x17c bit0) is set, OR 0xc into owner->+0x1b0 and dispatch cb. */
extern int Ov107_FindNearestObject(int owner, int a);
extern void SetIndexedSlot(int self, int index, void *cb);
extern void Mtx33_LookAt(void *buf, int a, int b, void *data);
extern void Quat_FromMtx33(int dst, void *buf);
extern void Ov213_EnterCharge(void);
extern int data_02042264;
struct bit0 { unsigned char b:1; };
void Ov213_Reaction_BuildTransformAndDispatch(int self) {
    int obj = *(int *)(self + 4);
    int buf[9];
    *(int *)(obj + 0x24) = Ov107_FindNearestObject(*(int *)obj, 0);
    if (*(int *)(obj + 0x24) == 0) {
        *(unsigned char *)(*(int *)obj + 0x1c7) = 2;
        SetIndexedSlot(self, *(signed char *)(self + 0x20), 0);
        return;
    }
    Mtx33_LookAt(buf, *(int *)(obj + 0x24) + 0x74, *(int *)obj + 0x74, &data_02042264);
    Quat_FromMtx33(obj + 0x38, buf);
    *(int *)(obj + 0x10) = -0x200;
    if (((struct bit0 *)(*(int *)obj + 0x17a))->b == 0 &&
        ((struct bit0 *)(*(int *)obj + 0x17c))->b == 0) {
        return;
    }
    *(unsigned short *)(*(int *)obj + 0x1b0) |= 0xc;
    SetIndexedSlot(self, *(signed char *)(self + 0x20), &Ov213_EnterCharge);
}
