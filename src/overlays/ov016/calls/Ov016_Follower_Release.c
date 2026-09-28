/* Tail-call Render_ReleaseNodeItem on the sub-object at param_1+0x1c. */
extern int Render_ReleaseNodeItem(void *obj);
int Ov016_Follower_Release(int param_1) {
    return Render_ReleaseNodeItem((void *)(param_1 + 0x1c));
}
