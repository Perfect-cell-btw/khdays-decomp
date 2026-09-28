/* Copies the 44-byte transform block from the source node into the destination object (+0x30). */

typedef struct { int w[11]; } Blk44;

void Ov257_CopyBlock44(char *obj) {
    char *node = *(char **)(obj + 4);
    char *dst = *(char **)node;
    char *src = *(char **)(node + 4);
    *(Blk44 *)(dst + 0x30) = *(Blk44 *)src;
}
