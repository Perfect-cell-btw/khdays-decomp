/* Announce the object's state. In a session that is a 6-byte message 3 carrying
 * the state byte from +0x3f; solo, there is nobody to tell, so the state is just
 * written straight to +0x2c. */

#include "game/engine.h"

extern void Ov002_RecordElementHit(void *self, void *message, int size);

typedef struct {
    char pad0000[0x2c];
    unsigned char bLocalState;  /* +0x2c */
    char pad002d[0x12];
    unsigned char bState;       /* +0x3f */
} Ov002Announcer;

void Ov002_AnnounceState(Ov002Announcer *self) {
    unsigned char message[8];

    if (Session_IsActive() != 0) {
        self->bLocalState = 4;
        return;
    }

    message[0] = 3;
    message[4] = self->bState;
    Ov002_RecordElementHit(self, message, 6);
}
