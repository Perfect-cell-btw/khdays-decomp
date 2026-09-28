/* Ov005_Widget_HitTest -- is the point (x, y) inside this widget's projected rectangle?
 * Only hit-tests a widget that is live (+0x98 set), not flagged out by bit 0 of +0x84, flagged in
 * by bit 1, and passing Ov005_Widget_IsShownAndEnabled's own visibility check. The rect comes from
 * Ov005_ProjectWorldPos, which projects the world position and reads the size from +0x1c/+0x1e;
 * a size of 0xffff on either axis means "no box" and never hits.
 * The bounds test is inclusive on all four edges. */

typedef struct {
    char pad[0x84];
    unsigned int b84_0 : 1;
    unsigned int b84_1 : 1;
    unsigned int b84_rest : 30;
    char pad2[0x98 - 0x88];
    int f98;
} Obj;

extern int Ov005_Widget_IsShownAndEnabled(Obj *o);
extern int *Ov005_ProjectWorldPos(int a, int *out, Obj *o);

int Ov005_Widget_HitTest(int a, int x, int y, Obj *o) {
    int rect[4];
    int hit;

    hit = 0;
    if (o->f98 != 0 && !o->b84_0 && o->b84_1 && Ov005_Widget_IsShownAndEnabled(o) != 0) {
        Ov005_ProjectWorldPos(a, rect, o);
        if (rect[2] == 0xffff || rect[3] == 0xffff) {
            return 0;
        }
        if (rect[0] <= x && x <= rect[0] + rect[2] && rect[1] <= y && y <= rect[1] + rect[3]) {
            hit = 1;
        }
    }
    return hit;
}
