/* Handles a character command: 0x2e binds the part rigs, 0x2f starts the animation tracks, 0x30
 * starts them and sets up the move parameters; a command equal to the current one is ignored. */

extern void Ov082_BindPartRigs(void *this);
extern void Ov082_StartAnimTracks(void *this);
extern void Ov082_InitMoveParams(void *this);

void Ov082_handleCommand(char *this, int cmd) {
    char *g = *(char **)(this + 0xdb4);
    switch (cmd) {
    case 0x2e:
        if (*(int *)(g + 0x6bc) == cmd) return;
        Ov082_BindPartRigs(this);
        return;
    case 0x2f:
        if (*(int *)(g + 0x6bc) == cmd) return;
        *(int *)(this + 8) = 1;
        Ov082_StartAnimTracks(this);
        return;
    case 0x30:
        *(int *)this = 1;
        if (*(int *)(g + 0x6bc) == cmd) return;
        Ov082_StartAnimTracks(this);
        Ov082_InitMoveParams(this);
        return;
    }
}
