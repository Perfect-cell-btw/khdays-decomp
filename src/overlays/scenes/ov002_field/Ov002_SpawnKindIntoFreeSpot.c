
/* The stage's own linear congruential generator. */

#include "nitro/types.h"

typedef struct Ov002Rng {
    int nSeed;
    int nMult;
    int nInc;
} Ov002Rng;

typedef struct Ov002Spawned {
    char pad000[0x30];
    u8 bFlags;
} Ov002Spawned;

typedef struct Ov002SpotStage {
    char pad000[0x2518];
    Ov002Rng rng;
} Ov002SpotStage;

typedef struct Ov002SpotHolder {
    char pad000[4];
    Ov002SpotStage *pStage;
} Ov002SpotHolder;

typedef struct Ov002SpotDesc {
    s8 nAnimSlot;           /* animation slot; negative means unavailable */
    char pad001[7];
} Ov002SpotDesc;

extern Ov002SpotHolder data_ov002_0207fa28;
extern Ov002SpotDesc data_ov002_0207e67c[];
extern u8 data_0204c240;                /* boot-mode flags */
extern u8 data_0204c248[];

extern int Ov002_FindFreeSpotId(int nWhich);     /* pick a free spot */
extern Ov002Spawned *Ov002_BuildSpawnRow(int nSpot, int nKind, int a1, int a2,
                                         int a3, int a4, Ov002Rng *pRng);

static inline void Ov002_StepRng(Ov002Rng *pRng)
{
    pRng->nSeed = pRng->nMult * pRng->nSeed + pRng->nInc;
}

/* Spawns one object of the requested kind into whichever spot is free.  When
   no spot is free it still burns three draws off the stage's generator, so the
   sequence stays in step whether or not the spawn happened.  Bit 2 is cleared
   on whatever it spawns, the opposite of what Ov002_SpawnSpot does. */
void *Ov002_SpawnKindIntoFreeSpot(int nKind, int a1, int a2, int a3, int a4)
{
    Ov002Spawned *pSpawned;
    int nSpot;

    if (data_ov002_0207e67c[nKind].nAnimSlot < 0) {
        return 0;
    }

    if ((data_0204c240 & 4) != 0) {
        if (nKind == 2 && data_0204c248[5] == 0) {
            return 0;
        }
    } else {
        if (nKind == 0) {
            return 0;
        }
    }

    nSpot = Ov002_FindFreeSpotId(0);
    if (nSpot < 0) {
        Ov002_StepRng(&data_ov002_0207fa28.pStage->rng);
        Ov002_StepRng(&data_ov002_0207fa28.pStage->rng);
        Ov002_StepRng(&data_ov002_0207fa28.pStage->rng);
        return 0;
    }

    pSpawned = Ov002_BuildSpawnRow(nSpot, nKind, a1, a2, a3, a4,
                                   &data_ov002_0207fa28.pStage->rng);
    pSpawned->bFlags = (u8)(pSpawned->bFlags & ~4);
    return pSpawned;
}
