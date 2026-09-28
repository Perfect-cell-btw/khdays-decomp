/* Stores arg3 into this+0x4cc and arg4 into this+0x4c8; if bit2 (0x4) of the u16 flags at this+0x12
 * is set, calls Ov002_RebindAnimTracks(arg1, arg2, 0) then SceneNode_Enable(arg1). */

extern void Ov002_RebindAnimTracks();
extern void SceneNode_Enable();

void Ov017_StoreArgsRunTwoSubActionsIfFlag4(int this_, int arg1, int arg2, int arg3, int arg4) {
    *(int *)(this_ + 0x4cc) = arg3;
    *(int *)(this_ + 0x4c8) = arg4;
    if ((*(unsigned short *)(this_ + 0x12) & 4) == 0) return;
    Ov002_RebindAnimTracks(arg1, arg2, 0);
    SceneNode_Enable(arg1);
}
