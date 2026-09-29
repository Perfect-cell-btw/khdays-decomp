/* MsgDb decoder for db 0x14: bounds-check, alloc a 0x58 record, fetch the string
 * pair, then store index + elem[0..3] and copy 5 pairs (elem[4],elem[5] walking) into
 * rec+0x28/+0x2c. elem = entry[8] + index*0x38 (table + 0x14*0x14). */

#include "game/engine.h"

extern int MsgDb_FetchStringPair(short *rec, void *a, void *b, void *c, void *d, int db, int index, int keep);
extern int data_0204c238;
int MsgDb_DecodeDb14(int *rec_out, int index, int keep) {
    int *pv;
    short *rec;
    int i, off;
    if (MsgDb_IsLoaded(0x14) == 0 || (keep >= 0 && *rec_out != 0)) {
        return 0;
    }
    if (index >= 0 && index < *(unsigned short *)(data_0204c238 + 0x19c)) {
        pv = (int *)(*(int *)(data_0204c238 + 0x198) + index * 0x38);
        if (MsgDb_AllocRecord(rec_out, 0x58, 0x14, keep) == 0 || (rec = (short *)*rec_out) == 0) {
            return 0;
        }
        if (MsgDb_FetchStringPair(rec, rec + 6, rec + 8, rec + 0x28, rec + 0x2a, 0x14, index, keep) == 0) {
            DispatchByNodeKind(rec_out);
            return 0;
        }
        *(int *)(*rec_out + 0x14) = index;
        *(int *)(*rec_out + 0x18) = pv[0];
        *(int *)(*rec_out + 0x1c) = pv[1];
        *(int *)(*rec_out + 0x20) = pv[2];
        *(int *)(*rec_out + 0x24) = pv[3];
        i = 0;
        off = 0;
        do {
            *(int *)(*rec_out + off + 0x28) = pv[4];
            i = i + 1;
            *(int *)(*rec_out + off + 0x2c) = pv[5];
            pv = pv + 2;
            off = off + 8;
        } while (i < 5);
        return 1;
    }
    return 0;
}
