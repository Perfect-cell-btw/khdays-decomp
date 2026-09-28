/* Loads the three lock-on marker sprites from the archive, sets their sizes, priorities and alpha,
 * and clears their tween. */

typedef struct Ov022DisplayRecord {
    char pad00[4];
    unsigned short width;
    unsigned short height;
    unsigned int attributes;
    char pad0c[0x18];
    unsigned char alpha;
    char pad25[0xb];
} Ov022DisplayRecord;

typedef struct Ov022DisplayGroup {
    Ov022DisplayRecord records[3];
    char tween[0x1c];
} Ov022DisplayGroup;

extern int Archive_GetMember(int *list, int group, int index);
extern void Ov002_SetSlotKeyAndRebind(Ov022DisplayRecord *record, int resource, int mode);
extern void Tween_Clear(void *tween);

void Ov022_LoadMarkerSprites(Ov022DisplayGroup *group, int *list)
{
    int resource;

    resource = Archive_GetMember(list, 7, 0);
    Ov002_SetSlotKeyAndRebind(&group->records[0], resource, 1);
    resource = Archive_GetMember(list, 7, 1);
    Ov002_SetSlotKeyAndRebind(&group->records[1], resource, 1);
    resource = Archive_GetMember(list, 7, 5);
    Ov002_SetSlotKeyAndRebind(&group->records[2], resource, 1);

    group->records[0].width = 0x10;
    group->records[0].height = 0x10;
    group->records[1].width = 0x20;
    group->records[1].height = 0x20;
    group->records[2].width = 0x40;
    group->records[2].height = 0x40;

    group->records[0].attributes |= 0xa << 16;
    group->records[1].attributes |= 0xf << 16;
    group->records[2].attributes |= 0xf << 16;

    group->records[0].alpha = 0x3f;
    group->records[1].alpha = 0x3f;
    group->records[2].alpha = 0x3e;

    Tween_Clear(group->tween);
}
