/* NitroSystem: restores the frame palette VRAM manager state from a saved pair. */

extern struct { int a, b; } data_02047364;

void NNS_GfdSetFrmPlttVramState(int *p) {
    data_02047364.a = p[0];
    data_02047364.b = p[1];
}
