typedef struct { int w[11]; } Blk44;

void Ov235_CopyBlock44Alt(char *obj) {
    char *node = *(char **)(obj + 4);
    char *dst = *(char **)(node + 4);
    char *src = *(char **)(node + 8);
    *(Blk44 *)(dst + 0x30) = *(Blk44 *)src;
}
