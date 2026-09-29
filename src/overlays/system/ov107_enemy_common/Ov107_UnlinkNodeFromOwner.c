extern int *Ov107_GetActorManager(void);
extern void TaskList_FinishByTag(int list, int node);
/* Unlink the node from the active owner's child list, if a node was given. */
void Ov107_UnlinkNodeFromOwner(void *node) {
    if (node == 0) {
        return;
    }
    TaskList_FinishByTag(*(int *)(*Ov107_GetActorManager() + 0x3c), (int)node);
}
