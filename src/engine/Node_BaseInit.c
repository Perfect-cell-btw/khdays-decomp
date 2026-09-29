/* Resets the node's flags, callbacks and both transforms, and counts it. */

#include "game/engine.h"

extern void SrtTransform_SetIdentity(void *o);
extern void Node_BaseOnDestroy(void);
extern void Node_DefaultHook6C(void);
extern int data_0204caa8;

typedef struct {
    int x0;
    char _4[0x58];
    unsigned int flags;
    unsigned char x60;
    char _61[3];
    void (*x64)(void);
    void (*x68)(int *);
    void (*x6c)(void);
    short x70;
    char _72[2];
    int x74;
    int x78;
    int x7c;
    int x80;
    int x84;
} S;

void Node_BaseInit(S *p)
{
    p->flags &= ~1u;
    p->flags &= ~2u;
    p->x0 = 0;
    p->x60 = 0;
    p->x70 = 0;
    p->x64 = Node_BaseOnDestroy;
    p->x6c = Node_DefaultHook6C;
    p->x74 = 0;
    p->x78 = 0;
    p->x84 = 0;
    p->x68 = Node_ComposeWorldSrt;
    p->x7c = 0;
    p->x80 = 0;
    SrtTransform_SetIdentity((char *)p + 4);
    SrtTransform_SetIdentity((char *)p + 0x30);
    data_0204caa8++;
}
