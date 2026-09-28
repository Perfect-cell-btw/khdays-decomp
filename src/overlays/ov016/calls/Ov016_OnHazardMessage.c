extern void Ov016_HazardSetState(void *self, int value, int flag);

void Ov016_OnHazardMessage(char *self, char *arg1) {
    if ((unsigned char)arg1[0] == 1) {
        Ov016_HazardSetState(self, *(int *)(arg1 + 4), 1);
    }
    self[0x2bc] = 0;
}
