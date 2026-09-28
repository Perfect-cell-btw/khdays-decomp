/* Panel callback: runs UpdateController on the controller at +0x2ca8. */

extern void Ov099_UpdateController(void *arg);

void Ov099_ForwardUpdateController(char *base) {
    Ov099_UpdateController(base + 0x2ca8);
}
