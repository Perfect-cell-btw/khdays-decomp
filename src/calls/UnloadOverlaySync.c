extern void FSi_WaitForCardThread(int, int);
extern void FS_UnloadOverlay(int, int);

void UnloadOverlaySync(int a, int b)
{
    FSi_WaitForCardThread(a, b);
    FS_UnloadOverlay(a, b);
}
