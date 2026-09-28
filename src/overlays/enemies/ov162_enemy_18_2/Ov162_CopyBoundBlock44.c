/* Copies the 44-byte transform block from the actor's bound source (+0x3c0) into the step's child.
 */

typedef struct { int w[11]; } Blk44;

void Ov162_CopyBoundBlock44(char *obj) {
    char *node = *(char **)(obj + 4);
    char *src = *(char **)(*(char **)node + 0x3c0);
    char *dst = *(char **)(node + 4);
    *(Blk44 *)(dst + 4) = *(Blk44 *)(src + 4);
}
