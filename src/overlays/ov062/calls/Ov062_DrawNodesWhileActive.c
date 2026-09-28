/* Draws both nodes while active. */

extern void Scene_DrawNode(void *node);

void Ov062_DrawNodesWhileActive(char *p) {
    if (*(int *)p != 1) return;
    Scene_DrawNode(p + 4);
    Scene_DrawNode(p + 0x10c);
}
