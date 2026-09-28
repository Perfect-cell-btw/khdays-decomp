/* Bind channels 0, 2, 4 and 1 of both +0x384 rider rigs to (mode, flag) and re-init them. */
struct Riders { char pad[0x384]; int rider[2]; };

extern void SetSubitemState(int item, int channel, short a, int b);
extern void RefreshObjectCallbacks(int item, int a);

void Ov254_BindRiderChannels(char *self, int mode, int flag)
{
    int i;

    for (i = 0; i < 2; i++) {
        SetSubitemState(((struct Riders *)self)->rider[i], 0, mode, flag);
        SetSubitemState(((struct Riders *)self)->rider[i], 2, mode, flag);
        SetSubitemState(((struct Riders *)self)->rider[i], 4, mode, flag);
        SetSubitemState(((struct Riders *)self)->rider[i], 1, mode, flag);
        RefreshObjectCallbacks(((struct Riders *)self)->rider[i], 0);
    }
}
