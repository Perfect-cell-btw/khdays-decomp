/* Ov006_MissionStartTween -- Mission Mode: start tween number `slot` (0..4) on the Mission Mode object.
 * Each tween lives at OBJ+0x9614 + slot*0x1c; `val` is the Q12 target. Returns 0 if the
 * Mission Mode object is gone or the slot is out of range. */
extern void Tween_Configure(int *tween, int a, int b, int target, int mode);
extern void Tween_Start(int tween);
extern int *data_ov006_02056664;

int Ov006_MissionStartTween(int val, unsigned int slot, int mode) {
    if (data_ov006_02056664 == 0) {
        return 0;
    }
    if (slot > 4) {
        return 0;
    }
    Tween_Configure((int *)((char *)data_ov006_02056664 + 0x9614 + slot * 0x1c),
                  0, 0, val << 12, mode);
    Tween_Start((int)((char *)data_ov006_02056664 + 0x9614 + slot * 0x1c));
    return 1;
}
