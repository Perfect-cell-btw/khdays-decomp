/* Posts a type-3 request (two ids and two arguments) to the loader thread. */

extern void *Loader_PopFreeRequest(void);
extern void OS_SendMessage(void *queue, void *message, int flags);

extern int data_0204bc1c;

typedef struct {
    char _0[4];
    int type;
    unsigned short id0;
    unsigned short id1;
    int arg2;
    int arg3;
} Message_0201f750;

void Loader_PostTypedRequest(unsigned short id0, unsigned short id1, int arg2, int arg3)
{
    Message_0201f750 *msg = Loader_PopFreeRequest();

    if (msg == 0)
        return;

    msg->type = 3;
    msg->id0 = id0;
    msg->id1 = id1;
    msg->arg2 = arg2;
    msg->arg3 = arg3;
    OS_SendMessage(&data_0204bc1c, msg, 1);
}
