extern int NNSi_FndGetCurrentRootHeap();
extern void Tween_Clear();
extern void Tween_Configure();
extern void Tween_Start();

void Ov010_SetupRootHeapField58(int arg0, int arg1, int arg2) {
    int heap = NNSi_FndGetCurrentRootHeap();
    Tween_Clear(heap + 0x58);
    Tween_Configure(heap + 0x58, 0, arg0, arg1, arg2);
    Tween_Start(heap + 0x58);
}
