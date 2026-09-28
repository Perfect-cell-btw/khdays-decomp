/* Returns the indexed player's group (+0x66), or -1 when the player has no entry. */

extern int GetEntryField20ByIndex();
int Ov022_GetEntryField66(int arg0) {
    int e = GetEntryField20ByIndex(arg0);
    return e == 0 ? -1 : *(short *)(e + 0x66);
}
