/* Kick anim 4, set bit 0 of the +0x3b4 status byte, then dispatch. */
extern int Ov107_PostTagUpdate(int, int, int);
extern int SetIndexedSlot(int, int, void *);
struct b8 { unsigned int f : 8; };
extern int Ov253_TauntTick(int);
void Ov253_AiEnterTaunt(int param_1) {
    int owner = *(int *)(param_1 + 4);
    Ov107_PostTagUpdate(*(int *)owner, 4, 0);
    ((struct b8 *)(*(int *)(*(int *)owner + 0x3b4) + 8))->f |= 1;
    SetIndexedSlot(param_1, *(signed char *)(param_1 + 0x20), (void *)&Ov253_TauntTick);
}
