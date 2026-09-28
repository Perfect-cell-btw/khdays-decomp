/* Advances a selection to the next enabled part after the target node in the object's part list;
 * returns whether one was found. */

typedef struct Ov022NodeFlags {
    unsigned int lowByte : 8;
    unsigned int rest : 24;
} Ov022NodeFlags;

typedef struct Ov022TraversalNode {
    char pad_0000[8];
    unsigned int flags8;
} Ov022TraversalNode;

typedef struct Ov022TraversalObject {
    char pad_0000[0x22c];
    char traversal22c[1];
} Ov022TraversalObject;

typedef struct Ov022SelectionState {
    int flags;
    int type;
    Ov022TraversalObject *object;
    Ov022TraversalNode *currentNode;
} Ov022SelectionState;

extern Ov022TraversalNode *List_First(void *list);
extern Ov022TraversalNode *List_Next(void *list);

int Ov022_WalkTraversalNode(Ov022SelectionState *state,
                        Ov022TraversalNode *targetNode, int active)
{
    int result = 0;
    Ov022TraversalObject *object = state->object;
    Ov022TraversalNode *node = List_First(object->traversal22c);

    if (node != 0) {
        int equalValue = 1;
        int flagValue = equalValue;

        while (node != 0) {
            unsigned int flags;

            if (targetNode != node && active == 0) {
                goto next_node;
            }
            if (active == 0) {
                node = List_Next(object->traversal22c);
            }
            if (node == 0) {
                break;
            }
            flags = ((Ov022NodeFlags *)&node->flags8)->lowByte;
            if ((flags & 2) != 0 || (flags & 1) == 0) {
                active = flagValue;
            } else if (state->currentNode == node) {
                active = equalValue;
            } else {
                state->currentNode = node;
                result = 1;
                state->type = result;
                break;
            }

next_node:
            node = List_Next(object->traversal22c);
        }
    }
    return result;
}
