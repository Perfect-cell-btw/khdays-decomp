/* In states 2-5 sets the model's polygon ID from the fade step and draws the node. */

extern int NNS_G3dMdlSetMdlPolygonID();
extern int Scene_DrawNode();

struct S {
    char pad[0x78];
    int *p78;
    char pad2[0x12c - 0x7c];
    unsigned char b12c;
    unsigned char b12d;
};

void Ov082_DrawWithFadePolygonId(struct S *r4) {
    switch (r4->b12c) {
    case 2:
    case 3:
    case 4:
    case 5:
        NNS_G3dMdlSetMdlPolygonID(r4->p78, 5, 0x1c - r4->b12d);
        Scene_DrawNode(r4);
        return;
    case 0:
    case 1:
    default:
        return;
    }
}
