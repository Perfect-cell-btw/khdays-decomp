void SceneNode_SetFlag40(unsigned short *p, int flag)
{
    if (flag)
        *p |= 0x40;
    else
        *p &= ~0x40;
}
