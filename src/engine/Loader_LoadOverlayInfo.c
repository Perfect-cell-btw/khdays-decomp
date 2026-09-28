/* Waits for the card thread, then loads the overlay info. */

extern void FSi_WaitForCardThread(void *arg0);
extern int FS_LoadOverlayInfo(void *info, int proc, int id);

int Loader_LoadOverlayInfo(void *info, int proc, int id) {
    FSi_WaitForCardThread(info);
    return FS_LoadOverlayInfo(info, proc, id);
}
