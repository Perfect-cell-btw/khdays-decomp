/* Plays the surprised cue and anim 0xd, then installs the rolling charge start. */

#include "nitro/types.h"

typedef struct {
    u16 soundId;
    u16 parameter;
} Ov236Cue;

typedef struct {
    u16 pad_0000[4];
    Ov236Cue surprisedCue;
} Ov236CueTable;

typedef struct Ov236CueObject Ov236CueObject;
typedef void (*Ov236CueCallback)(Ov236CueObject *object, Ov236Cue *cue, int size);

struct Ov236CueObject {
    u8 pad_0000[0x24];
    Ov236CueCallback playCue;
};

typedef struct {
    Ov236CueObject *object;
} Ov236Node;

typedef struct {
    u8 pad_0000[4];
    Ov236Node *node;
    u8 pad_0008[0x20 - 8];
    s8 scriptSlot;
} Ov236Actor;

extern void Ov107_PostTagUpdate(Ov236CueObject *object, int mode, int flag);
extern void SetIndexedSlot(Ov236Actor *self, int index, void *callback);
extern Ov236CueTable data_ov236_020d63c0;
extern void Ov236_AiStartRollingCharge(void);

void Ov236_AiEnterSurprised(Ov236Actor *self) {
    Ov236Node *node = self->node;
    Ov236Cue cue;
    Ov236CueCallback playCue;

    cue = data_ov236_020d63c0.surprisedCue;
    playCue = node->object->playCue;
    if (playCue != 0) {
        playCue(node->object, &cue, sizeof(cue));
    }
    Ov107_PostTagUpdate(node->object, 0xd, 0);
    SetIndexedSlot(self, self->scriptSlot, &Ov236_AiStartRollingCharge);
}
