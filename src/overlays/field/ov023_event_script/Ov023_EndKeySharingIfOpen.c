/* Ov023_EndKeySharingIfOpen -- end the pending key-sharing session if one is registered,
 * ov023 (handle @data_ov023_0208a000, -1 = none). */
extern void func_02023ad0(void *handle);
extern int data_ov023_0208a000;
void Ov023_EndKeySharingIfOpen(void) {
    if (data_ov023_0208a000 != -1) {
        func_02023ad0((void *)data_ov023_0208a000);
    }
}
