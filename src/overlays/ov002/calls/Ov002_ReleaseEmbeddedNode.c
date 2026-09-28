/* Class slot 0x0c: releases the node resources embedded at +0x2c. */

extern int ReleaseNodeResources();

int Ov002_ReleaseEmbeddedNode(int r0) {
    return ReleaseNodeResources(r0 + 0x2c);
}
