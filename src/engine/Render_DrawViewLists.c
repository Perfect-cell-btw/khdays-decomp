/* Per-frame update over entity[index]'s three intrusive lists (head slots at
 * data_0204c208+index*4+{0x64,0x84,0xa4}): run Scene_DrawNode on active nodes,
 * snapshot each active node's +0xb4 vec into +0x168 and run ShadowVolume_Draw, then
 * a second Scene_DrawNode pass, and finally Billboard_DrawList over the +0xa4 list. */
extern int data_0204c208;
extern void Scene_DrawNode(void *);
extern void ShadowVolume_Draw(void *);
extern void G3d_ResetGlobalState(void);
extern void Billboard_DrawList(void *);

struct V3 { int a, b, c; };

void Render_DrawViewLists(int index) {
    int *p;
    for (p = *(int **)(data_0204c208 + index * 4 + 0x64); p != 0; p = *(int **)p) {
        if ((*(unsigned char *)(p + 2) & 8) && (p[3] & 0x20) == 0) {
            Scene_DrawNode(p + 4);
        }
    }
    for (p = *(int **)(data_0204c208 + index * 4 + 0x84); p != 0; p = *(int **)p) {
        if ((*(unsigned char *)(p + 2) & 0x18) == 0x18) {
            *(struct V3 *)((char *)p + 0x168) = *(struct V3 *)((char *)p + 0xb4);
            ShadowVolume_Draw((char *)p + 0x168);
        }
    }
    for (p = *(int **)(data_0204c208 + index * 4 + 0x84); p != 0; p = *(int **)p) {
        if ((*(unsigned char *)(p + 2) & 8) && (p[3] & 0x20) == 0) {
            Scene_DrawNode(p + 4);
        }
    }
    p = *(int **)(data_0204c208 + index * 4 + 0xa4);
    if (p != 0) {
        G3d_ResetGlobalState();
        do {
            Billboard_DrawList(p + 3);
            p = *(int **)p;
        } while (p != 0);
    }
}
