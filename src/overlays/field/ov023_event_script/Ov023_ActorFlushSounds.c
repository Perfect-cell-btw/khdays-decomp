/* Ov023_ActorFlushSounds -- Ov023_ActorFlushSounds: fire the actor's two queued sound requests
 * (+0x498, 0x10 bytes each): kind 1 plays the pair (02033b24), kind 2 forwards the three words
 * (02033bb4); each request's kind is then cleared. */
#include "nitro/types.h"

typedef struct Ov023SoundRequest {
    int  nA;                  /* 0x00 */
    int  nB;                  /* 0x04 */
    int  nC;                  /* 0x08 */
    int  nKind;               /* 0x0c */
} Ov023SoundRequest;          /* 0x10 */

typedef struct Ov023Actor {
    u8   pad_0000[0x498];
    Ov023SoundRequest aSound[2]; /* 0x0498 */
} Ov023Actor;

extern void PlaySoundChecked(int nPair, int nArg);                     /* PlaySoundChecked */
extern void ForwardToHandlerOrCurrentObject(int nA, int nB, int nC);                  /* ForwardToHandlerOrCurrentObject */

void Ov023_ActorFlushSounds(Ov023Actor *pActor)
{
    int i;

    for (i = 0; i < 2; i++) {
        switch (pActor->aSound[i].nKind) {
        case 1:
            PlaySoundChecked(pActor->aSound[i].nA, pActor->aSound[i].nB);
            break;
        case 2:
            ForwardToHandlerOrCurrentObject(pActor->aSound[i].nA, pActor->aSound[i].nB, pActor->aSound[i].nC);
            break;
        }
        pActor->aSound[i].nKind = 0;
    }
}
