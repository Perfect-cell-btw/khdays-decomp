/* Ov253_DrawListRemove -- draw list removal: handles the +0x460 single, the four +0x458 parts and the
 * eight +0x45c parts (020c2b20), then the base removal (020c7b70). */
struct Ov253Actor { char pad[0x458]; int *parts4; int *parts8; int single; };

extern void Ov107_InitObjectFromSource(int list, int item);
extern void Ov107_HandleRegionEvent(struct Ov253Actor *self, int list);

void Ov253_DrawListRemove(struct Ov253Actor *self, int list) {
    int i;

    Ov107_InitObjectFromSource(list, self->single);
    for (i = 0; i < 4; i++) {
        Ov107_InitObjectFromSource(list, self->parts4[i]);
    }
    for (i = 0; i < 8; i++) {
        Ov107_InitObjectFromSource(list, self->parts8[i]);
    }
    Ov107_HandleRegionEvent(self, list);
}
