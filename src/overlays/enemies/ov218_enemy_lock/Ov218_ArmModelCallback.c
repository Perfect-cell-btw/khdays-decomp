/* Back-link param_1 into the sub-object (+0x4c), then arm it via NNS_G3dRenderObjSetCallBack
 * (handler Ov218_CaptureJoint, mode 0/6/3). */
extern void NNS_G3dRenderObjSetCallBack(int a, int b, int c, int d, int e);
extern void Ov218_CaptureJoint(void);
void Ov218_ArmModelCallback(int param_1) {
    *(int *)(*(int *)(*(int *)(param_1 + 0x384) + 0x88) + 0x4c) = param_1;
    NNS_G3dRenderObjSetCallBack(*(int *)(*(int *)(param_1 + 0x384) + 0x88) + 0x20,
                  (int)&Ov218_CaptureJoint, 0, 6, 3);
}
