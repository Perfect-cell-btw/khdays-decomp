/* Message handler of an ov254 helper: on channel-5 messages it attaches effects to the +0x4e8
 * pairs (kind 0x17 at the message's position for slots 0-2, 4 and 6; kind 0x17 on the +0x40c /
 * +0x410 part for slots 7 / 3; kind 5 on its own +0xa0 pose for slot 5, message byte 4 as the
 * variant), knocks itself back in place (0xa), attaches / releases the +0x4e4 sound 0x16d (0xb /
 * 0xc) or forwards byte 4 to the camera's +0x78 handler (0xd); then the base handler runs. */
typedef unsigned char u8;
struct Pairs { char pad[0x4e8]; struct { int res; int handle; } pair[1]; };

extern int Ov107_CreateNodeXformTaskFx24(int model, int res, int kind, int arg, int scale, void *pos);
extern int Ov107_CreateNodeBodyTask(int model, int res, int kind, void *at, int a, int b);
extern void Ov107_ForwardVisibleEvent(char *self, int a);
extern int Ov107_CreateSpawnTask(char *self, int id, int mode, int flag, void *pose);
extern void Ov107_UnlinkNodeFromOwner(int sub);
extern int func_ov107_020c9848();
extern int func_ov022_02083f0c(void);
extern void Ov107_AiState_OnMessage(char *self, u8 *msg, int arg);

void Ov254_HelperCHandleMessage(char *self, u8 *msg, int arg)
{
    int obj;

    if (msg[2] == 5) {
        switch (msg[3]) {
        case 0:
        case 1:
        case 2:
        case 4:
        case 6:
            ((struct Pairs *)self)->pair[msg[3]].handle =
                Ov107_CreateNodeXformTaskFx24(*(int *)(self + 0x3c), ((struct Pairs *)self)->pair[msg[3]].res, 0x17, 0, 0x1000, msg + 5);
            break;
        case 3:
        case 7:
            ((struct Pairs *)self)->pair[msg[3]].handle =
                Ov107_CreateNodeBodyTask(*(int *)(self + 0x3c), ((struct Pairs *)self)->pair[msg[3]].res, 0x17,
                                    (void *)(((int *)(self + 0x40c))[msg[3] != 7] + 4), 0, 0);
            break;
        case 5:
            ((struct Pairs *)self)->pair[msg[3]].handle =
                Ov107_CreateNodeBodyTask(*(int *)(self + 0x3c), ((struct Pairs *)self)->pair[msg[3]].res, 5,
                                    self + 0xa0, msg[4], msg[4] == 1);
            break;
        case 0xa:
            Ov107_ForwardVisibleEvent(self, 1);
            break;
        case 0xb:
            *(int *)(self + 0x4e4) = Ov107_CreateSpawnTask(self, 0x16d, 0x14, 1, self + 0xa0);
            break;
        case 0xc:
            if (*(int *)(self + 0x4e4) != 0) {
                Ov107_UnlinkNodeFromOwner(*(int *)(self + 0x4e4));
                *(int *)(self + 0x4e4) = 0;
            }
            break;
        case 0xd:
            if (*(int *)(func_ov107_020c9848() + 0x78) != 0) {
                obj = func_ov107_020c9848();
                (*(void (**)(int, int, int))(obj + 0x78))(func_ov022_02083f0c(), msg[4], 0);
            }
            break;
        }
    }
    Ov107_AiState_OnMessage(self, msg, arg);
}
