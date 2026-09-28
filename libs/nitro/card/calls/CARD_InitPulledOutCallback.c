extern void PXI_Init();
extern void PXI_SetFifoRecvCallback(int fifoNo, void (*cb)(int, unsigned));
extern void CARDi_PulledOutCallback(int, unsigned);
extern int data_02046d40[];

void CARD_InitPulledOutCallback(void) {
    PXI_Init();
    PXI_SetFifoRecvCallback(0xe, CARDi_PulledOutCallback);
    data_02046d40[1] = 0;
}
