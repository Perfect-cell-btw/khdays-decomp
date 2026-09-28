#include "nitro/types.h"

typedef struct {
    char pad00[4];
    char *pContext;                 /* +0x04 */
} Ov002SceneRef;

extern Ov002SceneRef data_ov002_0207fa20;

/* A scene command as it reaches the router: what to do, who to do it to, and
 * one argument.  Target kind 0xff with the wildcard id is the broadcast form. */
typedef struct {
    u8  bOp;                        /* +0x00 */
    u8  bTargetKind;                /* +0x01 */
    u16 wTargetId;                  /* +0x02 */
    u16 wArg;                       /* +0x04 */
} Ov002SceneCommand;

extern void Ov002_NotifyNodesOfKind(int nKind);
extern void Ov002_ActivateSpotFromCommand(int nId, Ov002SceneCommand *pCmd, void *pParam);
extern int Ov002_MulTagAtField4ePlusField54(int pList, int nId);
extern void Ov002_Element_CallHook8(int pNode, Ov002SceneCommand *pCmd, void *pParam);

/* Route a scene command to whatever it is addressed to.
 *
 * Target kind 0xff paired with the wildcard id 0xffff is the broadcast form,
 * and only operation 1 has anything to broadcast.  Kind 0x1f has a router of
 * its own.  Every other kind names one of the node lists the context keeps
 * from +0x17c on, and the command's id picks the node out of it; a command
 * addressed to a node that is not there is dropped.
 */
void Ov002_RouteSceneCommand(Ov002SceneCommand *pCmd, void *pParam)
{
    int pNode;

    if (pCmd->bTargetKind == 0xff && pCmd->wTargetId == 0xffff) {
        if (pCmd->bOp == 1) {
            Ov002_NotifyNodesOfKind(pCmd->wArg);
        }
        return;
    }

    if (pCmd->bTargetKind == 0x1f) {
        Ov002_ActivateSpotFromCommand(pCmd->wTargetId, pCmd, pParam);
        return;
    }

    pNode = Ov002_MulTagAtField4ePlusField54(
        *(int *)(data_ov002_0207fa20.pContext + pCmd->bTargetKind * 4 + 0x17c),
        pCmd->wTargetId);
    if (pNode != 0) {
        Ov002_Element_CallHook8(pNode, pCmd, pParam);
    }
}
