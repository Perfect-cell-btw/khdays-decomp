/* Ov004_ClassTeardown -- end the current key-sharing session, ov004 (tail-call to
 * WM_EndKeySharing over the doubly-indirected context @data_ov004_02051380). */
extern void *func_02023ad0(void *ctx);
extern void *data_ov004_02051380;
void *Ov004_ClassTeardown(void) {
    return func_02023ad0(*(void **)data_ov004_02051380);
}
