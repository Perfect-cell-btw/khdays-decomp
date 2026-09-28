/* Maps a state-transition code to the character's animation variant (0x2e rebinds the arm,
 * 0x2f/0x33 and 0x30/0x31 pick the variant flag), applies it and keeps 0x33 as the current code
 * when asked. */

extern void BindAnimTrack();
extern void Ov071_BindDefaultAnimsIfIdle();
extern void Ov022_SetAnimState();

void Ov071_dispatchStateTransitionCode(void *this, int code)
{
    char *base = (char *)this + 0x2c2c;
    int flag = -1;
    switch (code) {
    case 0x2e:
        BindAnimTrack((char *)this + 0xf10, 1, (char *)this + 0xff0, 1);
        if (*(int *)((char *)this + 0x6bc) != code) {
            Ov071_BindDefaultAnimsIfIdle(this, base);
        }
        break;
    case 0x2f:
    case 0x33:
        if (code == 0x33) {
            *(int *)(base + 4) = 1;
            flag = 0x33;
        } else {
            *(int *)(base + 4) = 0;
        }
        code = 0x2f;
        break;
    case 0x31:
        *(int *)(base + 4) = 1;
        break;
    case 0x30:
        *(int *)(base + 4) = 0;
        break;
    }
    Ov022_SetAnimState(this, code);
    if (flag >= 0) {
        *(int *)((char *)this + 0x6bc) = 0x33;
    }
}
