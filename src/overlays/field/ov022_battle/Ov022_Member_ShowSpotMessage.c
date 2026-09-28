/* For the local member shows the spot's message (with a sound) and arms its timer. */

#include "nitro/types.h"

typedef struct Ov022RosterRow {
    void *owner00;
    char padding004[0x06];
    u8 playerIndex0a;
    char padding00b;
} Ov022RosterRow;

typedef struct Ov022EntryRoot {
    int flags00;
    Ov022RosterRow rows04[4];
    char padding034[0x09];
    s8 activeSpot3d;
    char padding03e[0x02];
    int spotTimer40;
} Ov022EntryRoot;

typedef struct Ov022EntrySystem {
    int callback00;
    Ov022EntryRoot *root04;
} Ov022EntrySystem;

extern Ov022EntrySystem data_ov022_020b2e78;

extern unsigned int Session_GetLocalPlayerIndex(void);
extern void PlaySoundChecked(int bank, int sound);
extern void Ov002_AnnounceWithSound(int resourceId, int enabled);

void Ov022_Member_ShowSpotMessage(int index, unsigned int resourceId, int spot)
{
    Ov022EntryRoot *root;

    root = data_ov022_020b2e78.root04;
    if (root == 0) {
        return;
    }

    if (data_ov022_020b2e78.root04->rows04[index].playerIndex0a !=
        Session_GetLocalPlayerIndex()) {
        return;
    }

    if (spot != root->activeSpot3d) {
        PlaySoundChecked(0, 4);
        Ov002_AnnounceWithSound((u16)resourceId, 0);
        root->activeSpot3d = (s8)spot;
    } else if (resourceId == 0xffff) {
        PlaySoundChecked(0, 4);
    }

    root->spotTimer40 = 0x1e000;
}
