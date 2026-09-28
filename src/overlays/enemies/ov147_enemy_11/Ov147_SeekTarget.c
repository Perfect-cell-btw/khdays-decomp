typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct Vec3 {
    int x, y, z;
} Vec3;

typedef struct Vec4 {
    int x, y, z, w;
} Vec4;

struct AuxData {
    char pad00[0x1c4];
    u8 flags1c4;
    char pad1c5[0xcb];
    u16 field290;
};

struct Obj {
    char pad00[0x04];
    void *collisionOwner04;
    char pad08[0x58];
    u16 flags60;
    char pad62[0x12];
    Vec4 position74;
    char pad84[0x143];
    u8 state1c7;
    char pad1c8[0x90];
    int field258;
    int field25c;
    char pad260[0x130];
    struct AuxData *aux390;
};

struct State {
    struct Obj *owner;
    Vec3 *position;
    char pad08[0x18];
    int alternateQuery;
    int travel;
    Vec3 previousPosition;
};

struct Node {
    char pad00[0x04];
    struct State *state;
    char pad08[0x18];
    s8 action;
};

struct Zero44 {
    int words[11];
};

struct HitCommand {
    u32 flags00;
    Vec3 vector04;
    u32 field10;
    u32 field14;
    void *hit18;
    int pad1c[4];
};

struct CollisionHit {
    int pad00[2];
    u32 flags08 : 8;
};

struct CollisionResult {
    int pad00[2];
    int field08;
};

struct Hw60 {
    u16 low : 8;
    u16 high : 8;
};

extern const Vec3 data_02041dc8;
extern int Ov107_CollectSphereOverlaps(struct Obj *owner, Vec4 *position, struct Obj **results);
extern void VEC_Subtract(Vec3 *a, Vec3 *b, Vec3 *out);
extern void VEC_Normalize(Vec3 *a, Vec3 *out);
extern void ScaleVec3Fx12(int scale, Vec3 *a, Vec3 *out);
extern int Ov107_InvokeHitCallback(struct Obj *candidate, struct Obj *owner,
                              struct AuxData *aux, int mode, Vec3 *direction, int zero);
extern void func_ov107_020c0b90(struct Obj *owner, int mode, Vec3 position, int zero);
extern void Ov107_BuildAndSendUpdate(struct Obj *owner, int zero, int event, Vec3 *position);
extern void SetIndexedSlot(struct Node *node, int action, void *next);
extern struct Obj *Ov107_FindEntityHitBySphere(struct Obj *owner, Vec4 *position,
                                      void *result);
extern int Ov107_AiState_ApplyHit(struct Obj *target, int value, struct HitCommand *command);
extern void *Collision_CastRay(void *collision, Vec3 *position, Vec3 *direction);
extern struct CollisionResult *Collision_CastSphereEx(void *collision, Vec3 *position,
                                             Vec3 *direction, int radius, void *ignore);
extern int VEC_Mag(Vec3 *vector);

void Ov147_SeekTarget(struct Node *node)
{
    struct State *state = node->state;
    void *collisionOwner = state->owner->collisionOwner04;
    Vec4 origin;
    Vec3 movement;
    Vec3 ray;

    ((struct Hw60 *)&state->owner->flags60)->high &= ~0x80;
    origin = state->owner->position74;

    if (state->alternateQuery == 0) {
        struct Obj *results[4];
        Vec3 direction;
        int i;
        int count;

        count = Ov107_CollectSphereOverlaps(state->owner, &origin, results);
        for (i = 0; i < count; i++) {
            VEC_Subtract((Vec3 *)&results[i]->position74,
                         (Vec3 *)&state->owner->position74, &direction);
            direction.y = 0;
            VEC_Normalize(&direction, &direction);
            ScaleVec3Fx12(0x800, &direction, &direction);
            if (Ov107_InvokeHitCallback(results[i], state->owner,
                                    state->owner->aux390, 0,
                                    &direction, 0) != 0) {
                func_ov107_020c0b90(state->owner, 0, *state->position, 0);
                Ov107_BuildAndSendUpdate(state->owner, 0, 0x53, state->position);
                state->owner->state1c7 = 0;
                SetIndexedSlot(node, node->action, 0);
                return;
            }
        }
    } else {
        /* The helper consumes the object at &queryHit; this adjacent work area
         * is part of that query workspace and must be initialized first. */
        struct Zero44 scratch = {{0}};
        void *queryHit;
        struct Obj *target;

        target = Ov107_FindEntityHitBySphere(state->owner, &origin, &queryHit);
        if (target != 0 && (*(u16 *)((char *)target + 0x1ac) & 4) == 0) {
            struct HitCommand command = {0};

            command.flags00 = (command.flags00 & 0xffff0000) | 0x2004;
            command.vector04 = data_02041dc8;
            command.field10 = (command.field10 & 0xffff0000) |
                              (((u32)state->owner->aux390->field290 << 18) >> 16);
            command.field14 = (command.field14 & 0xffff0000) |
                              (((u32)state->owner->field258 << 16) >> 16);
            command.hit18 = queryHit;
            if ((((struct CollisionHit *)queryHit)->flags08 & 1) != 0 &&
                Ov107_AiState_ApplyHit(target, state->owner->field25c,
                                    &command) != 0) {
                func_ov107_020c0b90(state->owner, 0, *state->position, 0);
                Ov107_BuildAndSendUpdate(state->owner, 0, 0x53, state->position);
                state->owner->state1c7 = 0;
                SetIndexedSlot(node, node->action, 0);
                return;
            }
        }
    }

    {
        struct CollisionResult *result;

        VEC_Subtract(state->position, &state->previousPosition, &movement);
        state->previousPosition = *state->position;
        ray = movement;
        ray.y -= origin.w;

        if (Collision_CastRay(*(void **)((char *)collisionOwner + 0x7c),
                            state->position, &ray) != 0) {
            func_ov107_020c0b90(state->owner, 1, *state->position, 0);
            state->owner->state1c7 = 0;
            SetIndexedSlot(node, node->action, 0);
            return;
        }

        result = Collision_CastSphereEx(*(void **)((char *)collisionOwner + 0x7c),
                               state->position, &movement, 0x300, 0);
        if (result != 0 && result->field08 == 0) {
            func_ov107_020c0b90(state->owner, 1, *state->position, 0);
            state->owner->state1c7 = 0;
            SetIndexedSlot(node, node->action, 0);
            return;
        }

        state->travel += VEC_Mag(&movement);
        if (state->travel < 0x15000 && (state->owner->aux390->flags1c4 & 0xa) == 0) {
            return;
        }
        if ((state->owner->aux390->flags1c4 & 0xa) == 0) {
            func_ov107_020c0b90(state->owner, 1, *state->position, 0);
        }
        state->owner->state1c7 = 0;
        SetIndexedSlot(node, node->action, 0);
    }
}




