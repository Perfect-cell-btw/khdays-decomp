/* List-pair scene step: pumps the pending loads; returns no next step. */

extern int Ov002_PumpPendingLoads();

int Ov002_ListPairSceneLoadStep(void) {
    Ov002_PumpPendingLoads();
    return 0;
}
