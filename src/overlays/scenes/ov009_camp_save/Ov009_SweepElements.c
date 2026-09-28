/* Run the three-step sequence: Ov009_SweepReleasePendingElements(param_1), Ov009_FlushFlaggedElements(param_1, 0), Ov009_SweepFreeElementBuffers(param_1). */
extern void Ov009_SweepReleasePendingElements(int arg);
extern void Ov009_FlushFlaggedElements(int a, int b);
extern void Ov009_SweepFreeElementBuffers(int arg);
void Ov009_SweepElements(int param_1) {
    Ov009_SweepReleasePendingElements(param_1);
    Ov009_FlushFlaggedElements(param_1, 0);
    Ov009_SweepFreeElementBuffers(param_1);
}
