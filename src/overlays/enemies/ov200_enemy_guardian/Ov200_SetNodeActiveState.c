/* Marks the node active, or, when deactivated and of type 1, marks it finished (the 4-bit state at
 * +0x34). */

typedef struct {
    char pad[0x38];
    int type : 4;
    int state : 4;
} Node;

void Ov200_SetNodeActiveState(Node *node, int active) {
    if (active != 0) {
        node->state = 1;
    } else if (node->type == 1) {
        node->state = 2;
    }
}
