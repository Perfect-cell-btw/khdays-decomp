/* Ov107_Region_OnEvent -- refresh a node and forward the event to its parent, ov107. */
extern void Ov107_Region_SyncChildVisibility(void *node);
extern void DispatchObjectCallbacks(void *parent, int event);
void Ov107_Region_OnEvent(char *node, int event) {
    Ov107_Region_SyncChildVisibility(node);
    DispatchObjectCallbacks(*(void **)(node + 0x104), event);
}
