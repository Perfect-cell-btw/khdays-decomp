/* Runs a received member event by its selector: shows damage on a member (clients only), sets a
 * colour channel, or runs the member's kind handler (clients only). */

extern int Session_GetLocalPlayerIndex(void);
extern void Ov022_Member_ShowDamage(int kind, int id, int a2, int a3);
extern void Ov022_SetColourChannel(int kind, int a2, int id);
extern void func_ov022_02088cac(int kind);

struct Ent02089d90 {
    unsigned short id;
    unsigned char a2;
    unsigned char a3;
    unsigned char sel : 3;
    unsigned char kind : 3;
};

void Ov022_DispatchEntryByKind(int arg0) {
    struct Ent02089d90 *e = (struct Ent02089d90 *)arg0;
    switch (e->sel) {
    case 0:
        if (Session_GetLocalPlayerIndex() == 0) return;
        Ov022_Member_ShowDamage(e->kind, e->id, e->a2, e->a3);
        return;
    case 1:
        Ov022_SetColourChannel(e->kind, e->a2, e->id);
        return;
    case 2:
        if (Session_GetLocalPlayerIndex() == 0) return;
        func_ov022_02088cac(e->kind);
        return;
    }
}
