/* Back-link param_1 into the sub-object (+0x4c), then arm it via NNS_G3dRenderObjSetCallBack
 * (handler Ov260_ModelNodeCallback, mode 0/6/3). */
extern void NNS_G3dRenderObjSetCallBack(int a, int b, int c, int d, int e);
extern void Ov260_ModelNodeCallback(void);
void Ov260_ArmModelCallback(int param_1) {
    *(int *)(*(int *)(*(int *)(param_1 + 0x384) + 0x88) + 0x4c) = param_1;
    NNS_G3dRenderObjSetCallBack(*(int *)(*(int *)(param_1 + 0x384) + 0x88) + 0x20,
                  (int)&Ov260_ModelNodeCallback, 0, 6, 3);
}
