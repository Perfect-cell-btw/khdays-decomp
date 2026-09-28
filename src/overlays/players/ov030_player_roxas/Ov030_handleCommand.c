extern void Ov030_BindPartRigs(void *this);
extern void Ov030_StartAnimTracks(void *this);
extern void Ov030_InitMoveParams(void *this);

void Ov030_handleCommand(char *this, int cmd) {
    char *g = *(char **)(this + 0xdb4);
    switch (cmd) {
    case 0x2e:
        if (*(int *)(g + 0x6bc) == cmd) return;
        Ov030_BindPartRigs(this);
        return;
    case 0x2f:
        if (*(int *)(g + 0x6bc) == cmd) return;
        *(int *)(this + 8) = 1;
        Ov030_StartAnimTracks(this);
        return;
    case 0x30:
        *(int *)this = 1;
        if (*(int *)(g + 0x6bc) == cmd) return;
        Ov030_StartAnimTracks(this);
        Ov030_InitMoveParams(this);
        return;
    }
}
