extern void Ov099_UpdateController(void *arg);

void Ov099_ForwardUpdateController(char *base) {
    Ov099_UpdateController(base + 0x2ca8);
}
