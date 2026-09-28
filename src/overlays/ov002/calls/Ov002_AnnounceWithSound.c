extern int Ov002_AnnounceSelection();
extern int PlaySoundChecked();

void Ov002_AnnounceWithSound(int arg0, int arg1) {
    Ov002_AnnounceSelection(arg0);
    if (arg1 == 0) {
        return;
    }
    PlaySoundChecked(0, 0x11);
}
