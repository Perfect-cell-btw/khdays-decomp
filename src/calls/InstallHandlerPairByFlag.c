extern char data_0204bbfc[];
extern void EnqueueGfxCmd0();
extern void EnqueueGfxCmd1();
extern void Gfd_LoadTexB();
extern void Gfd_LoadTexPlttB();

void InstallHandlerPairByFlag(int arg0) {
    if (arg0 == 0) {
        *(void **)(data_0204bbfc + 0xc) = (void *)Gfd_LoadTexB;
        *(void **)(data_0204bbfc + 0x10) = (void *)Gfd_LoadTexPlttB;
    } else {
        *(void **)(data_0204bbfc + 0xc) = (void *)EnqueueGfxCmd0;
        *(void **)(data_0204bbfc + 0x10) = (void *)EnqueueGfxCmd1;
    }
}
