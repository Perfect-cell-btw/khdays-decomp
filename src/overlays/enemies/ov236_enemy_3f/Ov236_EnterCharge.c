/* Charge entry: plays the charge cue (data_ov236_020d63c0 entry 1) through the object's cue
 * callback when set, spawns effect 0x127 (kind 6) at the +0x38 anchor, plays pose 4 and moves
 * the node to 020d046c. */
typedef signed char s8;
typedef unsigned char u8;
typedef unsigned short u16;

typedef struct {
    u16 soundId;
    u16 parameter;
} Ov236Cue;

typedef struct {
    u16 pad_0000[2];
    Ov236Cue chargeCue;
} Ov236CueTable;

typedef struct Ov236CueObject Ov236CueObject;
typedef void (*Ov236CueCallback)(Ov236CueObject *object, Ov236Cue *cue, int size);

struct Ov236CueObject {
    u8 pad_0000[0x24];
    Ov236CueCallback playCue;
};

typedef struct {
    Ov236CueObject *object;
    u8 pad_0004[0x34];
    void *anchor;
} Ov236Node;

typedef struct {
    u8 pad_0000[4];
    Ov236Node *node;
    u8 pad_0008[0x20 - 8];
    s8 scriptSlot;
} Ov236Actor;

extern void Ov107_BuildAndSendUpdate(Ov236CueObject *object, int id, int kind, void *anchor);
extern void Ov107_PostTagUpdate(Ov236CueObject *object, int mode, int flag);
extern void SetIndexedSlot(Ov236Actor *self, int index, void *callback);
extern Ov236CueTable data_ov236_020d63c0;
extern void Ov236_AiReleaseRidersOnAnimEnd(void);

void Ov236_EnterCharge(Ov236Actor *self) {
    Ov236Node *node = self->node;
    Ov236Cue cue;
    Ov236CueCallback playCue;

    cue = data_ov236_020d63c0.chargeCue;
    playCue = node->object->playCue;
    if (playCue != 0) {
        playCue(node->object, &cue, sizeof(cue));
    }
    Ov107_BuildAndSendUpdate(node->object, 0x127, 6, node->anchor);
    Ov107_PostTagUpdate(node->object, 4, 0);
    SetIndexedSlot(self, self->scriptSlot, &Ov236_AiReleaseRidersOnAnimEnd);
}
