extern int FSi_WaitForCardThread();
extern int FS_LoadOverlayImage();

int Loader_LoadOverlayImage(int a) {
    FSi_WaitForCardThread(a);
    return FS_LoadOverlayImage(a);
}
