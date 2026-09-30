/* Leaves the field camera's look view (Ov002_Camera_UpdateFollow: Select, or A, B, L, R, X or Y
 * while in it): clears camera flags 0x2000 (the look view), 0x10000 and 0x20000 and sets 0x1000
 * (the view widening back), puts the distance (+0x7c) and height (+0x84) back to the preset's
 * (+0x44), seeds +0xb4 with 0x1f and drops the pending request (Ov002_ClearPendingOnBoot). The
 * camera context is the current root heap block. */
extern void *NNSi_FndGetCurrentRootHeap(void);
extern int Ov002_UpdateCameraDistance(int archive);
extern int Ov002_Camera_GetPresetHeight(int archive);
extern void Ov002_ClearPendingOnBoot(void);

void Ov002_Camera_LeaveLookView(void) {
    char *ctx = NNSi_FndGetCurrentRootHeap();

    *(int *)(ctx + 0x38) = *(int *)(ctx + 0x38) & ~0x32000 | 0x1000;
    *(int *)(ctx + 0x7c) = Ov002_UpdateCameraDistance(*(int *)(ctx + 0x44));
    *(int *)(ctx + 0x84) = Ov002_Camera_GetPresetHeight(*(int *)(ctx + 0x44));
    *(int *)(ctx + 0xb4) = 0x1f;
    Ov002_ClearPendingOnBoot();
}
