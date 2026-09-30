/* Aim and launch a homing move: compute the aim vector and speed toward the target
 * (Ov257_SteerToTarget with node[0x18]) into stack buffers, scale it into the velocity (node[4]),
 * then if the target is still valid (*node[3] == 0) enter the move state (2) and register the
 * callback. */
extern void Ov257_SteerToTarget(int node, int arg, void *outVec, int *outScale);
extern void ScaleVec3Fx12(int scale, void *src, void *dst);
extern void SetIndexedSlot(int self, int idx, int cb);

void Ov257_AimAndLaunchHoming(int param_1) {
    int *node = *(int **)(param_1 + 4);
    int scale;
    int aim[3];
    Ov257_SteerToTarget((int)node, node[0x18], aim, &scale);
    ScaleVec3Fx12(scale, aim, node + 4);
    if (*(unsigned char *)node[3] == 0) {
        *(char *)(*node + 0x1c7) = 2;
        SetIndexedSlot(param_1, *(signed char *)((char *)param_1 + 0x20), 0);
    }
}
