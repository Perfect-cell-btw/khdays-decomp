/* Prize box class pfnGetNode: returns the node (+0x1c) while the state is below 8. */

void *Ov021_PrizeBox_GetNode(void *self)
{
    if (*(unsigned char *)((char *)self + 0x1b8) < 8) {
        return (char *)self + 0x1c;
    }
    return 0;
}
