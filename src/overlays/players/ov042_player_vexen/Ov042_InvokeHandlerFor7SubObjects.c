/* Draws the character's seven effect nodes. */

extern void Ov042_ForwardToHandlerIfHeadSet();

void Ov042_InvokeHandlerFor7SubObjects(int this_, int base) {
    int i;
    char *p = (char *)(base + 0x14);
    for (i = 0; i < 7; i++) {
        Ov042_ForwardToHandlerIfHeadSet(p);
        p += 0x10c;
    }
}
