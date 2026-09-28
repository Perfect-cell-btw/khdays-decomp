/* Run a node's value through the transform its kind (+4) selects, using the context at +8 of
 * the owner: kind 0 goes to Ov022_RunCommandHandlers, kind 1 to Ov022_RunReachHandlers, and any other
 * kind passes the value through untouched.
 *
 * The nesting has to be inverted -- `if (kind != 0) { if (kind == 1) ... } else { ... }` -- so
 * that the kind-1 arm sits physically first and the kind-0 arm is the one branched to, which is
 * how the original lays them out. Written the natural way round (`if (kind == 0) ... else if`),
 * mwcc emits the two arms in source order and the branches come out inverted; written as a
 * switch it grows an extra compare. */
extern int Ov022_RunReachHandlers(int ctx, int value, int arg);
extern int Ov022_RunCommandHandlers(int ctx, int value, int arg);

int Ov022_TransformNodeValue(int *owner, int *node, int value, int arg) {
    int kind = node[1];
    int ctx = owner[2];
    if (kind != 0) {
        if (kind == 1) value = Ov022_RunReachHandlers(ctx, value, arg);
    } else {
        value = Ov022_RunCommandHandlers(ctx, value, arg);
    }
    return value;
}
