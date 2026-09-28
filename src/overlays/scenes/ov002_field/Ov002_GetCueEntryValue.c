/* Returns the value (+8) of the current cue entry. */

extern char *Ov002_GetCueEntry(void);
int Ov002_GetCueEntryValue(void)
{
    return *(int *)(Ov002_GetCueEntry() + 8);
}
