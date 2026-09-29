/* Handles an exit synchronisation message: the host records each client, clients record the host's
 * replies. */

#include "nitro/types.h"
#include "game/engine.h"

typedef struct Ov005ExitTask { unsigned receivedPlayerMask; int protocolPhase; } Ov005ExitTask;
extern Ov005ExitTask *data_ov005_0205b8d0;
extern const char *data_ov005_0205b79c[3];
extern int strcmp(const char *,const char *);
void Ov005_ReceiveExitMessage(const u8 *message,int size) {
    Ov005ExitTask *task=data_ov005_0205b8d0;
    if(task==0)return;
    if(Session_GetLocalPlayerIndex()==0) {
        if(size!=23)return;
        if(strcmp((const char *)message+1,data_ov005_0205b79c[2])==0)
            task->receivedPlayerMask|=1u<<message[0];
    } else if(task->protocolPhase==0) {
        if(strcmp((const char *)message,data_ov005_0205b79c[1])==0)
            task->receivedPlayerMask|=1;
    } else {
        if(strcmp((const char *)message,data_ov005_0205b79c[0])==0)
            task->protocolPhase=2;
    }
}
