#include "nitro/types.h"

#include "game/ov008_camp_menu.h"
/* Ov008_MissionLobbyEnter -- Ov008_MissionLobbyEnter: state entry for the mission
 * lobby.  Clears the two transfer words, drops the group header's bit 0 and the
 * join packet's "joined" flag; when no session is up yet it also clears the
 * list header and posts a join request (player index, target 0xff, arg 0) on
 * gate 0xd.  Returns the next state handler.
 */

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

#define MISSION_CONTEXT ((MissionContext *)data_ov008_02090f24.pContext)
extern int Session_IsReady(void);                                   /* Session_IsReady */
extern u32 Session_GetLocalPlayerIndex(void);                                   /* Session_GetLocalPlayerIndex */
extern void MsgQueue_SendGate(int nGate, void *pBuf, int nSize);      /* MsgQueue_SendGate */
extern void *Ov008_MissionLobbyJoin(void);                           /* next lobby state */

void *Ov008_MissionLobbyEnter(void)
{
    MISSION_CONTEXT->nTransferB = 0;
    MISSION_CONTEXT->nTransferA = 0;
    MISSION_CONTEXT->bHeaderBit0 = 0;
    MISSION_CONTEXT->join.bPending = 0;
    if (Session_IsReady() == 0) {
        MISSION_CONTEXT->nListHeader = 0;
        MISSION_CONTEXT->join.nPlayer = Session_GetLocalPlayerIndex();
        MISSION_CONTEXT->join.bPending = 0;
        MISSION_CONTEXT->join.nTarget = TARGET_ANY;
        MISSION_CONTEXT->join.nArg = 0;
        MsgQueue_SendGate(GATE_LOBBY, &MISSION_CONTEXT->join, sizeof(Ov008JoinPacket));
    }
    return (void *)Ov008_MissionLobbyJoin;
}
