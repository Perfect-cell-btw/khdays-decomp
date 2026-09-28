extern int data_ov030_020b5a00;
extern void *Ov030_ArmPlayerTarget();

void *Ov030_ForwardGlobalCtx2cb0(void) {
    return Ov030_ArmPlayerTarget(data_ov030_020b5a00 + 0x2cb0);
}
