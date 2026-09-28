/* Files the member into the actor, player or item list by its flags, then links it as a child. */

typedef unsigned short u16;

extern int *List_InsertSorted(int list, int stride, int max);
extern void Ov107_LinkChildNode(int owner, int child);

void Ov107_Region_AddMember(int owner, u16 *child) {
    u16 flags = *child;
    if (flags & 0x40) {
        *List_InsertSorted(owner + 0x80, 4, 100) = (int)child;
    } else if (flags & 0x80) {
        *List_InsertSorted(owner + 0xa8, 4, 110) = (int)child;
        if (*(void (**)(int, int))(owner + 0x14) != 0) {
            (*(void (**)(int, int))(owner + 0x14))(owner, 1);
        }
    } else if (flags & 2) {
        *List_InsertSorted(owner + 0xd0, 4, 90) = (int)child;
        *(int *)((char *)child + 0x40) |= 4;
    }
    Ov107_LinkChildNode(owner, (int)child);
}
