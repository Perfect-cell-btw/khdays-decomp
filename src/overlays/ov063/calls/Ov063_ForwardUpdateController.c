extern void Ov063_UpdateControllerCompleting(void *arg);

void Ov063_ForwardUpdateController(char *base) {
    Ov063_UpdateControllerCompleting(base + 0x2ca8);
}
