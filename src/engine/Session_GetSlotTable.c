/* CARDi_GetRomAccessor: returns the address of the ROM accessor block data_020429b8. */

extern int data_020429b8;

int Session_GetSlotTable(void) {
    return (int)&data_020429b8;
}
