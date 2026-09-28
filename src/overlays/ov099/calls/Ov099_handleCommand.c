extern void Ov099_BindPartRigs(void *this);
extern void Ov099_StartAnimTracks(void *this);
extern void Ov099_InitMoveParams(void *this);

void Ov099_handleCommand(char *this, int cmd) {
    char *g = *(char **)(this + 0xdb4);
    switch (cmd) {
    case 0x2e:
        if (*(int *)(g + 0x6bc) == cmd) return;
        Ov099_BindPartRigs(this);
        return;
    case 0x2f:
        if (*(int *)(g + 0x6bc) == cmd) return;
        *(int *)(this + 8) = 1;
        Ov099_StartAnimTracks(this);
        return;
    case 0x30:
        *(int *)this = 1;
        if (*(int *)(g + 0x6bc) == cmd) return;
        Ov099_StartAnimTracks(this);
        Ov099_InitMoveParams(this);
        return;
    }
}
