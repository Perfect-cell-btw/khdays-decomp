extern void Scene_DrawNode(unsigned short *arg0);
void func_ov022_02092844(unsigned char *arg0) {
    if ((*arg0 & 1) != 0 && (char)arg0[1] != 0) {
        Scene_DrawNode((unsigned short *)(arg0 + 4));
    }
}
