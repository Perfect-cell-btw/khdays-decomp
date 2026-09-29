/* MsgDb decoder for db 0x1a: bounds-check index, alloc a 0x54 record (kind 0x1a),
 * store index + elem[0], then copy 8 pairs (stride 8) from elem+4 into rec+0x14.
 * elem = entry[8] + index*0x44 (entry at table + 0x1a*0x14). */

#include "game/engine.h"

extern int data_0204c238;
int MsgDb_DecodeDb1A(int *rec_out, int index, int keep) {
    int elem;
    int i;
    int *ep;
    int off;
    if (MsgDb_IsLoaded(0x1a) == 0 || (keep >= 0 && *rec_out != 0)) {
        return 0;
    }
    if (index >= 0 && index < *(unsigned short *)(data_0204c238 + 0x214)) {
        elem = *(int *)(data_0204c238 + 0x210) + index * 0x44;
        if (MsgDb_AllocRecord(rec_out, 0x54, 0x1a, keep) == 0 || *rec_out == 0) {
            return 0;
        }
        *(int *)(*rec_out + 0xc) = index;
        *(int *)(*rec_out + 0x10) = *(int *)elem;
        ep = (int *)(elem + 4);
        i = 0;
        off = 0;
        do {
            *(int *)(*rec_out + off + 0x14) = ep[0];
            i = i + 1;
            *(int *)(*rec_out + off + 0x18) = ep[1];
            ep = ep + 2;
            off = off + 8;
        } while (i < 8);
        return 1;
    }
    return 0;
}
