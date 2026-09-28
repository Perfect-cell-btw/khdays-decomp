typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct {
    u8 bytes[1];
} MissionCellList;

typedef struct {
    u8 pad_000[8];
    MissionCellList cell_list;
} Ov006RootContext;

extern Ov006RootContext *data_ov006_02056664;
extern void *Ov006_FindEntryByTag(MissionCellList *list, u16 tag);
extern void Ov006_Elem_SetPos(MissionCellList *list, void *cell, int x, int y);
extern void Ov006_TagTracker_InvokeCallback(MissionCellList *list, void *cell);

void Ov006_MissionRetargetCellByTag(u32 tag, int x, int y) {
    void *cell;

    cell = Ov006_FindEntryByTag(&data_ov006_02056664->cell_list, tag);
    Ov006_Elem_SetPos(&data_ov006_02056664->cell_list, cell, x, y);
    cell = Ov006_FindEntryByTag(&data_ov006_02056664->cell_list, tag);
    Ov006_TagTracker_InvokeCallback(&data_ov006_02056664->cell_list, cell);
}
