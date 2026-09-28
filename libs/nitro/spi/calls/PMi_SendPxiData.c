/* NitroSDK spi (pm.c): PMi_SendPxiData -- retries PXI_SendWordByFifo(PXI_FIFO_TAG_PM = 8) until it succeeds. */
extern int PXI_SendWordByFifo(int a, int b, int c);

void PMi_SendPxiData(int arg0)
{
    while (PXI_SendWordByFifo(8, arg0, 0) != 0);
}
