extern void ReleaseNodeResources(char *p);

void Ov021_tailDispatch(char *p) {
    ReleaseNodeResources(p + 0x2c);
}
