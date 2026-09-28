/* Draws the node when its state is 2. */

extern void Scene_DrawNode(void *p);

void Ov046_DrawNodeIfState2(int *p) {
    if (*p != 2) return;
    Scene_DrawNode((char *)p + 4);
}
