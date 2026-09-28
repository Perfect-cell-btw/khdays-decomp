extern int Ov002_GetCtxTableByte(int slot);
extern int QueryActiveStateOrDelegate(void);
extern char *GetEntryField20ByIndex(int);
extern int VEC_Distance(void *a, void *b);

typedef struct { int x, y, z; } Ov002Vec3;

/* True when the player is within this actor's trigger radius and belongs to the same model. */
int Ov002_IsPlayerInTriggerRadius(char *self) {
    char *player;
    int id;
    Ov002Vec3 pos;
    player = GetEntryField20ByIndex(QueryActiveStateOrDelegate());
    if (player == 0) {
        return 0;
    }
    id = *(short *)(player + 0x66);
    if (id != Ov002_GetCtxTableByte((unsigned char)self[0x10])) {
        return 0;
    }
    pos = *(Ov002Vec3 *)(player + 0x48c);
    return *(int *)(self + 0x44) >= VEC_Distance(self + 0x1c, &pos);
}
