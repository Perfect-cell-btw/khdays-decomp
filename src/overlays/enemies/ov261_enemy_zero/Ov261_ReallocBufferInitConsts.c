/* Replaces the object's data with a copy of the source and installs the four action request
 * callbacks. */

#include "game/engine.h"

typedef void (*Callback261)(void);

typedef struct {
    int unk0;
    Callback261 cb0;
    Callback261 cb1;
    Callback261 cb2;
    Callback261 cb3;
} Header261;

typedef struct {
    char pad[0x39c];
    void *aux;
    void *data;
} Obj261;

extern void *CallocInstance(int size);
extern void MI_CpuCopy8(void *src, void *dst, int size);
extern void Ov261_RequestAction2(void);
extern void Ov261_RequestAction3WithParams(void);
extern void Ov261_RequestAction4WithParams(void);
extern void Ov261_RequestAction5WithValue(void);

void Ov261_ReallocBufferInitConsts(Obj261 *obj, int size, Header261 *src)
{
    if (obj->data != 0) {
        FreeInstanceMemory(obj->data);
        obj->data = 0;
        obj->aux = 0;
    }

    obj->data = CallocInstance(size);
    MI_CpuCopy8(src, obj->data, size);
    src->cb0 = Ov261_RequestAction2;
    src->cb1 = Ov261_RequestAction3WithParams;
    src->cb2 = Ov261_RequestAction4WithParams;
    src->cb3 = Ov261_RequestAction5WithValue;
}
