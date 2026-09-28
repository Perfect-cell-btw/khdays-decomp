/* Message override: message 5 carries a packed position; it spawns a node-transform task at that
 * position and a spawn task; other messages go to the shared handler (Ov107_AiState_OnMessage). */

typedef struct { int w[11]; } SrtTransform;
typedef struct { int x, y, z; } Vec3;

extern void SrtTransform_SetIdentity(SrtTransform *transform);
extern void Srt_SetTranslation(SrtTransform *transform, const Vec3 *translation);
extern int Ov107_CreateNodeXformTask(int model, int parent, int kind, int zero,
                               SrtTransform *transform);
extern int Ov107_CreateSpawnTask(int owner, int resourceId, int kind, int zero,
                               void *work);
extern void Ov107_AiState_OnMessage(int owner, unsigned char *command, int arg);

void Ov198_IssueSpawnCommand(int owner, unsigned char *command, int arg)
{
    SrtTransform transform;
    Vec3 translation;
    union {
        int words[3];
        unsigned char bytes[12];
    } packed;

    if (command[2] == 5) {
        packed.bytes[3] = command[5];
        packed.bytes[2] = command[6];
        packed.bytes[1] = command[7];
        translation.x = packed.words[0] >> 8;

        packed.bytes[7] = command[8];
        packed.bytes[6] = command[9];
        packed.bytes[5] = command[0xa];
        translation.y = packed.words[1] >> 8;

        packed.bytes[11] = command[0xb];
        packed.bytes[10] = command[0xc];
        packed.bytes[9] = command[0xd];
        translation.z = packed.words[2] >> 8;

        switch (command[3]) {
        case 0:
            SrtTransform_SetIdentity(&transform);
            Srt_SetTranslation(&transform, &translation);
            *(int *)(owner + command[3] * 8 + 0x3f4) =
                Ov107_CreateNodeXformTask(*(int *)(owner + 0x3c),
                                    *(int *)(owner + command[3] * 8 + 0x3f0),
                                    0x17, 0, &transform);
            break;
        case 2:
            *(int *)(owner + 0x3ec) =
                Ov107_CreateSpawnTask(owner, 0x130, 4, 0,
                                    (void *)(owner + 0xa0));
            break;
        }
    }

    Ov107_AiState_OnMessage(owner, command, arg);
}




