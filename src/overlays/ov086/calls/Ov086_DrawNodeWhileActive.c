extern void Scene_DrawNode(void *p);

void Ov086_DrawNodeWhileActive(int unused, char *p) {
    if (*(int *)(p + 0x11c) != 1) return;
    Scene_DrawNode(p + 0x120);
}
