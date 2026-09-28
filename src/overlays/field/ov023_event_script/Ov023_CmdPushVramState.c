/* Script command: pushes the entity manager VRAM state; returns 1. */

/* Forward to EntityMgr_PushVramState and return 1. */
extern void EntityMgr_PushVramState(int arg);
int Ov023_CmdPushVramState(int param_1) {
    EntityMgr_PushVramState(param_1);
    return 1;
}
