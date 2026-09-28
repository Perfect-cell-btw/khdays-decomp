extern void ReleaseNodeResources(int node);
/* Release the node resources at obj+0x2c and mark the object released (obj+0x2bc = 1). */
void Ov016_ReleaseNodeAndMark(int obj) {
    ReleaseNodeResources(obj + 0x2c);
    *(unsigned char *)(obj + 0x2bc) = 1;
}
