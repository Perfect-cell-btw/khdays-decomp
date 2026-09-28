/* Wait for the card thread to go idle, then FS_LoadOverlay. The paired teardown is
 * UnloadOverlaySync. */

extern void FS_LoadOverlay(int, int);
extern void FSi_WaitForCardThread(int, int);

void LoadOverlaySync(int a, int b)
{
    FSi_WaitForCardThread(a, b);
    FS_LoadOverlay(a, b);
}
