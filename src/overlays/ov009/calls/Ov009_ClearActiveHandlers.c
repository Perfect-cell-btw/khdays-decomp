/* Reset the ov009 id pair to -1. */
extern int data_ov009_020563ec;
void Ov009_ClearActiveHandlers(void) {
    data_ov009_020563ec = -1;
    (&data_ov009_020563ec)[1] = -1;
}
