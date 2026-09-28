extern void SceneNode_AttachToModelJoint();
extern void ClearFlag8HandleIfNot10();
extern void EntityMgr_UnlinkFromListA();
extern void EntityMgr_UnlinkFromListB();
void ReleaseNodeResources(int *param_1)
{
    if ((*(unsigned char *)(param_1 + 2) & 2) == 0)
        return;
    if ((*(unsigned char *)(param_1 + 2) & 4) != 0)
        SceneNode_AttachToModelJoint((int)(param_1 + 4), 0, 0);
    ClearFlag8HandleIfNot10((unsigned int *)(param_1 + 3));
    if ((*(unsigned char *)(param_1 + 2) & 0x20) != 0)
        EntityMgr_UnlinkFromListA(param_1);
    else
        EntityMgr_UnlinkFromListB(param_1);
    *(unsigned char *)(param_1 + 2) &= ~2;
}
