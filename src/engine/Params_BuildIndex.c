/* Builds the packed parameter index data_0204c590 from table 0x13 (0x73 records, MsgDb_LoadDb /
 * MsgDb_FetchRecord / DispatchByNodeKind / ResSlot_Release_2): for every record present (+0x20) the width is the
 * position of the highest bit set in its +0x24 mask (4 bits, `lo`) and the start is the running sum
 * of the previous widths (12 bits, `hi`). */
#pragma thumb on
#include "nitro/types.h"

struct Params {
    unsigned short lo : 4;
    unsigned short hi : 12;
};

typedef struct {
    char pad00[0x20];
    int present;        /* 0x20 */
    u8 mask;            /* 0x24 */
} TableRec;

extern void MsgDb_LoadDb(int table, int a);
extern void MsgDb_FetchRecord(TableRec **rec, int table, int index, int a);
extern void DispatchByNodeKind(TableRec **rec);
extern int ResSlot_Release_2(int table);
extern struct Params data_0204c590[];

void Params_BuildIndex(void)
{
    int start;
    TableRec *rec = 0;
    int i;
    int width;

    MsgDb_LoadDb(0x13, 0xf);
    start = 0;
    for (i = 1; i < 0x74; i++) {
        MsgDb_FetchRecord(&rec, 0x13, i, 0xf);
        data_0204c590[i - 1].lo = 0;
        if (rec->present != 0) {
            u8 mask = rec->mask;
            int b;

            for (b = 0; b < 8; b++) {
                if ((1 << b) & mask) {
                    width = b + 1;
                }
            }
            data_0204c590[i - 1].lo = width;
            data_0204c590[i - 1].hi = start;
            start += width;
        }
        DispatchByNodeKind(&rec);
    }
    ResSlot_Release_2(0x13);
}
