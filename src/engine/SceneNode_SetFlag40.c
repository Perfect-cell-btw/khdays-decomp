/* Set or clear bit 0x40 of the SceneNode flag halfword from a boolean argument. Same flag word as
 * SceneNode_Enable; the meaning of bit 0x40 is not yet established. */

void SceneNode_SetFlag40(void *pP, int flag)
{
    unsigned short *p = (unsigned short *)pP;
    if (flag)
        *p |= 0x40;
    else
        *p &= ~0x40;
}
