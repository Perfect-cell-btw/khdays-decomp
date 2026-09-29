/* Replaces the object's data with a copy of the source and installs the four action request
 * callbacks. */

#include "game/engine.h"

typedef void (*Callback262)(void);

typedef struct {
    int unk0;
    Callback262 cb0;
    Callback262 cb1;
    Callback262 cb2;
    Callback262 cb3;
} Header262;

typedef struct {
    char pad[0x39c];
    void *aux;
    void *data;
} Obj262;

extern void *CallocInstance(int size);
extern void MI_CpuCopy8(void *src, void *dst, int size);
extern void Ov262_RequestAction2(void);
extern void Ov262_RequestAction3WithParams(void);
extern void Ov262_RequestAction4WithParams(void);
extern void Ov262_RequestAction5WithValue(void);

void Ov262_ReallocBufferInitConsts(Obj262 *obj, int size, Header262 *src)
{
    if (obj->data != 0) {
        FreeInstanceMemory(obj->data);
        obj->data = 0;
        obj->aux = 0;
    }

    obj->data = CallocInstance(size);
    MI_CpuCopy8(src, obj->data, size);
    src->cb0 = Ov262_RequestAction2;
    src->cb1 = Ov262_RequestAction3WithParams;
    src->cb2 = Ov262_RequestAction4WithParams;
    src->cb3 = Ov262_RequestAction5WithValue;
}
