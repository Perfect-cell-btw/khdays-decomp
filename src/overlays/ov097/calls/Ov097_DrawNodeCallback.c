extern void Scene_DrawNode();

void Ov097_DrawNodeCallback(int a, int *b) {
    if (b[0] == 2) {
        Scene_DrawNode((char *)b + 4);
    }
}
