extern int Session_IsActive(void);
extern int Ov002_IsSessionOpen(void);
extern int Ov014_IsPlayerInRange(void *self);
extern int QueryActiveStateOrDelegate(void);
extern int GetEntryField20ByIndex(int index);
extern void func_ov022_020ad2e4(int arg0, int arg1);
extern void Ov014_ActorRelease(int this_);
extern void Ov002_RebindAnimTracks(short *pAnim, int nBlend, int nFrame);
extern void Scene_DrawNode(void *object);
extern int Ov014_ForwardIfFlag4Set(int this_);

void *Ov014_Element_Tick(void *self)
{
    void *next = 0;
    int state;

    if (Session_IsActive() == 0 && (*(unsigned short *)((char *)self + 0x12) & 2) == 0)
        return 0;

    if (Ov002_IsSessionOpen() != 0 && Ov014_IsPlayerInRange(self) != 0) {
        func_ov022_020ad2e4(GetEntryField20ByIndex(QueryActiveStateOrDelegate()), 1);
    }

    state = *(signed char *)((char *)self + 0x134);
    if (state != 2) {
        if (state == 3)
            next = (void *)&Ov014_ForwardIfFlag4Set;
    } else {
        Ov014_ActorRelease((int)self);
        if (*(unsigned short *)((char *)self + 0x12) & 4)
            Ov002_RebindAnimTracks((short *)((char *)self + 0x2c),
                                *(signed char *)((char *)self + 0x135), 0);
        next = (void *)&Ov014_ForwardIfFlag4Set;
    }

    if (*(unsigned short *)((char *)self + 0x12) & 4)
        Scene_DrawNode((char *)self + 0x2c);
    return next;
}
