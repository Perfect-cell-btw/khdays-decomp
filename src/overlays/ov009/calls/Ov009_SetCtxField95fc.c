/* Ov009_SetCtxField95fc -- set the pending sub-menu id, ov009. Notifies Ov009_EnableBothHalves
 * then records `id` in the ov009 context (*(&data_ov009_020563e4+4) @+0x95fc). */
extern void Ov009_EnableBothHalves(int id);
extern int data_ov009_020563e4;
void Ov009_SetCtxField95fc(int id) {
    Ov009_EnableBothHalves(id);
    *(int *)(*(char **)((char *)&data_ov009_020563e4 + 4) + 0x95fc) = id;
}
