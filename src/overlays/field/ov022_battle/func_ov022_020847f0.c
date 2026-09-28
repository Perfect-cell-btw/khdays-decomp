/* Retargets the panel surface (outside replay). */

extern unsigned char data_0204be04;
extern void Ov002_RetargetPanelSurface(void);
void func_ov022_020847f0(void) {
    if (data_0204be04 != 0) return;
    Ov002_RetargetPanelSurface();
}
