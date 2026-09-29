struct m4 { int w[4]; };

extern void Ov107_PostTagUpdate(int obj, int a, int b);
extern void Mtx33_LookAt(int *out, int a, int b, int *tbl);
extern void Quat_FromMtx33(int dst, int *src);
extern void SetIndexedSlot(int obj, int a, int cb);
extern int data_02042264;
extern void Ov117_AiDecelUntilSlow(void);

// Switch to mode 2; if a source transform is bound (node[0x4c]), build the
// interpolated matrix into a scratch buffer, apply it into node[6..9] and mirror
// it into node[2..5]; then advance the sub-state with the follow-up callback.
void Ov117_BuildTransformMatrixThenAdvance(int *this)
{
    int node = this[1];
    int scratch[9];
    Ov107_PostTagUpdate(*(int *)node, 2, 0);
    if (*(int *)(node + 0x4c) != 0) {
        Mtx33_LookAt(scratch, *(int *)(node + 0x4c) + 0x190, *(int *)(node + 0x44), &data_02042264);
        Quat_FromMtx33(node + 0x18, scratch);
        *(struct m4 *)(node + 8) = *(struct m4 *)(node + 0x18);
    }
    SetIndexedSlot((int)this, *(signed char *)((int)this + 0x20), (int)&Ov117_AiDecelUntilSlow);
}
