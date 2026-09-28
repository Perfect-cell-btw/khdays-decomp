/* Calls the node's +0x80 hook, if any, passing it the node. */

typedef void (*NodeHook)(char *node);

void Node_CallHook80(char *p) {
    NodeHook f = *(NodeHook *)(p + 0x80);
    if (f == 0)
        return;
    f(p);
}
