extern void SceneNode_AttachToModelJoint();
extern void EntityMgr_SpliceIntoListA();
extern void EntityMgr_SpliceIntoListB();
void LinkChildNode(int *param_1, int *param_2, unsigned int *param_3)
{
    SceneNode_AttachToModelJoint((int)(param_1 + 4), (int)(param_2 + 4), param_3);
    *(unsigned char *)(param_1 + 2) |= 0xb;
    if ((*(unsigned char *)(param_2 + 2) & 0x20) != 0) {
        *(unsigned char *)(param_1 + 2) |= 0x20;
        EntityMgr_SpliceIntoListA((unsigned int)*(unsigned char *)((char *)param_2 + 10), param_1, param_2);
        return;
    }
    *(unsigned char *)(param_1 + 2) &= ~0x20;
    EntityMgr_SpliceIntoListB((unsigned int)*(unsigned char *)((char *)param_2 + 10), param_1, param_2);
}
