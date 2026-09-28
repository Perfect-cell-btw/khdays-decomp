/* Releases the element's node item when it has one. */

extern int Render_ReleaseNodeItem();

void Ov002_Element_ReleaseNode(int arg0) {
    int n = *(int *)(arg0 + 8);
    if (*(signed char *)(n + 0x58) != 0) {
        Render_ReleaseNodeItem(arg0 + 0x2c);
    }
}
