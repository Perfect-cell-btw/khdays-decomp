/* Run the three-step sequence: Ov006_SweepReleasePendingElements(param_1), Ov006_FlushFlaggedElements(param_1, 0), Ov006_SweepFreeElementBuffers(param_1). */
extern void Ov006_SweepReleasePendingElements(int arg);
extern void Ov006_FlushFlaggedElements(int a, int b);
extern void Ov006_SweepFreeElementBuffers(int arg);
void Ov006_SweepElements(int param_1) {
    Ov006_SweepReleasePendingElements(param_1);
    Ov006_FlushFlaggedElements(param_1, 0);
    Ov006_SweepFreeElementBuffers(param_1);
}
