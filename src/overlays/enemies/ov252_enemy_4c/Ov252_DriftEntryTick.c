/* Drift entry tick of the ov252 actor: the +0xc velocity is the +0x574 part's +0x2c vector turned by
 * the +0x54 heading (020cdafc); once the partner holds no queued move pose 0xe plays, the part takes
 * motion 0x13 and the node moves on to 020d09cc. */
typedef struct { int x, y, z; } Vec3;

extern void Ov252_TurnVecY(Vec3 *out, int angle, Vec3 *vec);
extern void Ov107_PostTagUpdate(int actor, int pose, int loop);
extern int Ov107_StartAnim(int part, int motion, int mode);
extern void SetIndexedSlot(int *node, int slot, void *cb);
extern void Ov252_DriftLandTick(void);

void Ov252_DriftEntryTick(int *node)
{
    int *state = (int *)node[1];
    Vec3 v;

    Ov252_TurnVecY(&v, state[0x15], (Vec3 *)(*(int *)(*state + 0x574) + 0x2c));
    *(Vec3 *)(state + 3) = v;
    if (*(unsigned char *)(state[1] + 0xad) != 0) {
        return;
    }
    Ov107_PostTagUpdate(*state, 0xe, 0);
    Ov107_StartAnim(*(int *)(*state + 0x574), 0x13, 0);
    SetIndexedSlot(node, *(signed char *)((char *)node + 0x20), Ov252_DriftLandTick);
}
