/* Ov107_ActionResource_Destroy -- update the node's child widget then itself, ov107. */
extern void DestroyInstance(void *child);
extern void FreeInstanceMemory(void *node);
void Ov107_ActionResource_Destroy(char *node) {
    DestroyInstance(*(void **)(node + 0x3c));
    FreeInstanceMemory(node);
}
