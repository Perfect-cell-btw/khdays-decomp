/* Stores the 16-byte session setup (data_020429b8: state, player slot count, key, member mask)
 * that Session_Init and the field scene read back through Session_GetSetup. */

extern void MI_CpuCopy8();
extern int data_020429b8;

void Session_StoreSetup(void *setup) {
    MI_CpuCopy8(setup, &data_020429b8, 0x10);
}
