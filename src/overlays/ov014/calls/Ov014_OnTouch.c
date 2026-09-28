/* Unless busy or a HUD panel is open, records the touch and marks the element. */

typedef struct {
    char pad[0x134];
    signed char state;
} Ov014Object;

extern int Ov002_Hud_IsPanelOpen(void);
extern int Ov002_RecordElementHit(Ov014Object *self, unsigned char *record, int size);

int Ov014_OnTouch(Ov014Object *self, unsigned char *value)
{
    unsigned char record[6];

    if (self->state != 0) {
        return 0;
    }
    if (Ov002_Hud_IsPanelOpen() != 0) {
        return 0;
    }

    record[0] = 1;
    record[4] = *value;
    Ov002_RecordElementHit(self, record, 6);
    self->state = 1;
    return 0;
}
