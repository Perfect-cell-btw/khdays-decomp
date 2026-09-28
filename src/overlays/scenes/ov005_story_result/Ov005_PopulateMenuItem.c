/* Fills a reward list item from the item database (or the special reward texts): name, description,
 * icon, quantity and new-item state. */

typedef unsigned char u8;
typedef unsigned short u16;
typedef struct Ov005MenuItemHeader {
    u16 itemId,textureResourceId;
    u16 name[32];
    u16 description[256];
    int indicatorState;
    u8 quantities[2];
    u16 quantityLimit;
} Ov005MenuItemHeader;
typedef struct MsgDbItemRecord {
    char header[12];
    u16 *name,*description;
    int opaque14;
    int category;
    int opaque1c;
    u16 icon;
} MsgDbItemRecord;
extern char *data_ov005_0205b80c;
extern void MsgDb_FetchRecord(MsgDbItemRecord **,int,unsigned int,int);
extern void DispatchByNodeKind(MsgDbItemRecord **);
extern void StrNCopy16(u16 *,const u16 *,int);
extern u16 *Ov005_GetVarRecordByIndex(void *,unsigned int);
extern u16 *Ov005_GetItemDescriptionForMember(void *,MsgDbItemRecord *);
extern int GameState_IsFlagSet(unsigned int);
static inline int GetIconIndex(MsgDbItemRecord *record) {
    if (record==0 || record->icon==0) return 0;
    return record->icon-1;
}
void Ov005_PopulateMenuItem(Ov005MenuItemHeader *item,unsigned int itemId,int quantity,int row) {
    MsgDbItemRecord *record=0;
    if(item==0)return;
    if(itemId==0 || quantity==0)return;
    item->name[31]=0;
    item->description[255]=0;
    if(itemId>=0x277) {
        item->itemId=itemId;
        switch(itemId) {
        case 0x277:case 0x278:case 0x279:
            item->textureResourceId=itemId==0x279?0xd2:0xd1;
            MsgDb_FetchRecord(&record,0x15,itemId-0xb5,0xe);
            StrNCopy16(item->name,record->name,31);
            StrNCopy16(item->description,record->description,255);
            DispatchByNodeKind(&record);
            item->quantities[row]=1;
            break;
        case 0x27a:
            item->textureResourceId=0xd3;
            StrNCopy16(item->name,Ov005_GetVarRecordByIndex(data_ov005_0205b80c+0x6217c,11),31);
            StrNCopy16(item->description,Ov005_GetVarRecordByIndex(data_ov005_0205b80c+0x6217c,12),255);
            item->quantities[row]=quantity;
            break;
        case 0x27b:
            item->textureResourceId=0xd4;
            StrNCopy16(item->name,Ov005_GetVarRecordByIndex(data_ov005_0205b80c+0x6217c,13),31);
            StrNCopy16(item->description,Ov005_GetVarRecordByIndex(data_ov005_0205b80c+0x6217c,14),255);
            item->quantities[row]=quantity;
            break;
        }
        item->indicatorState=1;
    } else {
        int icon;
        MsgDb_FetchRecord(&record,0x15,itemId,0xe);
        icon=GetIconIndex(record);
        item->itemId=itemId;
        item->textureResourceId=icon;
        StrNCopy16(item->name,record->name,31);
        StrNCopy16(item->description,Ov005_GetItemDescriptionForMember(data_ov005_0205b80c+0x62188,record),255);
        item->quantities[row]+=quantity;
        if(GameState_IsFlagSet(itemId+0x37c9)) item->indicatorState=0;
        else item->indicatorState=1;
        item->quantityLimit=record->category==2 || itemId==1?255:99;
        DispatchByNodeKind(&record);
    }
}
