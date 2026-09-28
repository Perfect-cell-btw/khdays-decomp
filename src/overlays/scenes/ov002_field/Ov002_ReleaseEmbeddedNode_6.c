/* Class slot 0x0c: releases the node resources embedded at +0x1c. */

extern int ReleaseNodeResources();

int Ov002_ReleaseEmbeddedNode_6(int arg0) {
    return ReleaseNodeResources(arg0 + 0x1c);
}
