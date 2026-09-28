/* Picks the selector's target by the selection type: the current candidate's part, the entry's
 * activation result, or the fixed target; then moves the selector to it. */

#include "nitro/types.h"

typedef struct Ov022Flags60Bits {
    unsigned short lowByte : 8;
    unsigned short highByte : 8;
} Ov022Flags60Bits;

typedef struct Ov022TypeOneObject {
    char pad_0000[0x60];
    u16 flags60;
    char pad_0062[0x14a];
    u16 flags1ac;
    char pad_01ae[0x6a];
    s16 state218;
    char pad_021a[0x12];
    char traversal22c[1];
} Ov022TypeOneObject;

typedef struct Ov022SelectorContext {
    char pad_0000[4];
    char traversalState[4];
    int type;
    Ov022TypeOneObject *typeOneObject;
    void **node;
    char pad_0014[4];
    void *entry;
    char *base;
} Ov022SelectorContext;

extern Ov022SelectorContext *NNSi_FndGetCurrentRootHeap(void);
extern int Ov002_TriggerEntryActive(void *entry);
extern void *List_Last(void *traversal);
extern void *Ov022_WalkTraversalNode(void *state, void **node, void *previous);
extern void *Ov022_MoveSelectorTo(int argument, void *selected);

void *Ov022_PickSelectorTarget(int argument)
{
    Ov022SelectorContext *context = NNSi_FndGetCurrentRootHeap();
    void *selected = 0;
    void *result = selected;

    if (context->type == 1) {
        goto type_one;
    }
    if (context->type == 2) {
        goto type_two;
    }
    if (context->type != 3) {
        goto after_switch;
    }
    selected = context->base + 0x8f8;
    goto after_switch;

type_two: {
        int value = Ov002_TriggerEntryActive(context->entry);
        if (value != 0) {
            selected = (void *)value;
        }
        goto after_switch;
    }

type_one: {
        Ov022TypeOneObject *object = context->typeOneObject;

        if ((object->flags1ac & 2) != 0 ||
            (((Ov022Flags60Bits *)&object->flags60)->lowByte & 1) == 0 ||
            object->state218 == 0) {
            selected = (char *)object + 0x74;
        } else {
            void **node = context->node;
            selected = (char *)*node + 4;
            if (node != List_Last(object->traversal22c)) {
                result = Ov022_WalkTraversalNode(context->traversalState, node, result);
            }
        }
    }

after_switch:
    if (result == 0) {
        result = Ov022_MoveSelectorTo(argument, selected);
    }
    return result;
}
