/* Copies the 44-byte transform from the source block at ctx[1] into +4 of ctx[0] and, when
 * ctx[0]'s busy byte at +0xad is clear, hands over to Task_MarkFinished.
 * (The eleven-word block copy is a plain struct assignment -- see Ov236_RenderAtOwnerModel.) */
typedef struct { int w[11]; } Blk44;

extern void Task_MarkFinished(char *self);

void Ov107_FollowUntilAnimEnd(char *self) {
    char **ctx = *(char ***)(self + 4);
    *(Blk44 *)((char *)ctx[0] + 4) = *(Blk44 *)ctx[1];
    if (*(unsigned char *)(ctx[0] + 0xad) != 0) {
        return;
    }
    Task_MarkFinished(self);
}
