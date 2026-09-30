/* Reaction check: after the finishing action queues action 0 and reports it; otherwise, when the
 * actor is on the ground during an attack action, queues the landing action 0xb. */

typedef struct { unsigned char flag : 1; } BitByte;

int Ov114_UpdateNodeReservationState2(char *obj) {
    char *node = *(char **)*(char **)(obj + 0x214);
    signed char state = *(signed char *)(node + 0x1c6);
    if (state == 0xc) {
        *(char *)(node + 0x1c7) = 0;
        return 1;
    }
    if (*(signed char *)(node + 0x1c7) != 0xb && state != 0xb) {
        if (((BitByte *)(node + 0x17a))->flag) {
            if (!(state != 2 && state != 4 && state != 9 && state != 0xa))
                *(char *)(node + 0x1c7) = 0xb;
        }
    }
    return 0;
}
