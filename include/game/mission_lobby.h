/* The Mission Mode session context: a block on the root heap that ov006 (the character select)
 * and ov008 (the mission lobby) each keep in their globals and drive through the same session
 * code -- the two overlays carry copies of it (ov008's is 0x500 bytes, ov006's stops at 0x4f4).
 * It holds the work buffers the wireless messages go through, the mission rows the lobby offers,
 * the selection message this console sends, and the entry blocks (one per player) that are
 * synchronised between consoles. */
#ifndef GAME_MISSION_LOBBY_H
#define GAME_MISSION_LOBBY_H

#include "nitro/types.h"

typedef struct MissionWorkBuffer {
    void *buffer;                   /* +0x00: 0x100 bytes, 32-byte aligned */
    u32 key;                        /* +0x04: the first word of the payload last copied in */
} MissionWorkBuffer;

/* One mission row the lobby offers (0xc0 bytes). */
typedef struct MissionRecord {
    u8 option;                      /* +0x00 */
    u8 pad_01;
    u16 selection;                  /* +0x02 */
    u8 key[6];                      /* +0x04: identifies the row (Ov008_MissionUpsertRowByKey) */
    u8 pad_0a[2];
    u32 field_0c[12];               /* +0x0c */
    u16 itemCount;                  /* +0x3c */
    u16 field_3e;                   /* +0x3e */
    u16 ready;                      /* +0x40 */
    u16 field_42;                   /* +0x42 */
    u32 field_44[3];                /* +0x44 */
    u16 labelText[0x38];            /* +0x50: the row's menu label */
} MissionRecord;

/* A player's name and status as the session reports them. */
typedef struct MissionPeerRecord {
    u16 name[11];                   /* +0x00: UTF-16, with its terminator */
    u8 status;                      /* +0x16 */
    u8 reserved;                    /* +0x17 */
} MissionPeerRecord;

typedef union MissionPeerRecords {
    MissionPeerRecord all[4];
    struct {
        MissionPeerRecord local;
        MissionPeerRecord remote[3];
    } split;
} MissionPeerRecords;

/* The players present, as the session state reports them (0x68 bytes). */
typedef struct MissionPeerRoster {
    u8 remotePeerCapacity;          /* +0x00: remote slots initialised */
    u8 pad_01[3];
    MissionPeerRecords records;     /* +0x04 */
    u8 remotePeerActive[3];         /* +0x64: per remote slot, the player is present */
    u8 pad_67;
} MissionPeerRoster;

/* 0x040: the committed mission row, or the roster while players gather. */
typedef union MissionActiveBlock {
    MissionRecord record;
    MissionPeerRoster roster;
    u8 lowState[0x68];              /* cleared with the input buffers */
} MissionActiveBlock;

typedef union MissionSelectionFlags {
    u8 raw;
    struct {
        u8 sendStarted : 1;         /* the message is being sent */
        u8 changed : 1;             /* the selection changed since it was sent */
        u8 unused : 6;
    } bits;
} MissionSelectionFlags;

/* The selection message this console sends (0x68 bytes). */
typedef struct MissionSelectionSendBlock {
    MissionSelectionFlags flags;    /* +0x00 */
    u8 reserved01[3];
    u32 sessionValue;               /* +0x04 */
    u16 sessionMask;                /* +0x08: the players present, one bit each */
    u16 playerNames[4][11];         /* +0x0a */
    u8 peerStatus[4];               /* +0x62 */
    u8 reserved66[2];
} MissionSelectionSendBlock;

/* The same block read as the key state it carries. */
typedef struct MissionKeyBlock {
    u32 field_0;                    /* +0x00 */
    u32 rawKeys;                    /* +0x04 */
    u16 packedKeys;                 /* +0x08 */
} MissionKeyBlock;

/* 0x42c: the 0x68-byte message block. */
typedef union MissionMessage {
    MissionSelectionSendBlock selection;
    MissionKeyBlock keys;
    u8 raw[0x68];
} MissionMessage;

