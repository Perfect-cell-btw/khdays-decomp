extern void Ov107_ProcessObjectTick(void *obj, int arg2);

void Ov146_TickUnlessFrozen(char *obj, int arg2) {
    if (*(unsigned char *)(*(char **)(obj + 0x3b4) + 0x1c4) & 2) {
        if (*(unsigned short *)(obj + 0x1ac) & 0x10) {
            arg2 = 0;
        }
    }
    Ov107_ProcessObjectTick(obj, arg2);
}
