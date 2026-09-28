/* Message handler of the ov235 enemy (+0x1c). Kind-5 messages drive its effects, kept as
 * resource/handle pairs in the +0x3bc table: 0 starts the wing effect on the +0x3b0 part
 * (Ov235_SpawnChildStoreTwoArgs, pair 4), 1 the trail between pairs 2 and 3 on the +0x3ac part
 * (Ov235_SpawnHelper), 2 stops the trail, 3/4/5 play pairs 0, 1 and 5 (kind 0x17) and 6 pair
 * 7 (kind 5) at the message point, 7 attaches pair 6 to the +0x3ac part, 8 attaches pair 8 to the
 * +0x3b4 part, clears +0x3c4 and starts pair 10 there (Ov235_CreateHelperTask), 9 plays pair 9 at the
 * +0x3b0 part's point, 0xb raises +0x3c4, 0xc starts reaction +0x3c8 mode 0xd on the +0xa0 pose
 * (+0x3cc) and 0xd ends it. Every message then goes to the common handler. */
typedef unsigned char u8;
typedef struct { int value; } Fx32;
struct Pair { int res; int handle; };

#define PACK(buf, dead, src, at)                                              \
    (dead) = (src);                                                           \
    (buf)[at] = (u8)(((unsigned int)(dead).value >> 0x10 & 0x7f)              \
                     | ((unsigned int)(dead).value >> 0x18 & 0x80));          \
    (buf)[(at) + 1] = (u8)((unsigned int)(dead).value >> 8);                  \
    (buf)[(at) + 2] = (u8)(dead).value

extern int Ov235_SpawnChildStoreTwoArgs(char *self, int res, void *at);
extern int Ov235_SpawnHelper(char *self, int res, int res2, void *at);
extern void TaskList_FinishByTag(int model, int handle);
extern int Ov107_CreateNodeXformTaskFx24(int model, int res, int kind, int arg, int scale, void *pos);
extern int Ov107_CreateNodeBodyTask(int model, int res, int kind, void *at, int a, int b);
extern int Ov235_CreateHelperTask(char *self, int res, void *at);
extern int Ov107_CreateSpawnTask(char *self, int id, int mode, int flag, void *pose);
extern void Ov107_UnlinkNodeFromOwner(int handle);
extern void Ov107_AiState_OnMessage(char *self, u8 *msg, int arg);

#define PAIRS (*(struct Pair **)(self + 0x3bc))

void Ov235_HandleMessage(char *self, u8 *msg, int arg)
{
    u8 pos[9];
    Fx32 scratchZ;
    Fx32 scratchY;
    Fx32 scratchX;

    if (msg[2] == 5) {
        switch (msg[3]) {
        case 0:
            PAIRS[4].handle = Ov235_SpawnChildStoreTwoArgs(self, PAIRS[4].res, (void *)(*(int *)(self + 0x3b0) + 4));
            break;
        case 1:
            PAIRS[2].handle = Ov235_SpawnHelper(self, PAIRS[2].res, PAIRS[3].res, (void *)(*(int *)(self + 0x3ac) + 4));
            break;
        case 2:
            if (PAIRS[2].handle != 0) {
                TaskList_FinishByTag(*(int *)(self + 0x3c), PAIRS[2].handle);
                PAIRS[2].handle = 0;
            }
            break;
        case 3:
            PAIRS[0].handle = Ov107_CreateNodeXformTaskFx24(*(int *)(self + 0x3c), PAIRS[0].res, 0x17, 0, 0x1000, msg + 5);
            break;
        case 4:
            PAIRS[1].handle = Ov107_CreateNodeXformTaskFx24(*(int *)(self + 0x3c), PAIRS[1].res, 0x17, 0, 0x1000, msg + 5);
            break;
        case 5:
            PAIRS[5].handle = Ov107_CreateNodeXformTaskFx24(*(int *)(self + 0x3c), PAIRS[5].res, 0x17, 0, 0x1000, msg + 5);
            break;
        case 6:
            PAIRS[7].handle = Ov107_CreateNodeXformTaskFx24(*(int *)(self + 0x3c), PAIRS[7].res, 5, 0, 0x1000, msg + 5);
            break;
        case 7:
            PAIRS[6].handle = Ov107_CreateNodeBodyTask(*(int *)(self + 0x3c), PAIRS[6].res, 0x17, (void *)(*(int *)(self + 0x3ac) + 4), 0, 0);
            break;
        case 9: {
            int part = *(int *)(self + 0x3b0);

            PACK(pos, scratchX, *(Fx32 *)(part + 0x14), 0);
            PACK(pos, scratchY, *(Fx32 *)(part + 0x18), 3);
            PACK(pos, scratchZ, *(Fx32 *)(part + 0x1c), 6);
            PAIRS[9].handle = Ov107_CreateNodeXformTaskFx24(*(int *)(self + 0x3c), PAIRS[9].res, 5, 0, 0x1000, pos);
            break;
        }
        case 8:
            PAIRS[8].handle = Ov107_CreateNodeBodyTask(*(int *)(self + 0x3c), PAIRS[8].res, 5, (void *)(*(int *)(self + 0x3b4) + 4), 0, 0);
            *(int *)(self + 0x3c4) = 0;
            PAIRS[10].handle = Ov235_CreateHelperTask(self, PAIRS[10].res, (void *)(*(int *)(self + 0x3b4) + 4));
            break;
        case 11:
            *(int *)(self + 0x3c4) = 1;
            break;
        case 12:
            *(int *)(self + 0x3cc) = Ov107_CreateSpawnTask(self, (short)*(int *)(self + 0x3c8), 0xd, 0, self + 0xa0);
            break;
        case 13:
            Ov107_UnlinkNodeFromOwner(*(int *)(self + 0x3cc));
            *(int *)(self + 0x3cc) = 0;
            break;
        }
    }
    Ov107_AiState_OnMessage(self, msg, arg);
}
