/* Client exit step: once the host has answered, sends the client's exit message and waits for its
 * delivery. */

#include "game/engine.h"

typedef void *(*ExitTaskState)(void);
typedef struct Ov005ExitClientMessage { unsigned char playerIndex; char text[22]; } Ov005ExitClientMessage;
typedef struct Ov005ExitTask {
    unsigned receivedPlayerMask;
    int protocolPhase,completionStatus;
    unsigned short sendResult;
    char hostMessage[22];
    Ov005ExitClientMessage clientMessage;
} Ov005ExitTask;
extern Ov005ExitTask *NNSi_FndGetCurrentRootHeap(void);
extern const char *data_ov005_0205b79c[3];
extern void strcpy(char *,const char *);
extern void *Ov005_WaitExitDelivery(void);
ExitTaskState Ov005_UpdateClientExit(void) {
    Ov005ExitTask *task=NNSi_FndGetCurrentRootHeap();
    ExitTaskState nextState=0;
    if(task->receivedPlayerMask!=0) {
        strcpy(task->clientMessage.text,data_ov005_0205b79c[2]);
        MsgQueue_SendGate(19,&task->clientMessage,23);
        task->protocolPhase=1;
        nextState=Ov005_WaitExitDelivery;
    }
    return nextState;
}
