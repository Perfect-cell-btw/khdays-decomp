/* Draws the character's seven effect nodes. */

extern void Ov081_ForwardToHandlerIfHeadSet();

void Ov081_InvokeHandlerFor7SubObjects(int this_, int base) {
    int i;
    char *p = (char *)(base + 0x14);
    for (i = 0; i < 7; i++) {
        Ov081_ForwardToHandlerIfHeadSet(p);
        p += 0x10c;
    }
}
