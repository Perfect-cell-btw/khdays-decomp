/* Tail-call ReleaseNodeResources on the sub-object at param_1+0x1c. */
extern void ReleaseNodeResources(void *obj);
void Ov016_ReleaseEmbeddedNode_3(int param_1) {
    ReleaseNodeResources((void *)(param_1 + 0x1c));
}
