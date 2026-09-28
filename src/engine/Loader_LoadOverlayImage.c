/* Waits for the card thread, then loads the overlay image. */

extern int FSi_WaitForCardThread();
extern int FS_LoadOverlayImage();

int Loader_LoadOverlayImage(int a) {
    FSi_WaitForCardThread(a);
    return FS_LoadOverlayImage(a);
}
