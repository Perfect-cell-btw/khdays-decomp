/* Pushes the VRAM state, runs the frame without input and moves to ending the scene for each
 * player. */

extern void EntityMgr_PushVramState(void);
extern void Ov022_SetActorInputEnabled(int arg0);
extern int Ov022_EndSceneForEachPlayer(void);
int func_ov022_02083758(void) {
    EntityMgr_PushVramState();
    Ov022_SetActorInputEnabled(0);
    return (int)&Ov022_EndSceneForEachPlayer;
}
