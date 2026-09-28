/* Interworking tail-call veneer (`ldr ip,[pc] ; bx ip`): forwards to GetUnpackedAnimBankImpl_. */
extern void *GetUnpackedAnimBankImpl_();

void *func_020116e4(void *pNanrFile, void *ppAnimBank) {
    return GetUnpackedAnimBankImpl_(pNanrFile, ppAnimBank);
}
