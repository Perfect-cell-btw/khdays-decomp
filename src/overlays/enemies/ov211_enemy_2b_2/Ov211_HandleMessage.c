/* Message handler of the ov210 enemy (x3 with ov211/ov282). A "spawned" message (kind 5)
 * attaches effects from the +0x3d0 pair table by its slot (byte 3): slot 1 spawns pairs 0 and 1
 * at the packed 0x5 position (kind 0x17, byte 4, scale 1.0); slots 3/6 spawn the pair named by
 * the low nibble of byte 4 with its high nibble; slots 2/7 anchor pairs 2/7 on the +0x9c body's
 * +0x30 point, slots 4/5 anchor pairs 4/5 on the +0x3c0/+0x3bc parts' +4 point; slot 8 starts
 * reaction 0x117 mode 7 on the actor's +0xa0 pose into +0x3d8. The base handler always runs. */
typedef unsigned char u8;

struct Pair { int res; int handle; };
struct Nib { u8 lo : 4, hi : 4; };

extern int Ov107_CreateNodeXformTaskFx24(int model, int res, int kind, int arg, int scale, void *pos);
extern int Ov107_CreateNodeBodyTask(int model, int res, int kind, void *at, int a, int b);
extern int Ov107_CreateSpawnTask(char *self, int id, int mode, int flag, void *pose);
extern void Ov107_AiState_OnMessage(char *self, u8 *msg, int arg);

void Ov211_HandleMessage(char *self, u8 *msg, int arg)
{
    if (msg[2] == 5) {
        switch (msg[3]) {
        case 1:
            (*(struct Pair **)(self + 0x3d0))[0].handle =
                Ov107_CreateNodeXformTaskFx24(*(int *)(self + 0x3c), (*(struct Pair **)(self + 0x3d0))[0].res, 0x17, msg[4], 0x1000, msg + 5);
            (*(struct Pair **)(self + 0x3d0))[1].handle =
                Ov107_CreateNodeXformTaskFx24(*(int *)(self + 0x3c), (*(struct Pair **)(self + 0x3d0))[1].res, 0x17, msg[4], 0x1000, msg + 5);
            break;
        case 3:
        case 6:
            (*(struct Pair **)(self + 0x3d0))[((struct Nib *)(msg + 4))->lo].handle =
                Ov107_CreateNodeXformTaskFx24(*(int *)(self + 0x3c), (*(struct Pair **)(self + 0x3d0))[((struct Nib *)(msg + 4))->lo].res, 0x17, ((struct Nib *)(msg + 4))->hi, 0x1000, msg + 5);
            break;
        case 2:
            (*(struct Pair **)(self + 0x3d0))[2].handle =
                Ov107_CreateNodeBodyTask(*(int *)(self + 0x3c), (*(struct Pair **)(self + 0x3d0))[2].res, 0x17, (void *)(*(int *)(self + 0x9c) + 0x30), 0, 0);
            break;
        case 4:
            (*(struct Pair **)(self + 0x3d0))[4].handle =
                Ov107_CreateNodeBodyTask(*(int *)(self + 0x3c), (*(struct Pair **)(self + 0x3d0))[4].res, 0x17, (void *)(*(int *)(self + 0x3c0) + 4), 0, 0);
            break;
        case 5:
            (*(struct Pair **)(self + 0x3d0))[5].handle =
                Ov107_CreateNodeBodyTask(*(int *)(self + 0x3c), (*(struct Pair **)(self + 0x3d0))[5].res, 0x17, (void *)(*(int *)(self + 0x3bc) + 4), 0, 0);
            break;
        case 7:
            (*(struct Pair **)(self + 0x3d0))[7].handle =
                Ov107_CreateNodeBodyTask(*(int *)(self + 0x3c), (*(struct Pair **)(self + 0x3d0))[7].res, 0x17, (void *)(*(int *)(self + 0x9c) + 0x30), 0, 0);
            break;
        case 8:
            *(int *)(self + 0x3d8) = Ov107_CreateSpawnTask(self, 0x117, 7, 0, self + 0xa0);
            break;
        }
    }
    Ov107_AiState_OnMessage(self, msg, arg);
}
