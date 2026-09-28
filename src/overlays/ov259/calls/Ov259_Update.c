/* Update of the ov259 actor (+0xc): the +0x414 partner updates (020c9ec8), then the base update
 * (020c6980), the move hook for the current move (020cc134) and both placements (the +0x404 slot's
 * shape and the +0x408 shape) take the +0xa0 transform. */
typedef struct { int m[11]; } Srt;
struct Piece { char pad[0x10]; Srt srt; };

extern void Ov107_RefreshAndSelectChild(int part);
extern void Ov107_ProcessObjectTick(char *self, int arg);
extern void Ov259_MoveHook(char *self, int move);

void Ov259_Update(char *self, int arg)
{
    Ov107_RefreshAndSelectChild(*(int *)(self + 0x414));
    Ov107_ProcessObjectTick(self, arg);
    Ov259_MoveHook(self, *(signed char *)(self + 0x100 + 0xc6));
    ((struct Piece *)**(int **)(self + 0x404))->srt = *(Srt *)(self + 0xa0);
    ((struct Piece *)*(int *)(self + 0x408))->srt = *(Srt *)(self + 0xa0);
}
