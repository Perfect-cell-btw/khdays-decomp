/* Run the three-step sequence: Ov005_SweepReleasePendingElements(param_1), Ov005_FlushFlaggedElements(param_1, 0), Ov005_SweepFreeElementBuffers(param_1). */
extern void Ov005_SweepReleasePendingElements(int arg);
extern void Ov005_FlushFlaggedElements(int a, int b);
extern void Ov005_SweepFreeElementBuffers(int arg);
void Ov005_SweepElements(int param_1) {
    Ov005_SweepReleasePendingElements(param_1);
    Ov005_FlushFlaggedElements(param_1, 0);
    Ov005_SweepFreeElementBuffers(param_1);
}
