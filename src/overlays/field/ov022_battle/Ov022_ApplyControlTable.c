/* Runs an object's control word: notifies a peer hit, queues a point (or parks the value) for the
 * local side, or plays the control record its selector picks from the actor's table. */

#include "game/engine.h"

extern void Ov022_NotifyPeerHit(unsigned int *base, int obj, int a, int b);
extern int Ov022_GetEntryField66(int state);
extern void Ov106_QueuePoint(int obj);
extern void Ov002_ParkValue(int obj);
extern void Ov022_PlayControlRecord(unsigned int *base, int value, int obj);

struct Ctl02091f8c {
    unsigned int kind : 2;
    unsigned int _pad02 : 3;
    unsigned int selector : 4;
    unsigned int _pad09 : 2;
    unsigned int valueA : 12;
    unsigned int valueB : 8;
    unsigned int _pad31 : 1;
};

void Ov022_ApplyControlTable(int obj) {
    struct Ctl02091f8c *control =
        (struct Ctl02091f8c *)(obj + 0x10);
    unsigned int *base = GetEntryField20ByIndex(control->kind);
    int raw = *(int *)control;
    unsigned int *table = base + 0x992;
    int state;

    switch (control->selector) {
    case 6:
        Ov022_NotifyPeerHit(base, obj, control->valueA, control->valueB);
        return;
    case 7:
        state = Ov022_GetEntryField66(QueryActiveStateOrDelegate());
        if (state != Ov022_GetEntryField66(*((unsigned char *)base + 9))) {
            return;
        }
        if (LoadGlobalU16At0() == 0x2a) {
            Ov106_QueuePoint(obj);
        } else {
            Ov002_ParkValue(obj);
        }
        return;
    case 8:
        if (table[1] == 0) {
            return;
        }
        Ov022_PlayControlRecord(base, table[1], obj);
        return;
    }

    if (table[control->selector] == 0) {
        return;
    }
    Ov022_PlayControlRecord(base, table[control->selector], obj);
}
