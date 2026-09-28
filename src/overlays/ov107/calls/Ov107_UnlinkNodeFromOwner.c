extern int *func_ov107_020c9848(void);
extern void TaskList_FinishByTag(int list, int node);
/* Unlink the node from the active owner's child list, if a node was given. */
void Ov107_UnlinkNodeFromOwner(int node) {
    if (node == 0) {
        return;
    }
    TaskList_FinishByTag(*(int *)(*func_ov107_020c9848() + 0x3c), node);
}
