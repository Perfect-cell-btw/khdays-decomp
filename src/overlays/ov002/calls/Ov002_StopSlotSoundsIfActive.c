/* Stops the slot's sounds when the sound bank is active. */

extern int data_ov002_0207f9f0;
extern int Ov002_StopSlotSounds();

void Ov002_StopSlotSoundsIfActive(int arg0) {
    if (*(int *)&data_ov002_0207f9f0 != 0) {
        Ov002_StopSlotSounds(arg0, 1);
    }
}
