/* Class slot 0x0c: releases the node resources embedded at +0x2c. */

extern int ReleaseNodeResources();

int Ov002_ReleaseEmbeddedNode_2(int arg0) {
    return ReleaseNodeResources(arg0 + 0x2c);
}
