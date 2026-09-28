/* Returns the value (+8) of the current cue entry. */

extern char *Ov002_GetCueEntry(int);
int Ov002_GetCueEntryValue(int arg0)
{
    return *(int *)(Ov002_GetCueEntry(arg0) + 8);
}
