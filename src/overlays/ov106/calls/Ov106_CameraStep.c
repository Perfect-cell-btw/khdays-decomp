/* Per-frame ov106 camera step: unless the ov022 camera is unset (-1), the +0x8b4c camera bounds are set
 * to +/-3.7 x +/-4.85 and then +/-95.0 x +/-127.0, the queued points are tested against the camera
 * (020b7dc4), the +0x8bc4 widget resets (020b7ec0) and the camera commits (02023cc0). */
extern char *data_ov106_020b8b60;
extern int func_ov022_02083f0c(void);
extern void *Ov002_GetWord20(void);
extern void Camera_CommitMatricesEx(void *bounds, int right, int left, int top, int bottom);
extern void Ov106_ConsumeReachedPoints(void *target);
extern void Ov106_ResetMarkerWidget(void);
extern void Camera_CommitMatrices(void *camera);

void Ov106_CameraStep(void)
{
    void *camera;

    if (func_ov022_02083f0c() == -1) {
        return;
    }
    camera = Ov002_GetWord20();
    Camera_CommitMatricesEx(data_ov106_020b8b60 + 0x8b4c, 0x3b33, -0x3b33, -0x4d9a, 0x4d9a);
    Camera_CommitMatricesEx(data_ov106_020b8b60 + 0x8b4c, 0x5f000, -0x5f000, -0x7f000, 0x7f000);
    Ov106_ConsumeReachedPoints(camera);
    Ov106_ResetMarkerWidget();
    Camera_CommitMatrices(camera);
}
