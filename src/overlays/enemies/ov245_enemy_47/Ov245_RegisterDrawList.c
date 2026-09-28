/* Ov245_RegisterDrawList -- draw list registration: registers the actor's nine +0x3fc parts, the
 * three +0x420 parts, the four +0x42c..+0x438 singles and the three +0x43c parts on the draw
 * list (020c2b38), then the base registration (020c7c1c). */
struct Ov245Actor {
    char pad[0x3fc];
    int parts[9];
    int arms[3];
    int single42c;
    int single430;
    int single434;
    int single438;
    int tails[3];
};

extern void Ov107_InvokeSlot0x74(int list, int item);
extern void Ov107_Actor_DetachFromRegion(struct Ov245Actor *self, int list);

void Ov245_RegisterDrawList(struct Ov245Actor *self, int list) {
    int i;

    for (i = 0; i < 9; i++) {
        Ov107_InvokeSlot0x74(list, self->parts[i]);
    }
    for (i = 0; i < 3; i++) {
        Ov107_InvokeSlot0x74(list, self->arms[i]);
    }
    Ov107_InvokeSlot0x74(list, self->single42c);
    Ov107_InvokeSlot0x74(list, self->single430);
    Ov107_InvokeSlot0x74(list, self->single434);
    Ov107_InvokeSlot0x74(list, self->single438);
    for (i = 0; i < 3; i++) {
        Ov107_InvokeSlot0x74(list, self->tails[i]);
    }
    Ov107_Actor_DetachFromRegion(self, list);
}
