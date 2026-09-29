/* Announces the selection, optionally playing sound 0x11. */

#include "game/engine.h"

extern int Ov002_AnnounceSelection();

void Ov002_AnnounceWithSound(int arg0, int arg1) {
    Ov002_AnnounceSelection(arg0, arg1);
    if (arg1 == 0) {
        return;
    }
    PlaySoundChecked(0, 0x11);
}
