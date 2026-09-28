extern void Ov082_UpdateControllerCompleting(void *arg);

void Ov082_ForwardUpdateController(char *base) {
    Ov082_UpdateControllerCompleting(base + 0x2ca8);
}
