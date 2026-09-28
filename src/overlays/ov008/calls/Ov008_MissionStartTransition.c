typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct {
    u8 pad_000[0x28];
    u32 transition_requested;
    u8 pad_02c[0x14];
    u8 option;
    u8 pad_041;
    u16 selection;
} MissionContext;

extern MissionContext *volatile data_ov008_02090f24;
extern char data_ov008_02090f40[];

extern int Ov105_EnterState1AndResolveId(void);
extern int Ov105_WM_GetNextTgid(void);
extern void Ov105_SetBuffer(void *resource, int size);
extern int Ov105_WH_ParentConnect(int mode, int selection, int value, int count, int option);
extern void Ov105_WH_SetReceiver(void (*callback)(void));
extern void Ov105_SetPacketFilter(void (*callback)(void));
extern void Ov008_UpdateSlotCache(void);
extern void Ov008_MatchMissionStartPacket(void);

void Ov008_MissionStartTransition(void) {
    int value = Ov105_EnterState1AndResolveId();

    data_ov008_02090f24->selection = (u16)Ov105_WM_GetNextTgid();
    Ov105_SetBuffer(data_ov008_02090f40, 0x18);

    if (Ov105_WH_ParentConnect(0, data_ov008_02090f24->selection, value, 2,
                            data_ov008_02090f24->option) == 0) {
        return;
    }

    Ov105_WH_SetReceiver(Ov008_UpdateSlotCache);
    Ov105_SetPacketFilter(Ov008_MatchMissionStartPacket);
    data_ov008_02090f24->transition_requested = 1;
}
