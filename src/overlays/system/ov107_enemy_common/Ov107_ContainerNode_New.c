/* Allocate 0xb4 bytes via CallocInstance, initialise via Ov107_InitContainerNode,
 * return the allocation. */
extern int CallocInstance(int size);
extern void Ov107_InitContainerNode(int arg);
int Ov107_ContainerNode_New(void) {
    int r = CallocInstance(0xb4);
    Ov107_InitContainerNode(r);
    return r;
}
