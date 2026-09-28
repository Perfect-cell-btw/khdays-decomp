/* Refreshes the shared panel for the indexed player's entry when it exists. */

extern int GetEntryField20ByIndex();
extern void Ov022_RefreshSharedPanel();
void Ov022_CleanupEntry(int arg0) {
    int e = GetEntryField20ByIndex(arg0);
    if (e != 0) Ov022_RefreshSharedPanel(e);
}
