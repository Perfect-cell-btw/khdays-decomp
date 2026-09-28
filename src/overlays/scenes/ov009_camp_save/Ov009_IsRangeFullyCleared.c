/* Whether every mission in the value range of both lists is completed (clears *result on the first
 * open one). */

#include "nitro/types.h"

typedef struct Ov009ListObject {
    u8 pad000[2];
    u16 id;
    u8 pad004[0x14];
    int type;
    int rangeValue;
} Ov009ListObject;

extern Ov009ListObject *Ov009_FindListObjectWithField10Zero(
    void *list,
    Ov009ListObject *previous
);
extern u32 GameState_GetField(u32 field, int index);

int Ov009_IsRangeFullyCleared(
    void *firstList,
    void *secondList,
    int *result,
    int minimum,
    int maximum
)
{
    Ov009ListObject *object;

    object = Ov009_FindListObjectWithField10Zero(firstList, 0);
    while (object != 0) {
        if (object->rangeValue >= minimum &&
            object->rangeValue <= maximum &&
            GameState_GetField((u32)object->id * 3 + 0x28e4, 3) < 3) {
            *result = 0;
            return 0;
        }
        object = Ov009_FindListObjectWithField10Zero(firstList, object);
    }

    object = Ov009_FindListObjectWithField10Zero(secondList, 0);
    while (object != 0) {
        if (object->rangeValue >= minimum &&
            object->rangeValue <= maximum &&
            object->type != 4 &&
            GameState_GetField((u32)object->id * 3 + 0x2a4c, 3) == 0) {
            *result = 0;
            return 0;
        }
        object = Ov009_FindListObjectWithField10Zero(secondList, object);
    }

    return 1;
}
