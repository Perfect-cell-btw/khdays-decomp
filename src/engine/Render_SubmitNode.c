/* Attach/refresh `obj` on entity[index]'s container. When p3 and Collision_ProbeGround
 * both yield a transform, optionally compose it with p4 (VEC_Add), apply
 * via ModelObj_Place, cache the CollModel_GetEntryField14 result at obj+0x8c and set flag
 * 0x20; otherwise apply p4 directly. Then set state bits 0xa on obj+8 and
 * (re)link it into the 0x64 or 0x84 list by that bit. */
extern int data_0204c208;
extern int Collision_ProbeGround(void *cont, int p3, void *out);
extern void VEC_Add(void *a, void *b, void *c);
extern void ModelObj_Place(void *cont, void *field, void *vec);
extern int CollModel_GetEntryField14(void *cont, int p3);
extern void RenderList_PushEarly(int index, void *obj);
extern void RenderList_PushMain(int index, void *obj);

void Render_SubmitNode(void *obj, int index, int p3, void *p4) {
    void *cont = (void *)(data_0204c208 + 4 + index * 8);
    unsigned int buf[3];
    if (p3 != 0 && Collision_ProbeGround(cont, p3, buf) != 0) {
        if (p4 != 0) {
            VEC_Add(buf, p4, buf);
        }
        ModelObj_Place(cont, (char *)obj + 0xc, buf);
        {
            int r = CollModel_GetEntryField14(cont, p3);
            if ((*(int *)((char *)obj + 0xc) & 0x20) == 0) {
                *(short *)((char *)obj + 0x8c) = (short)r;
                *(unsigned short *)((char *)obj + 0x10) |= 0x20;
            }
        }
    } else {
        ModelObj_Place(cont, (char *)obj + 0xc, p4);
    }
    {
        unsigned char v = *(unsigned char *)((char *)obj + 8);
        v |= 0xa;
        *(unsigned char *)((char *)obj + 8) = v;
        if (v & 0x20) {
            RenderList_PushEarly(index, obj);
        } else {
            RenderList_PushMain(index, obj);
        }
    }
}
