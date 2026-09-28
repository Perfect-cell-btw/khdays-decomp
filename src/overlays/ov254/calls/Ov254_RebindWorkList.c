/* Rebind a rig to its work list for a new pose: reset the list (param_2) and its +0xc cursor, bind
 * the rig's *(+0x88) owner list, append the pose with tag 0xc, attach the list to the rig, set
 * channel 0 = (0, flag) and re-init the rig. */
extern void FreeAllResourceTables(int list);
extern void NNS_G3dRenderObjInit(int a, int b);
extern void Snd_RegisterSeqAndBind(int list, int owner, int pose, int tag);
extern void MainBlob_ResetSlotRows(int rig, int list);
extern void SetSubitemState(int rig, int channel, int a, int b);
extern void RefreshObjectCallbacks(int rig, int a);

void Ov254_RebindWorkList(int rig, int list, int pose, int flag)
{
    int owner = *(int *)(rig + 0x88);

    FreeAllResourceTables(list);
    *(int *)(list + 0xc) = 0;
    NNS_G3dRenderObjInit(owner + 0x20, *(int *)(owner + 0x78));
    Snd_RegisterSeqAndBind(list, owner, pose, 0xc);
    MainBlob_ResetSlotRows(rig, list);
    SetSubitemState(rig, 0, 0, flag);
    RefreshObjectCallbacks(rig, 0);
}
