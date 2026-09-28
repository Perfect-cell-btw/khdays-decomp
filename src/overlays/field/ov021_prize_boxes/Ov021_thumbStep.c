/* Releases the element's node resources (+0x124). */

extern void *ReleaseNodeResources();
void *Ov021_thumbStep(int p) {
    return ReleaseNodeResources(p + 0x124);
}
