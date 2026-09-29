/* Plays the surprised cue and anim 0xd, then installs the rolling charge start. */

#include "nitro/types.h"
#include "game/ai_task.h"

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
    AI_TASK_FIELDS(Ov236Node)
} Ov236Actor;

extern void Ov107_PostTagUpdate(Ov236CueObject *object, int mode, int flag);
extern void SetIndexedSlot(Ov236Actor *self, int index, void *callback);
extern Ov236CueTable data_ov278_020d6374;
extern void Ov278_AiStartRollingCharge(void);

void Ov278_AiEnterSurprised(Ov236Actor *self) {
    Ov236Node *node = self->pState;
    Ov236Cue cue;
    Ov236CueCallback playCue;

    cue = data_ov278_020d6374.surprisedCue;
    playCue = node->object->playCue;
    if (playCue != 0) {
        playCue(node->object, &cue, sizeof(cue));
    }
    Ov107_PostTagUpdate(node->object, 0xd, 0);
    SetIndexedSlot(self, self->slot, &Ov278_AiStartRollingCharge);
}
