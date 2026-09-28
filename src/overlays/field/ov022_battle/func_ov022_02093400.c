/* Draws the nine models of a loaded effect set, each with its own scale. */

extern void NNS_G3dGlbSetBaseScale(int *arg0);
extern void Scene_DrawNode(unsigned short *arg0);
void func_ov022_02093400(unsigned char *arg0) {
    int i;
    unsigned char *p;
    unsigned short *q;
    if ((*arg0 & 1) == 0) return;
    if ((*arg0 & 4) == 0) return;
    i = 0;
    p = arg0 + 0xb4;
    q = (unsigned short *)(arg0 + 4);
    do {
        NNS_G3dGlbSetBaseScale((int *)p);
        Scene_DrawNode(q);
        i++;
        p += 0x108;
        q += 0x84;
    } while (i < 9);
}
