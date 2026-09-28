extern void Ov063_BindPartRigs(void *this);
extern void Ov063_StartAnimTracks(void *this);
extern void Ov063_InitMoveParams(void *this);

void Ov063_handleCommand(char *this, int cmd) {
    char *g = *(char **)(this + 0xdb4);
    switch (cmd) {
    case 0x2e:
        if (*(int *)(g + 0x6bc) == cmd) return;
        Ov063_BindPartRigs(this);
        return;
    case 0x2f:
        if (*(int *)(g + 0x6bc) == cmd) return;
        *(int *)(this + 8) = 1;
        Ov063_StartAnimTracks(this);
        return;
    case 0x30:
        *(int *)this = 1;
        if (*(int *)(g + 0x6bc) == cmd) return;
        Ov063_StartAnimTracks(this);
        Ov063_InitMoveParams(this);
        return;
    }
}
