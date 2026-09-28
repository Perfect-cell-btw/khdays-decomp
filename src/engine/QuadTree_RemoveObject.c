/* Unlinks the node from the object's quad tree, if it has one. */

extern void Node_UnlinkAndClearRefs(int);

void QuadTree_RemoveObject(int *param_1, int param_2) {
    if (param_1[0x27] == 0) {
        return;
    }
    Node_UnlinkAndClearRefs(param_2);
}
