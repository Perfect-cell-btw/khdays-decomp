#include "nitro/types.h"

extern int Ov002_LookupChannelEntry(void *pName);
extern void Entity_Register(char *pObj, int nRes, int a, int b);
extern int GameState_GetField(u16 nId, unsigned char nSlot);
extern void Obj_SetFlagBit3(char *pObj, int bOn);

/* Rebind a timed element's model and reset it to a neutral pose.
 *
 * Skipped for a nameless owner and for state 7. The model is bound again, the
 * three scale components are put back to one, the first placement remembers
 * the angle, and the object goes back to following the game-state bit.
 */
void Ov002_ElementRebindModel(char *pElement)
{
    char *pOwner;
    u16 wAngle;
    int nState;

    pOwner = *(char **)(pElement + 8);

    if (*(signed char *)(pOwner + 0x58) != 0
        && *(unsigned char *)(pElement + 0x1b4) != 7) {

        Entity_Register(pElement + 0x2c, Ov002_LookupChannelEntry(pOwner + 0x58),
                      1, 4);

        *(int *)(pElement + 0xec) = *(int *)(pElement + 0xf0) =
            *(int *)(pElement + 0xf4) = 0x1000;

        wAngle = *(u16 *)(pElement + 0x18);
        if ((*(unsigned int *)(pElement + 0x38) & 0x20) == 0) {
            *(u16 *)(pElement + 0xb8) = wAngle;
            *(u16 *)(pElement + 0x3c) |= 0x20;
        }

        nState = GameState_GetField(*(u16 *)(pElement + 0x14),
                               *(unsigned char *)(pElement + 0x16));
        Obj_SetFlagBit3(pElement + 0x2c, (nState & 1) != 0);
    }
}
