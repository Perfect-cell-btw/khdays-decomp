/* Shows or hides the model node when the visibility changes and stores the flag. */

typedef union {
    int word;
    struct {
        signed int flagBit : 1;
    } bits;
} Field40;

typedef struct {
    char pad_000[0x40];
    Field40 field_40;
    char pad_44[0x9c - 0x44];
    int field_9c;
} Ov107Obj;

extern void invokeObjCallbackGuarded(int param_1);
extern int Node_CallHook80(char *p);

void Ov107_AiState_SetVisible(Ov107Obj *self, int flag)
{
    if (self->field_9c == 0) {
        goto done;
    }
    if (flag == 0) {
        goto altPath;
    }
    if (self->field_40.bits.flagBit) {
        goto altPath;
    }
    invokeObjCallbackGuarded(self->field_9c);
    goto done;

altPath:
    if (flag != 0) {
        goto done;
    }
    if (!self->field_40.bits.flagBit) {
        goto done;
    }
    Node_CallHook80((char *)self->field_9c);

done:
    self->field_40.word = (self->field_40.word & ~1) | (flag & 1);
}
