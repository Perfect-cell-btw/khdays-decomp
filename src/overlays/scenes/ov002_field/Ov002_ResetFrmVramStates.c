/* Resets the frame texture and palette VRAM managers. */

extern int NNS_GfdResetFrmTexVramState();
extern int NNS_GfdResetFrmPlttVramState();

void Ov002_ResetFrmVramStates(int arg0) {
    NNS_GfdResetFrmTexVramState(arg0);
    NNS_GfdResetFrmPlttVramState();
}
