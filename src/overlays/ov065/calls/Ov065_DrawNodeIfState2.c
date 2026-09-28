extern void Scene_DrawNode(void *p);

void Ov065_DrawNodeIfState2(int *p) {
    if (*p != 2) return;
    Scene_DrawNode((char *)p + 4);
}
