/* Draw handler for a script entity. Nothing is drawn until the entity has been
 * bound, and nothing is drawn while the shared ov022 slot reports -1.
 *
 * It swaps in the entity's own camera, set to an orthographic box of
 * +/-0x3b33 by +/-0x4d9a -- a 4:3 ratio, the screen's -- renders the scene
 * node into the context the ov002 getter returned, then restores the camera the
 * scene had. The result is always 0.
 */
struct Ov020Entity {
    char pad00[0x12];
    unsigned short hBindFlags12;            /* 0x12 */
    char pad14[8];
    unsigned short aNode1c[1];              /* 0x1c */
    char pad1e[0x106];
    char aCamera124[4];                     /* 0x124 */
};

extern void *Ov002_GetModuleScale(void);
extern int func_ov022_02083f0c(void);
extern void *Ov002_GetWord20(int self);
extern void Camera_CommitMatricesEx(void *camera, int top, int bottom, int left, int right);
extern void Sequence_UpdateTracks(unsigned short *node, void *context);
extern void Scene_DrawNode(unsigned short *node);
extern void Camera_CommitMatrices(void *camera);

int Ov020_DrawEntity(struct Ov020Entity *entity)
{
    void *context;
    void *scene_camera;
    int player;

    context = Ov002_GetModuleScale();
    if ((entity->hBindFlags12 & 4) != 0) {
        player = func_ov022_02083f0c();
        if (player == -1) {
            return 0;
        }

        scene_camera = Ov002_GetWord20(player);
        Camera_CommitMatricesEx(entity->aCamera124, 0x3b33, -0x3b33, -0x4d9a, 0x4d9a);
        Sequence_UpdateTracks(entity->aNode1c, context);
        Scene_DrawNode(entity->aNode1c);
        Camera_CommitMatrices(scene_camera);
    }
    return 0;
}
