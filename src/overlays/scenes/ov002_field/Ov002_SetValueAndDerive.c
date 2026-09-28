typedef struct {
    char pad00[0x44];
    int value;      /* +0x44 */
    int prev;       /* +0x48 */
    char pad4c[8];
    int derivedA;   /* +0x54 */
    char pad58[4];
    int derivedB;   /* +0x5c */
    int derivedC;   /* +0x60 */
    char pad64[0x18];
    int derivedD;   /* +0x7c */
    char pad80[4];
    int derivedE;   /* +0x84 */
    int derivedF;   /* +0x88 */
} Ov002Value;

typedef struct {
    char pad00[0x20];
    Ov002Value *v;  /* +0x20 */
} Ov002Owner;

extern int Ov002_UpdateCameraDistance(int v);
extern int Ov002_Camera_GetPresetHeight(int v);
extern int Ov002_GetCameraDistance(int v);

/* Takes THREE parameters: the call site in ov022 (Ov022_SetupSessionObject) sets r0,
 * r1 AND r2.  The body never reads the third, which is why a 2-param definition
 * also compiles byte-identically -- a callee's own code can never settle its
 * arity, only its callers can. */
void Ov002_SetValueAndDerive(Ov002Owner *owner, int value, int unused) {
    Ov002Value *c = owner->v;

    c->prev = c->value;
    c->value = value;
    c->derivedA = Ov002_UpdateCameraDistance(value);
    c->derivedB = Ov002_Camera_GetPresetHeight(c->value);
    c->derivedC = Ov002_GetCameraDistance(c->value);
    c->derivedD = Ov002_UpdateCameraDistance(c->value);
    c->derivedE = Ov002_Camera_GetPresetHeight(c->value);
    c->derivedF = Ov002_GetCameraDistance(c->value);
}
