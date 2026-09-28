/*
 * Ov002_ApplyInputEvent - apply a queued input event to an object (ARM).
 *
 * Dispatches on the event type param_2[0]: type 1 records the button code param_2[4] into
 * param_1+0x2c2 and marks the input state (param_1+0x2c1) as 2; type 2 confirms the current menu
 * selection - if the highlighted index (signed halfword at param_1+0x2c4) is valid it runs
 * Ov002_SetKeyNodeVisible on it, then sets the "confirmed" bit at param_1+0x2c3. Other event types are
 * ignored.
 */
extern void Ov002_SetKeyNodeVisible(int a, int b, int c);

void Ov002_ApplyInputEvent(int param_1, unsigned char *param_2)
{
    switch (param_2[0]) {
    case 1:
        *(unsigned char *)(param_1 + 0x2c2) = param_2[4];
        *(unsigned char *)(param_1 + 0x2c1) = 2;
        break;
    case 2:
        {
            short v = *(short *)(param_1 + 0x2c4);
            if (v >= 0) {
                Ov002_SetKeyNodeVisible(v, 1, -1);
            }
            *(unsigned char *)(param_1 + 0x2c3) |= 1;
        }
        break;
    }
}
