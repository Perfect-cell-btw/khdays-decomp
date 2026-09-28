/* Hides the referenced widget and releases its slots. */

extern int Ov025_GetContext();
extern int Ov025_PushSubitemPair();
extern int Ov025_ReleaseTwoSlotsEx_2();
extern int Ov025_ReleaseTwoSlots();

void Ov025_WidgetRef_Hide(int arg0) {
    int h = Ov025_GetContext(arg0);
    Ov025_PushSubitemPair(h, *(int *)(arg0 + 4), 1);
    Ov025_ReleaseTwoSlotsEx_2(h, *(int *)(arg0 + 4), 0);
    Ov025_ReleaseTwoSlots(h, *(int *)(arg0 + 4));
}
