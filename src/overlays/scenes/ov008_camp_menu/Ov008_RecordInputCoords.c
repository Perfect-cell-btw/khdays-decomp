/* Ov008_RecordInputCoords -- Ov008_RecordInputCoords (164 B, 6 relocs).
 * Records the current input coordinates into the shared input log data_ov008_02090f00. Gets the
 * slot index (Session_GetLocalPlayerIndex) up front, and bails out if the log is not allocated or the gate
 * (Session_Exists) is false. When a fresh coordinate source is supplied (arg0 != 0) it copies the
 * 3-halfword coordinate triple into the log's "current" slot. Then, if Ov008_IsSessionReady()
 * reports the recording is enabled, it snapshots the current triple into the per-slot history
 * (entries[idx], stride 6) and signals mode 3 to Ov008_SendMenuMessage; otherwise it signals
 * mode 2. */

#include "nitro/types.h"

typedef struct InputCoords {
    u16 x;   /* 0x0 */
    u16 y;   /* 0x2 */
    u16 z;   /* 0x4 */
} InputCoords;

typedef struct InputLog {
    u8          pad_0000[0x2e];
    InputCoords entries[4];   /* 0x2e: per-slot recorded coords, stride 6 */
    InputCoords cur;          /* 0x46: current coordinates */
} InputLog;

extern InputLog *data_ov008_02090f00;
extern int  Session_GetLocalPlayerIndex(void);
extern int  Session_Exists(void);
extern int  Ov008_IsSessionReady(void);
extern void Ov008_SendMenuMessage(int mode);

void Ov008_RecordInputCoords(InputCoords *arg0)
{
    int idx = Session_GetLocalPlayerIndex();
    if (data_ov008_02090f00 == 0) return;
    if (Session_Exists() == 0) return;
    if (arg0 != 0) {
        InputLog *g = data_ov008_02090f00;
        g->cur = *arg0;
    }
    if (Ov008_IsSessionReady() != 0) {
        InputLog *g = data_ov008_02090f00;
        g->entries[idx] = g->cur;
        Ov008_SendMenuMessage(3);
    } else {
        Ov008_SendMenuMessage(2);
    }
}
