extern void SetSubitemState();
extern void RefreshObjectCallbacks();

struct bit0 { unsigned char b : 1; };

void Ov240_ApplyActorConfig310(int this_) {
    SetSubitemState(*(int *)(this_ + 0x388), 0,
                  *(signed char *)(this_ + 0x310),
                  ((struct bit0 *)(this_ + 0x311))->b);
    RefreshObjectCallbacks(*(int *)(this_ + 0x388), 0);
}
