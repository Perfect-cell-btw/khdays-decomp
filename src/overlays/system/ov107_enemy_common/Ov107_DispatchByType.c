/* Dispatches an event to the handler registered for this node's type (*node), if any. */

extern int Ov107_FindMessageHandler(unsigned int type);
extern void Ov107_DispatchMessage(int handler, int node, int arg);

void Ov107_DispatchByType(unsigned short *node, int arg) {
    int handler = Ov107_FindMessageHandler(*node);
    if (handler == 0) {
        return;
    }
    Ov107_DispatchMessage(handler, (int)node, arg);
}
