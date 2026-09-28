extern void ReleaseNodeResources(int node);
/* Release the node resources at obj+0x498 and invalidate the handle at obj+0x6a (= -1). */
void Ov016_ReleaseNodeAndInvalidate(int obj) {
    ReleaseNodeResources(obj + 0x498);
    *(short *)(obj + 0x6a) = -1;
}
