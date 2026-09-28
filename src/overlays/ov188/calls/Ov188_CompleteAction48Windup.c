typedef unsigned char u8;
typedef unsigned short u16;

typedef struct VecFx32 {
    int x;
    int y;
    int z;
} VecFx32;

struct Actor {
    char pad000[0x60];
    u16 flags60;
    char pad062[0x12];
    VecFx32 position74;
};

struct Ov188ActionState {
    struct Actor *actor;
    char pad004[4];
    struct Actor *target;
    int reactionContext0c;
    int angle10;
    int angle14;
    int timer18;
};

struct Ov188Scene {
    char pad000[0x2c];
    int frameStep2c;
};

struct Ov188ActionNode {
    struct Ov188Scene *scene;
    struct Ov188ActionState *state;
    char pad008[0x18];
    signed char slot20;
};

struct ActorFlags60 {
    u16 low : 8;
    u16 high : 8;
};

extern struct Actor *Ov107_FindNearestObject(struct Actor *actor, int mode);
extern void VEC_Subtract(VecFx32 *a, VecFx32 *b, VecFx32 *out);
extern int func_020050b4(int x, int z);
extern void Ov107_PostTagUpdate(struct Actor *actor, int arg1, int arg2);
extern void Ov107_BuildAndSendUpdate(struct Actor *actor, int reactionId,
                                int reactionMode, int context);
extern void SetIndexedSlot(struct Ov188ActionNode *node, int slot, void *next);
extern void Ov188_AiStep_QueueAction2OnAnimEnd(void);

void Ov188_CompleteAction48Windup(struct Ov188ActionNode *node)
{
    struct Ov188ActionState *state = node->state;
    VecFx32 direction;

    state->timer18 += node->scene->frameStep2c;
    if (state->timer18 < 0x6ee) {
        return;
    }

    state->target = Ov107_FindNearestObject(state->actor, 0);
    if (state->target != 0) {
        VEC_Subtract(&state->target->position74,
                     &state->actor->position74, &direction);
        state->angle10 = state->angle14 = func_020050b4(direction.x,
                                                        direction.z);
    }

    ((struct ActorFlags60 *)&state->actor->flags60)->high &= ~0x82;
    Ov107_PostTagUpdate(state->actor, 0, 0);
    Ov107_BuildAndSendUpdate(state->actor, 0x12f, 6,
                        state->reactionContext0c);
    SetIndexedSlot(node, node->slot20, Ov188_AiStep_QueueAction2OnAnimEnd);
}
