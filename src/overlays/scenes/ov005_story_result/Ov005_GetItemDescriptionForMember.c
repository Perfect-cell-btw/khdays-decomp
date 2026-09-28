/* Resolve an item description for the local session member, releasing prior cached records. */
#include "nitro/types.h"
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
extern int Ov005_GetLocalMemberKind(void);
extern int Ov005_RemapDescriptionRecord00(int c);
extern int Ov005_RemapDescriptionRecord01(int c);
extern int Ov005_RemapDescriptionRecord02(int c);
extern int Ov005_RemapDescriptionRecord03(int c);
extern int Ov005_RemapDescriptionRecord04(int c);
extern int Ov005_RemapDescriptionRecord05(int c);
extern int Ov005_RemapDescriptionRecord06(int c);
extern int Ov005_RemapDescriptionRecord07(int c);
extern int Ov005_RemapDescriptionRecord08(int c);
extern int Ov005_RemapDescriptionRecord09(int c);
extern int Ov005_RemapDescriptionRecord10(int c);
extern int Ov005_RemapDescriptionRecord11(int c);
extern int Ov005_RemapDescriptionRecord12(int c);
extern int Ov005_RemapDescriptionRecord13(int c);
extern int Ov005_RemapDescriptionRecord14(int c);
extern int Ov005_RemapDescriptionRecord15(int c);
extern int Ov005_RemapDescriptionRecord16(int c);
extern int Ov005_RemapDescriptionRecord17(int c);

u16 *Ov005_GetItemDescriptionForMember(Ov005DescriptionCache *cache, MsgDbItemRecord *item) {
    int originalRecordId;
    int mappedRecordId;

    if (item == 0) {
        return 0;
    }
    originalRecordId = item->descriptionRecordId;
    if (cache->record != 0) {
        cache->releaseCallback(&cache->record);
    }
    switch (Ov005_GetLocalMemberKind()) {
    case 1:  mappedRecordId = Ov005_RemapDescriptionRecord00(originalRecordId); break;
    case 6:  mappedRecordId = Ov005_RemapDescriptionRecord01(originalRecordId); break;
    case 17: mappedRecordId = Ov005_RemapDescriptionRecord02(originalRecordId); break;
    case 18: mappedRecordId = Ov005_RemapDescriptionRecord03(originalRecordId); break;
    case 7:  mappedRecordId = Ov005_RemapDescriptionRecord04(originalRecordId); break;
    case 8:  mappedRecordId = Ov005_RemapDescriptionRecord05(originalRecordId); break;
    case 9:  mappedRecordId = Ov005_RemapDescriptionRecord06(originalRecordId); break;
    case 10: mappedRecordId = Ov005_RemapDescriptionRecord07(originalRecordId); break;
    case 16: mappedRecordId = Ov005_RemapDescriptionRecord08(originalRecordId); break;
    case 11: mappedRecordId = Ov005_RemapDescriptionRecord09(originalRecordId); break;
    case 0:
    case 14:
    case 19: mappedRecordId = Ov005_RemapDescriptionRecord10(originalRecordId); break;
    case 3:  mappedRecordId = Ov005_RemapDescriptionRecord11(originalRecordId); break;
    case 5:  mappedRecordId = Ov005_RemapDescriptionRecord12(originalRecordId); break;
    case 12: mappedRecordId = Ov005_RemapDescriptionRecord13(originalRecordId); break;
    case 4:  mappedRecordId = Ov005_RemapDescriptionRecord14(originalRecordId); break;
    case 13: mappedRecordId = Ov005_RemapDescriptionRecord15(originalRecordId); break;
    case 2:  mappedRecordId = Ov005_RemapDescriptionRecord16(originalRecordId); break;
    case 15: mappedRecordId = Ov005_RemapDescriptionRecord17(originalRecordId); break;
    default: mappedRecordId = originalRecordId; break;
    }
    if (mappedRecordId == originalRecordId) {
        return item->description;
    }
    cache->loadCallback(&cache->record, 0x15, mappedRecordId, 0xe);
    return cache->record->description;
}
