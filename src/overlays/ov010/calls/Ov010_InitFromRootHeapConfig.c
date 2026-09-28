/* Gets the NNS root heap, reads its 0x58 config via Tween_Sample into a local, arithmetic-shifts
 * >>12, passes the result to SetMasterBrightnessMain and SetMasterBrightnessSub, and returns bit2
 * of *(heap+0x70). */

extern int NNSi_FndGetCurrentRootHeap();
extern void Tween_Sample();
extern void SetMasterBrightnessMain();
extern void SetMasterBrightnessSub();

struct bf70 { unsigned int _pad : 2; unsigned int b : 1; };

int Ov010_InitFromRootHeapConfig(void) {
    int obj = NNSi_FndGetCurrentRootHeap();
    int v;
    int s;
    Tween_Sample(obj + 0x58, &v);
    s = v >> 12;
    SetMasterBrightnessMain(s);
    SetMasterBrightnessSub(s);
    return ((struct bf70 *)(obj + 0x70))->b;
}
