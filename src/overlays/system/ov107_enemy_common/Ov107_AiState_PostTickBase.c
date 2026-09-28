/* Counts the hit cooldown down, updates the hit shapes, respawns actors fallen below the world and
 * ticks the rest timer. */

extern int func_ov107_020c9848(void);
extern int List_First(void *list);
extern int List_Next(void *list);
extern void Ov107_HitShape_UpdateWorld(int v);
extern void Ov107_MoveNodeAndRelayout(void *self, void *node);
extern void Ov107_AiState_PostTick(void *self);

typedef struct {
    void *f0;
    char pad4[4];
    unsigned int f8 : 8;
} InnerNode;

typedef struct {
    unsigned char bit0 : 1;
    unsigned char rest : 7;
} Flags311;

void Ov107_AiState_PostTickBase(char *self)
{
    if (*(int *)(self + 0x2e8) > 0) {
        int cooldown = *(int *)(self + 0x2e8) - *(int *)((char *)func_ov107_020c9848() + 0x40) / 30;
        *(int *)(self + 0x2e8) = cooldown;
        if (cooldown <= 0) {
            *(int *)(self + 0x2e8) = 0;
        }
    }

    if ((unsigned)(*(unsigned short *)(self + 0x60) << 24) >> 24 & 1) {
        InnerNode *node = (InnerNode *)List_First(self + 0x22c);
        while (node != 0) {
            if ((node->f8 & 1) && node->f0 != 0) {
                Ov107_HitShape_UpdateWorld((int)node->f0);
            }
            node = (InnerNode *)List_Next(self + 0x22c);
        }
    }

    if (*(int *)(self + 0xb4) < -0x32000) {
        Ov107_MoveNodeAndRelayout(self, self + 0x190);
    }

    if (*(int *)(self + 0x50) == 2) {
        if (((Flags311 *)(self + 0x311))->rest != 0) {
            ((Flags311 *)(self + 0x311))->rest--;
        }
    }

    Ov107_AiState_PostTick(self);
}
