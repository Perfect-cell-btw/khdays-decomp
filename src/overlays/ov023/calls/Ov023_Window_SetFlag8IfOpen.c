#pragma thumb on
/* Ov023_Window_SetFlag8IfOpen -- set/clear sub-panel flag bit 8 (@+0x1a28) per `on`, but only
 * while the panel is enabled (bit 0), ov023. */
void Ov023_Window_SetFlag8IfOpen(char *obj, int on) {
    int *p = (int *)(obj + 0x1a28);
    if (*p & 1) {
        if (on != 0) {
            *p |= 8;
        } else {
            *p &= ~8;
        }
    }
}
