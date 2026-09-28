extern int Scene_DrawNode();
extern int Sequence_UpdateTracks();

int Ov002_DrawAndStepNode(int arg0) {
    Scene_DrawNode(arg0);
    return Sequence_UpdateTracks(arg0, 0x1000);
}
