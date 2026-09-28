
#include "nitro/fx_types.h"

extern VecFx32 data_ov002_0207e19c;
extern int data_ov002_0207f628;

extern int func_02023c40(void);
extern void Scene_DrawNode(int pTarget);

/* Reset the tracked offset to its default and kick the follower, but only
 * while the owner still holds a live subject. */
void Ov002_ResetFollowOffset(void)
{
    VecFx32 vDefault;
    int pOwner;

    vDefault = data_ov002_0207e19c;
    pOwner = *(int *)&data_ov002_0207f628;

    func_02023c40();

    if (*(int *)(pOwner + 0xe0) != 0) {
        *(VecFx32 *)(pOwner + 0x6b4) = vDefault;
        Scene_DrawNode(pOwner + 0x610);
    }
}
