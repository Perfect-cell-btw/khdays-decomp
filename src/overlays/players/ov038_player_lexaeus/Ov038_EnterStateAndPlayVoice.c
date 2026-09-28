extern int data_ov038_020b4ca0;
extern int Ov022_PlayEntityVoice();

void Ov038_EnterStateAndPlayVoice(int a, int *ctx) {
    int *row = (int *)(*(int *)&data_ov038_020b4ca0 + 0x2c + 0x2c00);
    ctx[0x43] = 0;
    ctx[0] = 1;
    row[0x154] = Ov022_PlayEntityVoice(a, 0xc8, 5);
}
