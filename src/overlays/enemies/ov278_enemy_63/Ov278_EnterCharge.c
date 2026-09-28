/* Charge entry: plays the charge cue (data_ov278_020d6374 entry 1) through the object's cue
 * callback when set, spawns effect 0x166 (kind 6) at the +0x38 anchor, plays pose 4 and moves
 * the node to 020d046c. */
#include "nitro/types.h"

typedef struct {
    u16 soundId;
    u16 parameter;
} Ov278Cue;

typedef struct {
    u16 pad_0000[2];
    Ov278Cue chargeCue;
} Ov278CueTable;

typedef struct Ov278CueObject Ov278CueObject;
typedef void (*Ov278CueCallback)(Ov278CueObject *object, Ov278Cue *cue, int size);

struct Ov278CueObject {
    u8 pad_0000[0x24];
    Ov278CueCallback playCue;
};

typedef struct {
    Ov278CueObject *object;
    u8 pad_0004[0x34];
    void *anchor;
} Ov278Node;

typedef struct {
    u8 pad_0000[4];
    Ov278Node *node;
    u8 pad_0008[0x20 - 8];
    s8 scriptSlot;
} Ov278Actor;

extern void Ov107_BuildAndSendUpdate(Ov278CueObject *object, int id, int kind, void *anchor);
extern void Ov107_PostTagUpdate(Ov278CueObject *object, int mode, int flag);
extern void SetIndexedSlot(Ov278Actor *self, int index, void *callback);
extern Ov278CueTable data_ov278_020d6374;
extern void Ov278_AiReleaseRidersOnAnimEnd(void);

void Ov278_EnterCharge(Ov278Actor *self) {
    Ov278Node *node = self->node;
    Ov278Cue cue;
    Ov278CueCallback playCue;

    cue = data_ov278_020d6374.chargeCue;
    playCue = node->object->playCue;
    if (playCue != 0) {
        playCue(node->object, &cue, sizeof(cue));
    }
    Ov107_BuildAndSendUpdate(node->object, 0x166, 6, node->anchor);
    Ov107_PostTagUpdate(node->object, 4, 0);
    SetIndexedSlot(self, self->scriptSlot, &Ov278_AiReleaseRidersOnAnimEnd);
}
