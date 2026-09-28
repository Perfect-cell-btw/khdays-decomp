/* Tail-call ReleaseNodeResources on the sub-object at param_1+0x2c. */
extern void ReleaseNodeResources(void *obj);
void Ov016_ReleaseEmbeddedNode_2(int param_1) {
    ReleaseNodeResources((void *)(param_1 + 0x2c));
}
