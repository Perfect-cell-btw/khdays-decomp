/* Same routine as the ov157 function of this name; see it for the details. */

extern void CreateRegistryEntry();
extern void Ov285_AiStateInit();

void Ov285_CreateRegistryEntryAndLink(int this_) {
    int out;
    CreateRegistryEntry(*(int *)(this_ + 0x3c), 0x64, 0x30, (int)&Ov285_AiStateInit, 0, &out);
    *(int *)out = this_;
    *(int *)(this_ + 0x214) = out;
}
