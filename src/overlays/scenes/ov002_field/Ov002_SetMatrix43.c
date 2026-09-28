typedef struct { int w[12]; } Blk48;

void Ov002_SetMatrix43(char *obj, void *src) {
    *(Blk48 *)(obj + 0x10c) = *(Blk48 *)src;
}
