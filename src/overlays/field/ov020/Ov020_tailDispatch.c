/* ov thin tail-call veneer: forwards to ReleaseField74AndCleanup with a computed/first arg. */

extern void *ReleaseField74AndCleanup();
void *Ov020_tailDispatch(int p) {
    return ReleaseField74AndCleanup(p + 0x1c);
}
