/* Starts the timed effect (state 1, timer cleared) and plays the character's attack voice, keeping
 * its handle. */

extern int data_ov077_020b9b80;
extern int Ov022_PlayEntityVoice();

void Ov077_EnterStateAndPlayVoice(int a, int *ctx) {
    int *row = (int *)(*(int *)&data_ov077_020b9b80 + 0x2c + 0x2c00);
    ctx[0x43] = 0;
    ctx[0] = 1;
    row[0x154] = Ov022_PlayEntityVoice(a, 0xc8, 5);
}
