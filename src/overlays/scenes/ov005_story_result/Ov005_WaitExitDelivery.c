/* Waits until the exit message has been delivered (host) or answered (clients, resending
 * meanwhile), then finishes the exit. */

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
extern unsigned Session_GetLocalPlayerIndex(void);
extern int MsgQueue_Contains(unsigned);
extern unsigned MsgQueue_SendGate(int,const void *,unsigned);
extern void *Ov005_FinishExit(void);
ExitTaskState Ov005_WaitExitDelivery(void) {
    Ov005ExitTask *task=NNSi_FndGetCurrentRootHeap();
    int complete=0;
    if(Session_GetLocalPlayerIndex()==0) {
        if(MsgQueue_Contains(task->sendResult)==0)complete=1;
    } else {
        if(task->protocolPhase!=1)complete=1;
        else MsgQueue_SendGate(19,&task->clientMessage,23);
    }
    return complete?Ov005_FinishExit:0;
}
