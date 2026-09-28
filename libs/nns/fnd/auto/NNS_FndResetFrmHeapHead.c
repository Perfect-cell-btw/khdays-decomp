/* NitroSystem FND: resets the frame heap's head pointer and drops its saved states. */

void NNS_FndResetFrmHeapHead(int *p)
{
    p[0x24 / 4] = p[0x18 / 4];
    p[0x2c / 4] = 0;
}
