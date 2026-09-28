extern int ReleaseNodeResources();

int Ov002_ReleaseEmbeddedNode(int r0) {
    return ReleaseNodeResources(r0 + 0x2c);
}
