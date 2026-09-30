/* Reaction check: after the finishing action queues action 0 and reports it; otherwise, when the
 * actor is on the ground during an attack action, queues the landing action. */

typedef struct { unsigned char flag : 1; } BitByte;

int Ov210_UpdateNodeReservationState(char *obj) {
    char *node = *(char **)*(char **)(obj + 0x214);
    signed char state = *(signed char *)(node + 0x1c6);
    if (state == 0x12) {
        *(char *)(node + 0x1c7) = 0;
        return 1;
    }
    if (*(signed char *)(node + 0x1c7) != 0x11 && state != 0x11) {
        if (((BitByte *)(node + 0x17a))->flag) {
            if (!(state != 2 && state != 9 && state != 0xa && state != 0xc && state != 0xd))
                *(char *)(node + 0x1c7) = 0x11;
        }
    }
    return 0;
}
