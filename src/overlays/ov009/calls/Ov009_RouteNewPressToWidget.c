/* Ov009_RouteNewPressToWidget -- route a fresh press to the first widget under the pointer.
 * The input is sampled (and, if the sampler declines, filled in by Ov009_Touch_GetLatestValidSampleB), then
 * only a NEWLY pressed key counts -- `new & (new ^ previous)` against the copy at +0x4a48.
 * The widget list at +0x4a38 is walked in order and hit-tested with Ov009_Widget_HitTest; the
 * first hit gets its handler (+0x98) called and stops the walk.
 * The sampled input is copied to +0x4a44 exactly once either way: in the hit path before the
 * handler runs (so the handler can read it), otherwise on the way out.
 * Reports whether anything was hit. */

typedef struct {
    unsigned short x;
    unsigned short y;
    unsigned short keys;
    unsigned short pad;
} Ov000_Input;

extern int Ov009_CopySourceBlock(Ov000_Input *in);
extern void Ov009_Touch_GetLatestValidSampleB(int self, Ov000_Input *in);
extern void *NNS_FndGetNextListObject(void *list, void *obj);
extern int Ov009_Widget_HitTest(int self, int x, int y, void *obj);
extern void MI_CpuCopy8(const void *src, void *dst, unsigned int n);

int Ov009_RouteNewPressToWidget(int self) {
    Ov000_Input in;
    int hit;
    void *obj;

    hit = 0;
    if (Ov009_CopySourceBlock(&in) == 0) {
        Ov009_Touch_GetLatestValidSampleB(self, &in);
    }

    if ((in.keys & (in.keys ^ *(unsigned short *)(self + 0x4a48))) != 0) {
        obj = NNS_FndGetNextListObject((void *)(self + 0x4a38), 0);
        while (obj != 0) {
            if (Ov009_Widget_HitTest(self, in.x, in.y, obj) != 0) {
                MI_CpuCopy8(&in, (void *)(self + 0x4a44), 8);
                (*(void (**)(void *))((char *)obj + 0x98))(obj);
                hit = 1;
                break;
            }
            obj = NNS_FndGetNextListObject((void *)(self + 0x4a38), obj);
        }
    }

    if (hit == 0) {
        MI_CpuCopy8(&in, (void *)(self + 0x4a44), 8);
    }
    return hit;
}
