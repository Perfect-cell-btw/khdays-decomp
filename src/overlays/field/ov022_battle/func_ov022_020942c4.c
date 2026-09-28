extern int Ov022_IsBit0Set_5(unsigned char *arg0);
extern void Scene_DrawNode(unsigned short *arg0);
void func_ov022_020942c4(unsigned char *arg0) {
    if (!Ov022_IsBit0Set_5(arg0)) return;
    if ((*arg0 & 0x20) == 0) return;
    Scene_DrawNode((unsigned short *)(arg0 + 4));
}
