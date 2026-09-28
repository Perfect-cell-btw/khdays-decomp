/* Resource callback: blits the entry's queued image. */

extern int Ov026_BlitQueuedImage(int a, int b);
int Ov026_ResourceEntryCallback(int param_1) {
    return Ov026_BlitQueuedImage(param_1, 1);
}
