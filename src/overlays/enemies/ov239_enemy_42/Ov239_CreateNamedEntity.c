/* Allocate and name a 0x3bc-byte Ov239Actor, install the initializer callback, and initialize its
 * base actor. */

#include "game/enemy_common.h"

extern void *CallocInstance(int size);
extern void OS_SPrintf(void *buffer, void *format);
extern void func_ov107_020c6624(void *obj, int arg);
extern int data_ov239_020cdc40;
extern void Ov239_InitializeActorResources(void *obj);

void *Ov239_CreateNamedEntity(int arg)
{
    char name[0x1d] = { 0 };
    void *obj = CallocInstance(0x3bc);

    *(signed char *)((int)obj + 0x19c) = 0x42;
    OS_SPrintf(name, &data_ov239_020cdc40);
    *(int *)((int)obj + 0x1a4) = Ov107_OpenCachedResourceByName(name);
    *(void **)((int)obj + 0x18c) = Ov239_InitializeActorResources;
    func_ov107_020c6624(obj, arg);
    return obj;
}
