/* Poll one request bit of the global flag word (data_0204c190 bit 3).
 * When game flag 0x2483 is set, give ov023 first refusal on the request
 * (Ov023_StepDialog); if it declines, play sound 4 and drop the request.
 * Otherwise latch the request in the halfword at data_0204be08+2 -- playing
 * sound 1 only on the transition from 0 -- and post event 0x12. */
extern unsigned short data_0204c190;
extern unsigned short data_0204be08;
extern unsigned short data_0204be0a;

extern int GameState_IsFlagSet(int flag);
extern int Ov023_StepDialog(void);
extern void PlaySoundChecked(int a, int b);
extern void PlaySound(int a, int b);
extern short func_02031384(int a, void *b, int c);

void PollAndLatchRequest(void) {
    if ((data_0204c190 & 8) == 0) return;

    if (GameState_IsFlagSet(0x2483) != 0) {
        if (Ov023_StepDialog() == 0) {
            PlaySoundChecked(0, 4);
        }
        return;
    }

    if ((&data_0204be08)[1] == 0) {
        PlaySound(0, 1);
    }
    (&data_0204be08)[1] = 1;
    func_02031384(0x12, &data_0204be0a, 2);
}
