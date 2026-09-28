/* Twin of FS_UnloadOverlayImage over KeyRepeat_Update. */
extern void KeyRepeat_Update(void *p);

int func_020362ec(void *p) {
    KeyRepeat_Update(p);
    return 1;
}
