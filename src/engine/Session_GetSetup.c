/* Returns the session setup block (gSessionSetup: state, player slot count, key, member mask),
 * stored by Session_StoreSetup. */

extern int gSessionSetup;

int Session_GetSetup(void) {
    return (int)&gSessionSetup;
}
