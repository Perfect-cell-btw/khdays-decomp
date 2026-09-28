extern void RefreshObjectCallbacks(int child, int arg);
extern void DispatchObjectCallbacks(void *child, int flag);
/* Refresh the node's child object (node+0x3c) and then re-select it. */
void Ov107_RefreshAndSelectChild(int node, int arg1) {
    RefreshObjectCallbacks(*(int *)(node + 0x3c), arg1);
    DispatchObjectCallbacks(*(void **)(node + 0x3c), 1);
}
