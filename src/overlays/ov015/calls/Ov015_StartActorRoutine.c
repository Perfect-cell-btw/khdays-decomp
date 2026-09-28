extern int Ov002_GetCtxTableByte(int slot);
extern void Ov015_ForEachPieceInSphere(int id, void *p, int arg, void *fn, void *self);
extern void Ov015_ChestPushPlayer(void);

/* Starts the actor's scripted routine with Ov015_ChestPushPlayer as its per-frame hook. */
void Ov015_StartActorRoutine(char *self, int arg) {
    Ov015_ForEachPieceInSphere(Ov002_GetCtxTableByte((unsigned char)self[0x10]), self + 0x488, arg,
                        (void *)&Ov015_ChestPushPlayer, self);
}
