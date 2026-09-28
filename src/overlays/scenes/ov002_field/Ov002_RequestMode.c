/* Marks a mode as pending in the root context and announces it with its sound (0x1c2 + mode, capped
 * at 2). */

typedef struct {
    unsigned char bPending;
    unsigned char pad01[3];
} Ov002ModeRecord;

typedef struct {
    unsigned char pad0000[0x8d4e];
    Ov002ModeRecord aModes[3];
} Ov002RootContext;

extern Ov002RootContext *data_ov002_0207fa00;
extern void Ov002_AnnounceWithSound(int resourceId, int enabled);

void Ov002_RequestMode(int mode)
{
    Ov002RootContext *root = data_ov002_0207fa00;

    root->aModes[mode].bPending = 1;

    if (mode > 2) {
        mode = 2;
    }

    Ov002_AnnounceWithSound((unsigned short)(mode + 0x1c2), 1);
}
