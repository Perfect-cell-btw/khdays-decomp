/* Aim/scale variant of Ov257_AimAndLaunchHoming using Ov235_SteerToTarget and node[0x17]. */

extern void Ov235_SteerToTarget(int node, int arg, void *outVec, int *outScale);
extern void ScaleVec3Fx12(int scale, void *src, void *dst);
extern void SetIndexedSlot(int self, int idx, int cb);

void Ov235_AimAndLaunchHoming(int param_1) {
    int *node = *(int **)(param_1 + 4);
    int scale;
    int aim[3];
    Ov235_SteerToTarget((int)node, node[0x17], aim, &scale);
    ScaleVec3Fx12(scale, aim, node + 4);
    if (*(unsigned char *)node[3] == 0) {
        *(char *)(*node + 0x1c7) = 2;
        SetIndexedSlot(param_1, *(signed char *)((char *)param_1 + 0x20), 0);
    }
}
