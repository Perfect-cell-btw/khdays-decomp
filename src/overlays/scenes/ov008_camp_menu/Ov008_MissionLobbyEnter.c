/* Ov008_MissionLobbyEnter -- Ov008_MissionLobbyEnter: state entry for the mission
 * lobby.  Clears the two transfer words, drops the group header's bit 0 and the
 * join packet's "joined" flag; when no session is up yet it also clears the
 * list header and posts a join request (player index, target 0xff, arg 0) on
 * gate 0xd.  Returns the next state handler.
 */
#include "nitro/types.h"

typedef struct Ov008JoinPacket {
    u8  nPlayer;              /* 0x00 */
    u8  bJoined : 1;          /* 0x01 bit 0 */
    u8  bPending : 1;         /*      bit 1 */
    u8  nSpare : 6;
    signed char nTarget;      /* 0x02: -1 = any */
    u8  nPad;                 /* 0x03 */
    u16 nArg;                 /* 0x04 */
} Ov008JoinPacket;

typedef struct MissionContext {
    u8  pad_0000[0x4a0];
    int nListHeader;          /* 0x4a0 */
    u8  pad_04a4[4];
    u32 bHeaderBit0 : 1;      /* 0x4a8: current group header */
    u32 nHeaderRest : 31;
    u8  pad_04ac[0x4e0 - 0x4ac];
    Ov008JoinPacket join;     /* 0x4e0 */
    u8  pad_04e6[0x4f4 - 0x4e6];
    int nTransferA;           /* 0x4f4 */
    u8  pad_04f8[4];
    int nTransferB;           /* 0x4fc */
} MissionContext;

#define GATE_LOBBY  0xd
#define TARGET_ANY  -1                                  /* signed byte: the ROM materialises it with mvn */

typedef void *(*Ov008StateFn)(void);

extern MissionContext *data_ov008_02090f24;
extern int Session_IsReady(void);                                   /* Session_IsReady */
extern u32 Session_GetLocalPlayerIndex(void);                                   /* Session_GetLocalPlayerIndex */
extern void MsgQueue_SendGate(int nGate, void *pBuf, int nSize);      /* MsgQueue_SendGate */
extern void *Ov008_MissionLobbyJoin(void);                           /* next lobby state */

void *Ov008_MissionLobbyEnter(void)
{
    data_ov008_02090f24->nTransferB = 0;
    data_ov008_02090f24->nTransferA = 0;
    data_ov008_02090f24->bHeaderBit0 = 0;
    data_ov008_02090f24->join.bPending = 0;
    if (Session_IsReady() == 0) {
        data_ov008_02090f24->nListHeader = 0;
        data_ov008_02090f24->join.nPlayer = Session_GetLocalPlayerIndex();
        data_ov008_02090f24->join.bPending = 0;
        data_ov008_02090f24->join.nTarget = TARGET_ANY;
        data_ov008_02090f24->join.nArg = 0;
        MsgQueue_SendGate(GATE_LOBBY, &data_ov008_02090f24->join, sizeof(Ov008JoinPacket));
    }
    return (void *)Ov008_MissionLobbyJoin;
}
