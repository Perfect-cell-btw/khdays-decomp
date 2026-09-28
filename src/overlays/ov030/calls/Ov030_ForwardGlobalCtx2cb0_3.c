extern int data_ov030_020b5a00;
extern void *Ov030_UpdateController();

void *Ov030_ForwardGlobalCtx2cb0_3(void) {
    return Ov030_UpdateController(data_ov030_020b5a00 + 0x2cb0);
}
