/* Appends the load-screen apply step to the pending entries. */

extern int Ov002_AppendEntry();
extern int gOv002UiBtlBmLoTt08Path;
extern int Ov002_ApplyLoadedScreen();

int Ov002_QueueScreenLoad(void) {
    return Ov002_AppendEntry(&gOv002UiBtlBmLoTt08Path, Ov002_ApplyLoadedScreen, 0);
}
