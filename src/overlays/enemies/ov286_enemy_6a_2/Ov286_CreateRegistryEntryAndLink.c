/* Same routine as the ov157 function of this name; see it for the details. */

extern void CreateRegistryEntry();
extern void Ov286_AiStateInit();

void Ov286_CreateRegistryEntryAndLink(int this_) {
    int out;
    CreateRegistryEntry(*(int *)(this_ + 0x3c), 0x64, 0x30, (int)&Ov286_AiStateInit, 0, &out);
    *(int *)out = this_;
    *(int *)(this_ + 0x214) = out;
}
