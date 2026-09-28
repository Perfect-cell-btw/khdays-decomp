/* Ov000_MarkSceneReady -- flag the logo scene block ready, ov000. Runs
 * Ov000_BeginCardTransfer, then sets the scene block's ready field (@+0x6a44) to 1. */
extern void Ov000_BeginCardTransfer(int);
extern char *data_ov000_0205ac24;
void Ov000_MarkSceneReady(int slot) {
    Ov000_BeginCardTransfer(slot);
    *(int *)(data_ov000_0205ac24 + 0x6a44) = 1;
}
