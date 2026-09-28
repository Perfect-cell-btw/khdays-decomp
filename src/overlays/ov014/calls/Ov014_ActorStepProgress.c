extern int Ov002_GetModuleScale(void);
extern void Ov002_SetFrameOnActiveTracks(void *, int);
extern void Ov002_RebindAnimTracks(void *, int, int);
extern int Ov002_FindKeyIndex(int);
extern void Ov002_SetKeyNodeVisible(int, int, int);
extern unsigned int GameState_GetField(int, int);
extern void GameState_SetField(unsigned int, unsigned int, unsigned int);
extern int Ov002_DoneTick(void);

typedef struct Owner {
    unsigned char _000[0x58];
    int resource;                    /* 0x058 */
} Owner;

/* The block the model routines are handed, at actor+0x2c. */
typedef struct ModelBlock {
    unsigned char _000[0x0c];
} ModelBlock;

/* The block the animation routines are handed, at actor+0x3c. */
typedef struct AnimBlock {
    unsigned short flags;            /* 0x000 */
    unsigned char _002[0x7a];
} AnimBlock;

typedef struct Actor {
    unsigned char _000[8];
    Owner *owner;                    /* 0x008 */
    unsigned char _00c[4];
    unsigned char slot;              /* 0x010 */
    unsigned char _011;
    unsigned short flags;            /* 0x012 */
    unsigned short selector;         /* 0x014 */
    unsigned char count;             /* 0x016 */
    unsigned char _017;
    unsigned short animation;        /* 0x018 */
    unsigned char _01a[0x12];
    ModelBlock model;                /* 0x02c */
    int drawFlags;                   /* 0x038 */
    AnimBlock anim;                  /* 0x03c */
    unsigned short animId;           /* 0x0b8 */
    unsigned char _0ba[0x7a];
    unsigned char phase;             /* 0x134 */
    unsigned char step;              /* 0x135 */
    unsigned char _136[0x7b];
    unsigned char state;             /* 0x1b1 */
    unsigned char _1b2;
    unsigned char pose;              /* 0x1b3 */
    unsigned char _1b4[0x18];
    int progress;                    /* 0x1cc */
    short soundId;                   /* 0x1d0 */
} Actor;

int Ov014_ActorStepProgress(Actor *self)
{
    int frame;
    int complete;

    frame = Ov002_GetModuleScale();
    complete = 0;
    if ((self->state & 2) == 0)
        goto not_complete;
    {
        self->progress = self->progress + frame;
        frame = self->progress;
        if (frame >= 0x24000) {
            frame = 0x24000;
            self->progress = frame;
            complete = 1;
        }
        if ((self->flags & 4) != 0)
            Ov002_SetFrameOnActiveTracks(&self->anim, self->progress);
    }
    if (complete == 0)
        goto not_complete;
    {
        int bits;
        self->pose = 2;
        Ov002_RebindAnimTracks(&self->anim, 2, 0);
        self->state &= ~2;
        frame = Ov002_FindKeyIndex(self->soundId);
        if (frame >= 0)
            Ov002_SetKeyNodeVisible(self->soundId, 1, -1);
        bits = GameState_GetField(self->selector, self->count);
        GameState_SetField(self->selector, self->count,
                      (unsigned short)((bits & 0xffff0001) | 4));
        return (int)Ov002_DoneTick;
    }
not_complete:
    return 0;
}
