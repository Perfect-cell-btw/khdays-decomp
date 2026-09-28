/* Run the three-step sequence: Ov026_SweepReleasePendingElements(param_1), Ov026_FlushFlaggedElements(param_1, 0), Ov026_SweepFreeElementBuffers(param_1). */
extern void Ov026_SweepReleasePendingElements(int arg);
extern void Ov026_FlushFlaggedElements(int a, int b);
extern void Ov026_SweepFreeElementBuffers(int arg);
void Ov026_SweepElements(int param_1) {
    Ov026_SweepReleasePendingElements(param_1);
    Ov026_FlushFlaggedElements(param_1, 0);
    Ov026_SweepFreeElementBuffers(param_1);
}
