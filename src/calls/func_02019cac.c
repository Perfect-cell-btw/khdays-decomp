/* Interworking tail-call veneer (`ldr ip,[pc] ; bx ip`): forwards to NNSi_SndCaptureEndSleep. */
extern void *NNSi_SndCaptureEndSleep();

void *func_02019cac() {
    return NNSi_SndCaptureEndSleep();
}
