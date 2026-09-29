/* Runs every child's handler, alternating forward and backward order each frame. */

#include "game/engine.h"

typedef struct HandlerObj {
    char pad[0x20];
    void (*handler)(struct HandlerObj *self);
} HandlerObj;

typedef HandlerObj **ListItem;

typedef struct Ov107 {
    char pad[0x6c];
    int field_6c;
} Ov107;

extern ListItem List_First(void *list);
extern ListItem List_Last(void *list);
extern ListItem List_Prev(void *list);

void Ov107_Region_RunHandlersAlternating(Ov107 *self)
{
    void *list = (char *)self + 0x44;
    ListItem item;

    self->field_6c++;
    if (self->field_6c & 1) {
        item = List_First(list);
        if (item != 0) {
            do {
                HandlerObj *obj = *item;
                if (obj->handler) {
                    obj->handler(obj);
                }
                item = List_Next(list);
            } while (item != 0);
        }
    } else {
        item = List_Last(list);
        if (item != 0) {
            do {
                HandlerObj *obj = *item;
                if (obj->handler) {
                    obj->handler(obj);
                }
                item = List_Prev(list);
            } while (item != 0);
        }
    }
}
