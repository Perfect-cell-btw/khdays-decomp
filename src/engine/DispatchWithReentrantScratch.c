extern void RigWork_Update(int a, int b, void *guard, void *buf);
extern int data_020475d0;

/* Reentrancy guard: on the outermost call use a local 392-byte scratch buffer
   (published in the global guard); nested calls reuse the already-published one. */
void DispatchWithReentrantScratch(int param_1, int param_2, int param_3, int param_4) {
    char buffer[392];
    if (data_020475d0 == 0) {
        data_020475d0 = (int)buffer;
        RigWork_Update(param_1, param_2, &data_020475d0, buffer);
        data_020475d0 = 0;
        return;
    }
    RigWork_Update(param_1, param_2, &data_020475d0, (void *)data_020475d0);
}
