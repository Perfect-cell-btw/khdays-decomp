/* Retire the widget: while its flag bit 2 is set, stop the sub-node at +0x3c
 * (only when the owner's byte at +0x58 says it was started) and post event 0x5d
 * with the payload at +0xe0. Either way the state byte at +0x1b4 goes to 5 and
 * the word at +0x1b0 is cleared. */
extern void Ov002_RebindAnimTracks(void *node, int a, int b);
extern void SceneNode_Enable(void *node);
extern void Slot_Spawn(int a, int event, void *payload, int b);

void Ov002_RetireWidget(char *self) {
    char *owner = *(char **)(self + 8);

    if (*(unsigned short *)(self + 0x12) & 4) {
        if (owner[0x58] != 0) {
            Ov002_RebindAnimTracks(self + 0x3c, 1, 0);
            SceneNode_Enable(self + 0x3c);
        }
        Slot_Spawn(0, 0x5d, self + 0xe0, 0);
    }

    *(unsigned char *)(self + 0x1b4) = 5;
    *(int *)(self + 0x1b0) = 0;
}
