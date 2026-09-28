/* Records a movie request and, when the player is waiting, starts it. */

extern int data_ov012_0205cb20;
extern void Ov024_MobiClip_KickPlayerSlot();

void Ov012_SubmitRequestIfIdle(int arg0, int arg1) {
    char *base = (char *)(data_ov012_0205cb20 + 0x8000);
    *(int *)(base + 0xbe4) = arg1;
    *(int *)(base + 0xbe8) = -1;
    *(unsigned char *)(base + 0xbe2) = (unsigned char)arg0;
    if (*(int *)(base + 0xbdc) != 1) return;
    *(int *)(base + 0xbdc) = 2;
    Ov024_MobiClip_KickPlayerSlot(0);
}
