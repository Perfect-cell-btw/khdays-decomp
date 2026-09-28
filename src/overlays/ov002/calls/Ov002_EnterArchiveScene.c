/* Scene entry: the context IS the current root heap block. Re-bank the display
 * flags at +0x38 (clear 0x32000, set 0x1000), resolve the two objects the
 * archive at +0x44 provides into +0x7c and +0x84, seed +0xb4 with 0x1f and run
 * the setup. */
extern void *NNSi_FndGetCurrentRootHeap(void);
extern int Ov002_UpdateCameraDistance(int archive);
extern int Ov002_Camera_GetPresetHeight(int archive);
extern void Ov002_ClearPendingOnBoot(void);

void Ov002_EnterArchiveScene(void) {
    char *ctx = NNSi_FndGetCurrentRootHeap();

    *(int *)(ctx + 0x38) = *(int *)(ctx + 0x38) & ~0x32000 | 0x1000;
    *(int *)(ctx + 0x7c) = Ov002_UpdateCameraDistance(*(int *)(ctx + 0x44));
    *(int *)(ctx + 0x84) = Ov002_Camera_GetPresetHeight(*(int *)(ctx + 0x44));
    *(int *)(ctx + 0xb4) = 0x1f;
    Ov002_ClearPendingOnBoot();
}
