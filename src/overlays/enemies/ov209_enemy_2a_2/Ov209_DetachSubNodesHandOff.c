/*
 * Ov209_DetachSubNodesHandOff -- x3 (ov208/209/268). Detach all sub-nodes, then hand off.
 * Notify the owner via 020c2b38(arg, *(self+0x3b0)); walk the 5-entry table at *(self+0x40c):
 * for each live handle (word at +8*i+4) release it through 0203c650(*(self+0x3c), handle) and
 * clear the slot. Finish by ticking 020c7c1c(self, arg).
 */
extern void Ov107_InvokeSlot0x74(int owner, int node);
extern void TaskList_FinishByTag(int scene, int handle);
extern void Ov107_Actor_DetachFromRegion(int self, int arg);

struct slot { int a; int handle; };

void Ov209_DetachSubNodesHandOff(int self, int arg) {
    int i, handle;

    Ov107_InvokeSlot0x74(arg, *(int *)(self + 0x3b0));
    for (i = 0; i < 5; i++) {
        handle = ((struct slot **)self)[0x40c / 4][i].handle;
        if (handle != 0) {
            TaskList_FinishByTag(*(int *)(self + 0x3c), handle);
            ((struct slot **)self)[0x40c / 4][i].handle = 0;
        }
    }
    Ov107_Actor_DetachFromRegion(self, arg);
}
