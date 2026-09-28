/* Ov009_StartCardTransfer -- commit a menu action and mark it handled, ov009. Runs
 * Ov009_BeginCardTransfer(action) and sets the handled flag at obj+0x23c. */
extern void Ov009_BeginCardTransfer(int action);
void Ov009_StartCardTransfer(char *obj, int action) {
    Ov009_BeginCardTransfer(action);
    *(int *)(obj + 0x23c) = 1;
}
