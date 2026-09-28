extern char *data_ov002_0207fa00;
/* Publish `value` into the root context's slot at +0x8d64. */
void Ov002_SetRootSlot0x8d64(int value) {
    *(int *)((int)data_ov002_0207fa00 + 0x8d64) = value;
}
