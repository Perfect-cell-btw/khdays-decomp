extern void Ov002_RebindAnimTracks();
extern void SceneNode_Enable();

void Ov021_StoreArgsRunTwoSubActionsIfFlag4(int this_, int arg1, int arg2, int arg3, int arg4) {
    *(int *)(this_ + 0x1b4) = arg3;
    *(int *)(this_ + 0x1b0) = arg4;
    if ((*(unsigned short *)(this_ + 0x12) & 4) == 0) return;
    Ov002_RebindAnimTracks(arg1, arg2, 0);
    SceneNode_Enable(arg1);
}
