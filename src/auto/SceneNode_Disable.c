/* Clear bit 0x2 of the SceneNode flag halfword at node+0. The "0" arm of Ov002_SetSceneNodeEnabled;
 * see SceneNode_Enable. */

void SceneNode_Disable(unsigned short *p)
{
    *p &= ~2;
}
