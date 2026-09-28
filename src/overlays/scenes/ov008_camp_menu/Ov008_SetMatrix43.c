/* Copies a 4x3 matrix into the element (+0x10c). */

typedef struct { int w[12]; } Blk48;

void Ov008_SetMatrix43(char *obj, void *src) {
    *(Blk48 *)(obj + 0x10c) = *(Blk48 *)src;
}
