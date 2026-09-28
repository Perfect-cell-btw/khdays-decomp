/* Computes the aim angle on the global player context. */

extern int data_ov030_020b5a00;
extern void *Ov030_ComputeAimAngle();

void *Ov030_ForwardGlobalCtx2cb0_2(void) {
    return Ov030_ComputeAimAngle(data_ov030_020b5a00 + 0x2cb0);
}
