/* Apply a mode change to the ov048 enemy (x4: ov048/067/086/103). `mode - 0x2e` selects the
 * setup arm: 0x2e runs the idle setup, 0x2f the rig setup, 0x30/0x31 nothing, and 0x32/0x33 (the
 * attack pair) reset the rig's alternate flag (1 for 0x33), run the attack setup and the rig
 * setup, then hand mode 0x2f down while caching the real mode at +0x6bc. Every arm no-ops when
 * the mode did not change. */
extern void Ov103_InitTwoGlobalChannelSlots(char *self);
extern void Ov103_Activate(char *self, char *rig);
extern void Ov103_PlayVoiceAndBindThreeAnims(char *self, char *rig);
extern void Ov103_Deactivate(char *self, char *rig);
extern void Ov022_SetAnimState(char *self, int mode);
extern char *data_ov103_020bc120;

void Ov103_ApplyMode(char *self, int mode)
{
    char *rig = data_ov103_020bc120 + 0x2c + 0x2c00;
    int reached = -1;

    switch (mode - 0x2e) {
    case 0:
        if (*(int *)(self + 0x6bc) != mode) {
            Ov103_InitTwoGlobalChannelSlots(self);
        }
        break;
    case 1:
        if (*(int *)(self + 0x6bc) != mode) {
            Ov103_Activate(self, rig);
        }
        break;
    case 2:
        break;
    case 3:
        break;
    case 4:
    case 5:
        if (*(int *)(self + 0x6bc) != mode) {
            *(int *)rig = 0;
            if (mode == 0x33) {
                *(int *)rig = 1;
            }
            Ov103_PlayVoiceAndBindThreeAnims(self, rig);
            Ov103_Deactivate(self, rig);
        }
        reached = mode;
        mode = 0x2f;
        break;
    }
    Ov022_SetAnimState(self, mode);
    if (reached >= 0) {
        *(int *)(self + 0x6bc) = reached;
    }
}
