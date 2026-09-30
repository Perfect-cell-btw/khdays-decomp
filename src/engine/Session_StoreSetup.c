/* Stores the 16-byte session setup (gSessionSetup: state, player slot count, key, member mask)
 * that Session_Init and the field scene read back through Session_GetSetup. */

extern void MI_CpuCopy8();
extern int gSessionSetup;

void Session_StoreSetup(void *setup) {
    MI_CpuCopy8(setup, &gSessionSetup, 0x10);
}
