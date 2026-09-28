typedef struct Ov005Context { char opaque00[0x4c34]; int exitRequested; } Ov005Context;
extern Ov005Context *data_ov005_0205b80c;
void Ov005_MarkMenuExitRequested(void) {
    Ov005Context *context=data_ov005_0205b80c;
    if(context->exitRequested==0)context->exitRequested=1;
}
