struct v3 { int x, y, z; };
struct b1 { unsigned char b:1; };

extern void ScaleVec3Fx12(int a, void *b, void *c);
extern void Ov107_PostTagUpdate(int a, int b, int c);
extern void SetIndexedSlot(int node, int slot, void *cb);
extern void Ov250_stateScaleVecMagnitudeGate(void);

void Ov250_stEasePoseCheckFlags(int node) {
    int state = *(int *)(node + 4);
    struct v3 *src = (struct v3 *)(state + 0x60);
    *(struct v3 *)(state + 0x54) = *src;
    ScaleVec3Fx12(0xb00, src, src);
    if (*(unsigned char *)(*(int *)(state + 0xc)) != 0) return;
    {
        int obj = *(int *)state;
        if (((struct b1 *)(obj + 0x17a))->b || ((struct b1 *)(obj + 0x17c))->b) {
            Ov107_PostTagUpdate(obj, 9, 1);
            SetIndexedSlot(node, *(signed char *)(node + 0x20), &Ov250_stateScaleVecMagnitudeGate);
        }
    }
}