typedef struct MissionEntryFlags {
    u8 selectable : 1;              /* bit 0 */
    u8 request : 1;                 /* bit 1 */
    u8 confirmed : 1;               /* bit 2 */
    u8 acknowledged : 1;            /* bit 3 */
    u8 unused : 4;
} MissionEntryFlags;

/* One player's entry (6 bytes). */
typedef struct MissionEntry {
    u8 playerIndex;                 /* +0x00 */
    MissionEntryFlags flags;        /* +0x01 */
    s8 characterId;                 /* +0x02: -1 = none */
    u8 reserved;                    /* +0x03 */
    u16 missionId;                  /* +0x04 */
} MissionEntry;

typedef union MissionEntryHeader {
    u32 raw;
    struct {
        u32 locked : 1;             /* bit 0: the entries may not be replaced */
        u32 dirty : 1;              /* bit 1 */
        u32 unused : 30;
    } bits;
} MissionEntryHeader;

/* The four players' entries, with the word in front of them (0x1c bytes). */
typedef struct MissionEntryBlock {
    MissionEntryHeader header;      /* +0x00 */
    MissionEntry entries[4];        /* +0x04 */
} MissionEntryBlock;

typedef struct MissionContext {
    u8 *primaryBuffer;              /* 0x000: the packet buffer; its first word counts packets */
    int sendSeq;                    /* 0x004: the outgoing sequence counter */
    MissionWorkBuffer workBuffers[4]; /* 0x008 */
    u32 transitionRequested;        /* 0x028 */
    u32 sendBusy;                   /* 0x02c: a reliable message is on its way */
    u32 workStates[4];              /* 0x030 */
    MissionActiveBlock active;      /* 0x040 */
    volatile u8 rowCount;           /* 0x100 */
    u8 pad_101[3];
    MissionRecord rows[4];          /* 0x104 */
    u32 rowStates[4];               /* 0x404: frames since each row was refreshed */
    u8 selectionBlock[0x18];        /* 0x414 */
    MissionMessage message;         /* 0x42c */
    u32 refreshRequested;           /* 0x494 */
    int refreshTimer;               /* 0x498 */
    int busy;                       /* 0x49c: a transfer is in flight; blocks starting another */
    u32 entryUpdateMask;            /* 0x4a0 */
    u32 entryInputReady;            /* 0x4a4 */
    MissionEntryBlock liveEntries;  /* 0x4a8 */
    MissionEntryBlock sentEntries;  /* 0x4c4: the block last sent */
    MissionEntry localEntry;        /* 0x4e0 */
    u8 pad_4e6[2];
    u32 localMode;                  /* 0x4e8: game-state flag 0x200d (solo play), latched when the
                                     * context is made (Ov008_Link_IsLocal) */
    u16 messageHandle;              /* 0x4ec: 0xffff = no reliable message pending */
    u8 mode;                        /* 0x4ee */
    u8 signal;                      /* 0x4ef */
    u8 startFailed;                 /* 0x4f0 */
    u8 pad_4f1;
    u16 retryCount;                 /* 0x4f2 */
    /* ov008 only: ov006 clears just the part before this (MISSION_CONTEXT_COMMON_SIZE) */
    int transferA;                  /* 0x4f4 */
    int groupBuilt;                 /* 0x4f8 */
    int transferB;                  /* 0x4fc */
} MissionContext;

/* The part of the context both overlays use: ov006's copy stops before transferA. */
#define MISSION_CONTEXT_COMMON_SIZE 0x4f4

/* Each overlay's mission globals (ov006 0x020565e4, ov008 0x02090f24). The .bss block is 28 bytes;
 * nothing uses the five words after these two, and the sources only match with them left out
 * (declared 28 bytes long, mwcc addresses the block differently). */
typedef struct MissionGlobals {
    MissionContext *pContext;       /* +0x00: the session context, a root-heap block */
    void *pController;              /* +0x04: the controller instance, whose update handler
                                     * (Obj +0x14) the lobby and selection screens swap */
} MissionGlobals;

#endif
