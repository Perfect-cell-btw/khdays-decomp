/* Back-link param_1 into the sub-object (+0x4c), then arm it via NNS_G3dRenderObjSetCallBack
 * (handler Ov221_SyncPartNodesToJoint, mode 0/6/3). */
extern void NNS_G3dRenderObjSetCallBack(int a, int b, int c, int d, int e);
extern void Ov221_SyncPartNodesToJoint(void);
void Ov221_ArmModelCallback(int param_1) {
    *(int *)(*(int *)(*(int *)(param_1 + 0x384) + 0x88) + 0x4c) = param_1;
    NNS_G3dRenderObjSetCallBack(*(int *)(*(int *)(param_1 + 0x384) + 0x88) + 0x20,
                  (int)&Ov221_SyncPartNodesToJoint, 0, 6, 3);
}
