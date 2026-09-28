/* MsgDb_FetchStringPair -- fetch a record's two message strings, MAIN. Clears both string pointers, then
 * extracts strings index*2 and index*2+1 of message db `db` (P2_ExtractString, P2_ExtractString) into
 * ptrA/cntA and ptrB/cntB; fails (0) if either extraction fails. A record whose id (+0x00) is not
 * negative keeps the two strings (+0x04 / +0x08); otherwise both are cleared. Returns 1. The ROM
 * re-reads `index` from its stack slot for each call, hence the volatile parameter. */

#include "nitro/types.h"

typedef struct MsgRecord {
    short id;                           /* +0x00 */
    short pad02;
    u16 *textA;                         /* +0x04 */
    u16 *textB;                         /* +0x08 */
} MsgRecord;

extern int P2_ExtractString(u16 **out_ptr, u32 *out_count, int db, int k, int keep);   /* P2_ExtractString */

int MsgDb_FetchStringPair(MsgRecord *rec, u16 **ptrA, u16 **ptrB, u32 *cntA, u32 *cntB, int db, volatile int index, int keep)
{
    *ptrA = 0;
    *ptrB = 0;
    if (P2_ExtractString(ptrA, cntA, db, index * 2, keep) == 0) {
        return 0;
    }
    if (P2_ExtractString(ptrB, cntB, db, index * 2 + 1, keep) == 0) {
        return 0;
    }
    if (rec->id >= 0) {
        rec->textA = *ptrA;
        rec->textB = *ptrB;
    } else {
        rec->textA = 0;
        rec->textB = 0;
    }
    return 1;
}
