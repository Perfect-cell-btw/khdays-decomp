extern void Ov002_RebindAnimTracks();
extern void SceneNode_Enable();

void Ov014_SetFlag2RunTwoSubActionsIfFlag4(int this_, int arg1) {
    *(unsigned char *)(this_ + 0x1b1) |= 2;
    if ((*(unsigned short *)(this_ + 0x12) & 4) == 0) return;
    Ov002_RebindAnimTracks(this_ + 0x3c, arg1, 0);
    SceneNode_Enable(this_ + 0x3c);
}
