/* Stores the 16-byte session setup (data_020429b8: id, mode, key, member mask) that Session_Init
 * reads back through Session_GetSlotTable. */

extern void MI_CpuCopy8();
extern int data_020429b8;

void Session_StoreSetup(void *setup) {
    MI_CpuCopy8(setup, &data_020429b8, 0x10);
}
