/* MsgDb decoder for db 0x20: bounds-check index, alloc a 0x2c record (kind 0x20),
 * store index + elem[0..5] (words) then elem+0x18 (short) and elem+0x1a/0x1b (bytes)
 * into rec+0x28/0x2a/0x2b. elem = entry[8] + index*0x1c (entry at table + 0x20*0x14). */

#include "game/engine.h"

extern int data_0204c238;
int MsgDb_DecodeDb20(int *rec_out, int index, int keep) {
    int *elem;
    if (MsgDb_IsLoaded(0x20) == 0 || (keep >= 0 && *rec_out != 0)) {
        return 0;
    }
    if (index >= 0 && index < *(unsigned short *)(data_0204c238 + 0x28c)) {
        elem = (int *)(*(int *)(data_0204c238 + 0x288) + index * 0x1c);
        if (MsgDb_AllocRecord(rec_out, 0x2c, 0x20, keep) == 0 || *rec_out == 0) {
            return 0;
        }
        *(int *)(*rec_out + 0xc) = index;
        *(int *)(*rec_out + 0x10) = elem[0];
        *(int *)(*rec_out + 0x14) = elem[1];
        *(int *)(*rec_out + 0x18) = elem[2];
        *(int *)(*rec_out + 0x1c) = elem[3];
        *(int *)(*rec_out + 0x20) = elem[4];
        *(int *)(*rec_out + 0x24) = elem[5];
        *(unsigned short *)(*rec_out + 0x28) = *(unsigned short *)((int)elem + 0x18);
        *(unsigned char *)(*rec_out + 0x2a) = *(unsigned char *)((int)elem + 0x1a);
        *(unsigned char *)(*rec_out + 0x2b) = *(unsigned char *)((int)elem + 0x1b);
        return 1;
    }
    return 0;
}
