#pragma thumb on
/* Ov023_Window_SetFlag10 -- set/clear sub-panel flag bit 0x10 (@+0x1a28), ov023, per `on`. */
void Ov023_Window_SetFlag10(char *obj, int on) {
    if (on != 0) {
        *(int *)(obj + 0x1a28) |= 0x10;
    } else {
        *(int *)(obj + 0x1a28) &= ~0x10;
    }
}
