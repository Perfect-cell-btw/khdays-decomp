/* NitroSDK spi (pm.c): PMi_SendPxiData -- retries PXI_SendWordByFifo(PXI_FIFO_TAG_PM = 8) until it succeeds. */
extern int func_020093e8(int a, int b, int c);

void PMi_SendPxiData(int arg0)
{
    while (func_020093e8(8, arg0, 0) != 0);
}
