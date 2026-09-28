/* Resolves the calendar rank value for a day from the missions available on it and how many are
 * cleared. */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct Ov004ListConfig {
    u32 resourceId;
    int baseValue;
    int capacity;
} Ov004ListConfig;

typedef struct Ov004ObjectList {
    u32 words[9];
} Ov004ObjectList;

typedef struct Ov004ListObject {
    u8 pad000[2];
    u16 id;
    u8 pad004[6];
    u16 fallbackValue;
    u8 pad00c[0x10];
    int rangeValue;
} Ov004ListObject;

extern const Ov004ListConfig data_ov004_020510a4;
extern void Ov004_InitObjectWithList(Ov004ObjectList *list,
                                const Ov004ListConfig *config);
extern Ov004ListObject *Ov004_FirstPositiveCountNode(Ov004ObjectList *list);
extern Ov004ListObject *Ov004_FindListObjectWithField10Zero(
    Ov004ObjectList *list,
    Ov004ListObject *previous);
extern void Ov004_DestroyMissionList(Ov004ObjectList *list);
extern u32 GameState_GetField(u32 field, int width);

int Ov004_ResolveMissionRank(int value) {
    Ov004ListConfig config = data_ov004_020510a4;
    Ov004ObjectList list;
    Ov004ListObject *first;
    int matched;
    int total;
    Ov004ListObject *object;
    int result;

    config.capacity = 4;
    config.baseValue = value;
    Ov004_InitObjectWithList(&list, &config);
    first = Ov004_FirstPositiveCountNode(&list);
    matched = 0;
    total = 0;
    object = Ov004_FindListObjectWithField10Zero(&list, 0);
    while (object != 0) {
        int enabled =
            GameState_GetField((u32)object->id * 3 + 0x28e4, 3) >= 2;

        if (enabled != 0) {
            matched++;
        }
        if (object->rangeValue < value) {
            value = object->rangeValue;
        }
        total++;
        object = Ov004_FindListObjectWithField10Zero(&list, object);
    }
    if (first != 0 && matched >= total) {
        result = first->fallbackValue;
    } else {
        result = value + matched;
    }
    Ov004_DestroyMissionList(&list);
    return result;
}
