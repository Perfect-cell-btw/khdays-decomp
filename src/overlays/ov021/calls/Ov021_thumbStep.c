extern void *ReleaseNodeResources();
void *Ov021_thumbStep(int p) {
    return ReleaseNodeResources(p + 0x124);
}
