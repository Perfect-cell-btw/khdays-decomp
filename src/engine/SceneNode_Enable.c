/* Set bit 0x2 of the SceneNode flag halfword at node+0. This is the "1" arm of the boolean setter
 * Ov002_SetSceneNodeEnabled(node, on); SceneNode_Disable (SceneNode_Disable) is the "0" arm.
 * Callers configure the node first and enable it last (Ov014_SetFlag2RunTwoSubActionsIfFlag4). */

void SceneNode_Enable(void *pP)
{
    unsigned short *p = (unsigned short *)pP;
    *p |= 2;
}
