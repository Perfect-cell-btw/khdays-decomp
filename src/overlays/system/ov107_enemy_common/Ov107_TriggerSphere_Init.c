/* Initialises a trigger sphere (test/react hooks, center, radius, bounding box). */

#include "nitro/types.h"

extern void Ov107_TaskReset(int obj);
extern void Ov107_TriggerSphere_TestPlayers(void);
extern void Ov107_TriggerSphere_NotifyExits(void);
extern void SphereToAABB(int *dst, int *src);

typedef struct { u32 w[3]; } Blk3;
typedef struct { u32 w[4]; } Blk4;

void Ov107_TriggerSphere_Init(int a, int b)
{
    Ov107_TaskReset(a);
    *(void (**)(void))(a + 4) = Ov107_TriggerSphere_TestPlayers;
    *(void (**)(void))(a + 8) = Ov107_TriggerSphere_NotifyExits;
    *(Blk3 *)(a + 0x10) = *(Blk3 *)b;
    *(Blk4 *)(a + 0x1c) = *(Blk4 *)b;
    SphereToAABB((int *)(a + 0x2c), (int *)b);
}
