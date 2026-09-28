extern void Ov044_UpdateController(void *arg);

void Ov044_ForwardUpdateController(char *base) {
    Ov044_UpdateController(base + 0x2ca8);
}
