extern int data_ov002_0207f9f0;
extern int Ov002_SwitchSlotCues();

void Ov002_SwitchSlotCuesIfActive(int arg0) {
    if (*(int *)&data_ov002_0207f9f0 != 0) {
        Ov002_SwitchSlotCues(arg0, 1);
    }
}
