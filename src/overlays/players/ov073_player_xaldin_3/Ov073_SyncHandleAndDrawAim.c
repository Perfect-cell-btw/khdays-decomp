/* Per-frame special-attack update: keeps the ground-follow rumble running only for the local player
 * in the charge states (stopping it otherwise), scrolls the charge widget with the animation frame,
 * draws the animation and finishes the battle-module update. */

extern int Anim_GetFrame(int a, int b);
extern int func_ov022_02083f0c(void);
extern void Ov002_StoreVAndToggleBit25(int a, int b, int c);
extern int Session_GetLocalPlayerIndex(void);
extern int Ov022_FollowGroundRumble(int self);
extern void Ov002_WidgetScrollCommit(int a, int b, int c, int d);
extern void Ov073_UpdateAnimationAndDraw(int self);
extern void func_ov022_020ad588(int self);

void Ov073_SyncHandleAndDrawAim(int self) {
    int *blk = (int *)(self + 0xe4 + 0x2c00);
    int t = Anim_GetFrame(*(int *)(self + 0x20) + 4, 0);
    int st = *(int *)(self + 0x6bc);
    if ((st != 0x31 && st != 0x33) ||
        (st == 0x31 && *(int *)(self + 0x7b0) >= 0x18000)) {
        if (blk[3] == 1) {
            Ov002_StoreVAndToggleBit25(func_ov022_02083f0c(), 0, 0);
            blk[3] = 0;
        }
    } else if (*(unsigned char *)(self + 8) == Session_GetLocalPlayerIndex()) {
        blk[3] = Ov022_FollowGroundRumble(self);
    }
    Ov002_WidgetScrollCommit(self + 0x1a8 + 0xc00, self + 0x2c + 0x2c00,
                        *(short *)(self + 0x2a00 + 0xba), t);
    Ov073_UpdateAnimationAndDraw(self);
    func_ov022_020ad588(self);
}
