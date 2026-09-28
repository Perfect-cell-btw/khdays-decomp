extern void NNSi_FndDestroyDoubleList(void *p);
extern void Node_BaseOnDestroy(void *p);

void ModelNode_Destroy(char *arg0) {
    NNSi_FndDestroyDoubleList(arg0 + 0x88);
    Node_BaseOnDestroy(arg0);
}
