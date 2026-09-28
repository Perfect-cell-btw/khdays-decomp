/* Two-step teardown: FS_EndOverlay(param_1) then FS_UnloadOverlayImage(param_1). */
extern void FS_EndOverlay(int arg);
extern void FS_UnloadOverlayImage(int arg);
void Ov107_CallSetupThenSharedHandler(int param_1) {
    FS_EndOverlay(param_1);
    FS_UnloadOverlayImage(param_1);
}
