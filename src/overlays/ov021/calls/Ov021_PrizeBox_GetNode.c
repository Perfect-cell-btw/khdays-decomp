void *Ov021_PrizeBox_GetNode(void *self)
{
    if (*(unsigned char *)((char *)self + 0x1b8) < 8) {
        return (char *)self + 0x1c;
    }
    return 0;
}
