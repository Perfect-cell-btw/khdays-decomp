extern void Scene_DrawNode();

int Ov014_ForwardIfFlag4Set(int this_) {
    if (*(unsigned short *)(this_ + 0x12) & 4) {
        Scene_DrawNode(this_ + 0x2c);
    }
    return 0;
}
