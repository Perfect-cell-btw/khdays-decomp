typedef int (*Unk0205137cCallback)(int arg0);

typedef struct {
    void *object;
    int unused;
} Unk0205137cEntry;

extern int data_ov009_020563ec[];
extern Unk0205137cEntry data_ov009_020562dc[];

int Ov009_InvokeHandlerA(int arg0)
{
    int result = 1;
    int index = data_ov009_020563ec[0];

    if (index != -1) {
        result = (*(Unk0205137cCallback *)data_ov009_020562dc[index].object)(arg0);
    }

    return result;
}
