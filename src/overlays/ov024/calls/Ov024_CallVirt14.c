/* Ov024_CallVirt14 -- virtual call thunk, ov024. Invokes the object's vtable
 * method at +0x14 with the object as `this`. */
typedef void (*Method)(void *);
void Ov024_CallVirt14(void *obj) {
    (*(Method *)((char *)*(void **)obj + 0x14))(obj);
}
