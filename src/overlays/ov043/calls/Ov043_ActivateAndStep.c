extern void Ov043_RebindAnimTracks(int obj, int arg);
/* Mark the actor as active (+0x11c = 1), clear its timer (+0x120) and tail-call the entry step. */
void Ov043_ActivateAndStep(int unused, int obj) {
    *(int *)(obj + 0x11c) = 1;
    *(int *)(obj + 0x120) = 0;
    Ov043_RebindAnimTracks(obj, 0);
}
