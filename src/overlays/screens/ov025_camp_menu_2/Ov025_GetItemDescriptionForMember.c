/* Resolve an item description for the local session member, releasing prior cached records. */
typedef unsigned short u16;
typedef struct MsgDbItemRecord {
    char header[12];
    u16 *name,*description;
    int descriptionRecordId,category,unknown1c;
    u16 icon;
} MsgDbItemRecord;
typedef struct Ov005DescriptionCache {
    MsgDbItemRecord *record;
    int (*loadCallback)(MsgDbItemRecord **,int,unsigned int,int);
    int (*releaseCallback)(MsgDbItemRecord **);
    void *exitTaskHandle;
} Ov005DescriptionCache;
extern int Ov025_GetLocalMemberKind(void);
extern int Ov025_RemapCharCode00(int c);
extern int Ov025_RemapCharCode01(int c);
extern int Ov025_RemapCharCode02(int c);
extern int Ov025_RemapCharCode03(int c);
extern int Ov025_RemapCharCode04(int c);
extern int Ov025_RemapCharCode05(int c);
extern int Ov025_RemapCharCode06(int c);
extern int Ov025_RemapCharCode07(int c);
extern int Ov025_RemapCharCode08(int c);
extern int Ov025_RemapCharCode09(int c);
extern int Ov025_RemapCharCode10(int c);
extern int Ov025_RemapCharCode11(int c);
extern int Ov025_RemapCharCode12(int c);
extern int Ov025_RemapCharCode13(int c);
extern int Ov025_RemapCharCode14(int c);
extern int Ov025_RemapCharCode15(int c);
extern int Ov025_RemapCharCode16(int c);
extern int Ov025_RemapCharCode17(int c);

u16 *Ov025_GetItemDescriptionForMember(Ov005DescriptionCache *cache, MsgDbItemRecord *item) {
    int originalRecordId;
    int mappedRecordId;

    if (item == 0) {
        return 0;
    }
    originalRecordId = item->descriptionRecordId;
    if (cache->record != 0) {
        cache->releaseCallback(&cache->record);
    }
    switch (Ov025_GetLocalMemberKind()) {
    case 1:  mappedRecordId = Ov025_RemapCharCode00(originalRecordId); break;
    case 6:  mappedRecordId = Ov025_RemapCharCode01(originalRecordId); break;
    case 17: mappedRecordId = Ov025_RemapCharCode02(originalRecordId); break;
    case 18: mappedRecordId = Ov025_RemapCharCode03(originalRecordId); break;
    case 7:  mappedRecordId = Ov025_RemapCharCode04(originalRecordId); break;
    case 8:  mappedRecordId = Ov025_RemapCharCode05(originalRecordId); break;
    case 9:  mappedRecordId = Ov025_RemapCharCode06(originalRecordId); break;
    case 10: mappedRecordId = Ov025_RemapCharCode07(originalRecordId); break;
    case 16: mappedRecordId = Ov025_RemapCharCode08(originalRecordId); break;
    case 11: mappedRecordId = Ov025_RemapCharCode09(originalRecordId); break;
    case 0:
    case 14:
    case 19: mappedRecordId = Ov025_RemapCharCode10(originalRecordId); break;
    case 3:  mappedRecordId = Ov025_RemapCharCode11(originalRecordId); break;
    case 5:  mappedRecordId = Ov025_RemapCharCode12(originalRecordId); break;
    case 12: mappedRecordId = Ov025_RemapCharCode13(originalRecordId); break;
    case 4:  mappedRecordId = Ov025_RemapCharCode14(originalRecordId); break;
    case 13: mappedRecordId = Ov025_RemapCharCode15(originalRecordId); break;
    case 2:  mappedRecordId = Ov025_RemapCharCode16(originalRecordId); break;
    case 15: mappedRecordId = Ov025_RemapCharCode17(originalRecordId); break;
    default: mappedRecordId = originalRecordId; break;
    }
    if (mappedRecordId == originalRecordId) {
        return item->description;
    }
    cache->loadCallback(&cache->record, 0x15, mappedRecordId, 0xe);
    return cache->record->description;
}
