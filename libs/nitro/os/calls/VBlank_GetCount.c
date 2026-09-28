/* Returns the VBlank count: the word at data_027e0088 (DTCM), which the VBlank interrupt handler
 * increments. Its old name (OS_IsThreadAvailable) was a shape match. */

extern int data_027e0088;

int VBlank_GetCount(void) {
    return data_027e0088;
}
